//
//  CNXRoutePreviewView.h
//  Stanford
//
//  Created by Fabian Fermin Guerra Soto on 11/19/14.
//  Copyright (c) 2014 Connexient. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CNXMapManager.h"


/**
 *  @brief UIView class which represents route segment display. Can be used with  CustomInstructionView.xib file in sample project.
 */
@interface CNXRoutePreviewView : UIView

/**
 *  CNXMapManager instance
 */
@property (weak, nonatomic) CNXMapManager *mapManager;

/**
 *  Title of the route instruction
 */
@property (weak, nonatomic) NSString *routeTitle;

/**
 *  Previous button outlet
 */
@property (weak, nonatomic) IBOutlet UIButton *previousButton;

/**
 *  Next button outlet
 */
@property (weak, nonatomic) IBOutlet UIButton *nextButton;

/**
 *  Segment icon image view
 */
@property (weak, nonatomic) IBOutlet UIImageView *segmentIconImage;

/**
 *  Segment title label
 */
@property (weak, nonatomic) IBOutlet UILabel *segmentTitle;

/**
 *  Segnem label 2
 */
@property (weak, nonatomic) IBOutlet UILabel *segmentLabel;

/**
 *  Segment time label
 */
@property (weak, nonatomic) IBOutlet UILabel *segmentTimeLabel;

/**
 *  Segment view
 */
@property (weak, nonatomic) IBOutlet UIView *segmentView;


/**
 *  Initializer
 *
 *  @param frame      Frame of the instruction view on UIViewController root view
 *  @param mapManager CNXMapManager instance
 *
 *  @return CNXRoutePreviewView
 */
- (instancetype)initWithFrame:(CGRect)frame andMapManager:(CNXMapManager *)mapManager;

/**
 *  Action for previous button
 *
 *  @param sender UIButton
 */
- (IBAction)previousHandler:(id)sender;

/**
 *  Action for next button
 *
 *  @param sender UIButton
 */
- (IBAction)nextHandler:(id)sender;

/**
 *  Go to route segment
 *
 *  @param segmentIndex number of route segment
 *  @param animated     is change animated?
 */
- (void)handleRouteSegments:(int)segmentIndex isAnimated:(BOOL)animated;

/**
 *  Go to next segment
 *
 *  @param animated is change animated?
 */
- (void)nextHandlerAnimated:(BOOL)animated;

/**
 *  Go to previous segment
 *
 *  @param animated is change animated?
 */
- (void)previousHandlerAnimated:(BOOL)animated;

/**
 *  Number of total segments
 *
 *  @return integer of segments
 */
-(int)getTotalNumberOfSegments;

/**
 *  Get index for next segment
 *
 *  @return int of segment
 */
-(int)getIndexForNextSegment;

/**
 *  Get index for previous segment
 *
 *  @return int od segment
 */
-(int)getIndexForPreviousSegment;

@end
