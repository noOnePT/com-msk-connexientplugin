/********* msk-connexient-plugin.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import "ConnexientKit/ConnexientKit.h"
#import <ConnexientMapKit/ConnexientMapKit.h>
#import <ConnexientAnalyticsKit/ConnexientAnalyticsKit.h>
#import <ConnexientKit/ConnexientKit.h>
#import <ConnexientUI/ConnexientUI.h>


@interface MSKConnexientPlugin : CDVPlugin {
  // Member variables go here.
}

- (void)setEnvironment:(CDVInvokedUrlCommand*)command;
- (void)initAsync:(CDVInvokedUrlCommand*)command;
- (void)showMap:(CDVInvokedUrlCommand*)command;
- (void)openLink:(CDVInvokedUrlCommand*)command;

@end

@implementation MSKConnexientPlugin

- (void)setEnvironment:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* envStr = [command.arguments objectAtIndex:0];
    if ([envStr  isEqual: @"DEV"] || [envStr  isEqual: @"NEWDEV"]){
        [[ CNXCore sharedManager] setCurrentEnvironment:CNXSDKEnvironmentDevelopment];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else if ([envStr isEqual:@"DEV2"]){
        [[ CNXCore sharedManager] setCurrentEnvironment:CNXSDKEnvironmentDevelopment2];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else if ([envStr isEqual:@"PROD"]){
        [[ CNXCore sharedManager] setCurrentEnvironment:CNXSDKEnvironmentProduction];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else if ([envStr isEqual:@"STAGING"] ){
        [[ CNXCore sharedManager] setCurrentEnvironment:CNXSDKEnvironmentStaging];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Please input a valid environment"];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)initAsync:(CDVInvokedUrlCommand*)command
{
    __block CDVPluginResult* pluginResult = nil;
    
    NSString* apiKey = [command.arguments objectAtIndex:0];
    [[CNXCore sharedManager] setupWithAppKey:apiKey inEnvironment:CNXSDKEnvironmentDevelopment];
    
    [[CNXCore sharedManager] setCompletitionBlock:^(NSError *error) {
        if(!error){
            [CNXMapManager prepareMapsForUse];
            //[CNXANAnalytics getStarted];
        } else {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }
    }];
    
    [[NSNotificationCenter defaultCenter] addObserverForName:kMapsReadyForUse object:nil queue:nil usingBlock:^(NSNotification *note) {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        NSLog(@"Maps ready for use!");
    }];
}

- (void)showMap:(CDVInvokedUrlCommand*)command{
    __block CDVPluginResult* pluginResult = nil;
    LoadingViewController *loadingVC = [LoadingViewController new];
    UINavigationController *navC = [[UINavigationController alloc] initWithRootViewController:loadingVC];
    navC.modalPresentationStyle = UIModalPresentationFullScreen;
    [self.viewController presentViewController:navC animated:YES completion:^{
        [loadingVC mapsAreReadyForUse];
        [SDKAPPLinkManager processURL:[NSURL URLWithString:@"medinav://map"]];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }];
}

- (void)openLink:(CDVInvokedUrlCommand*)command{
    __block CDVPluginResult* pluginResult = nil;
    LoadingViewController *loadingVC = [LoadingViewController new];
    NSString* deepLink = [command.arguments objectAtIndex:0];
    UINavigationController *navC = [[UINavigationController alloc] initWithRootViewController:loadingVC];
    navC.modalPresentationStyle = UIModalPresentationFullScreen;
    [self.viewController presentViewController:navC animated:YES completion:^{
        [loadingVC mapsAreReadyForUse];
        [SDKAPPLinkManager processURL:[NSURL URLWithString:deepLink]];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }];
}

@end

/*
NOT IMPLEMENTED AS THEY DO NOT EXIT IN THE SDK
loadMap
loadMapNoId
isMapReady
isMapReadyNoId
isMapDownloading
isMapDownloadingNoId
searchStaff
showDirectory
 */
