//
//  SDKAPPMainSlideView.h
//  com.connexient.SDKAPP
//
//  Created by Curcio Jamunda Sobrinho on 05/09/17.
//  Copyright © 2017 CNX. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SDKAPPMainSliveViewDelegate <NSObject>
@optional
-(void) didSlideToPercentage:(int) percentage controller:(id) controller;
-(void) slideToY:(int)y;
-(void) didTapMainSlideGestureView:(UITapGestureRecognizer *) tap controller:(id) controller;
-(void) didTapSearchOnSlide:(UITextField *) searchField controller:(id) controller;
@end

@interface SDKAPPMainSlideView : UIView <UITextFieldDelegate>

// initially they are the same sizes and starting points
@property (nonatomic) UIView *dimmedView;
// it will be null if showSearchOnly is set to YES
// this is where ALL views should be added to
@property (nonatomic) UIView *contentView;
// it will be null if showSearchOnly is set to NO
@property (nonatomic) UITextField *textField;
//from ini to 30 points - this one slides the whole
@property (nonatomic) UIView *gestureView;
@property int sliderIsAtPercent;
@property (nonatomic) BOOL showSearchOnly;
@property (nonatomic) BOOL canSlideDownToEnd;
@property (nonatomic) BOOL canManuallySlide;
@property (weak, nonatomic) id <SDKAPPMainSliveViewDelegate> delegate;

-(void) slideToPercentage:(int) percentage completionBlock:(void(^)(void)) block;

// prefered init
-(instancetype) initWithDelegate:(id <SDKAPPMainSliveViewDelegate>) delegate atPercentage:(int)percentage andSearchOnly:(BOOL) showSearchOnly;

-(instancetype) initWithDelegate:(id <SDKAPPMainSliveViewDelegate>) delegate
                    atPercentage:(int)percentage
                        andFrame:(CGRect)frame;

@end
