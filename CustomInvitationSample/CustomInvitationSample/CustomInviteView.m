//
//  CustomInviteView.m
//  CustomInvitationSample
//
//  Created by Wayne Burkett on 5/5/16.
//  Copyright © 2016 ForeSee. All rights reserved.
//

#import "CustomInviteView.h"
#import "CustomInviteViewBox.h"

typedef enum StyleTypes : NSUInteger {
    CONTENT_PADDING = 0,
    FRAME_WIDTH
} StyleTypes;

@interface CustomInviteView ()

@property (nonatomic, getter=isShowing) BOOL showing;

@end

@implementation CustomInviteView

#pragma mark - Init

- (instancetype)init {
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    self = [self initWithFrame:window.frame];
    if (self) {
        [self setup];
        [self createSubviews];
    }
    return self;
}

- (void)setup {
    self.backgroundColor = [UIColor colorWithWhite:0 alpha:0];
    self.showing = NO;
}

- (void)layoutSubviews {
    [self layoutContainers];
    [self layoutText];
    [self layoutButtons];
}

#pragma mark - View creation

- (void)createSubviews {
    
    // You can create your custom view in Interface Builder or in code. This example uses code.
    // All subviews are created and added here.
    
    self.inviteView = [[CustomInviteViewBox alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    
    [self createHeader];
    [self createLogo];
    [self createHeaderLabel];
    [self createBodyLabel];
    [self createSubmitButton];
    [self createCancelButton];
    [self addSubview:self.inviteView];
}

- (void)createHeader {
    UIImage *img = [UIImage imageNamed:@"header2.png"];
    self.headerImageView = [[UIImageView alloc] initWithImage:img];
    [self.inviteView addSubview:self.headerImageView];
}

- (void)createLogo {
    UIImage *img = [UIImage imageNamed:@"ForeSee_logo_RGB.png"];
    self.logoImageView = [[UIImageView alloc] initWithFrame:CGRectMake(15, 15, 134, 60)];
    self.logoImageView.image = img;
    [self.inviteView addSubview:self.logoImageView];
}

- (void)createHeaderLabel {
    self.headerLabel = [[UILabel alloc] init];
    self.headerLabel.numberOfLines = 0;
    self.headerLabel.backgroundColor = [UIColor clearColor];
    self.headerLabel.text = @"We would love your feedback!";
    self.headerLabel.font = [self headerFont];
    self.headerLabel.textColor = [UIColor blackColor];
    [self.inviteView addSubview:self.headerLabel];
}

- (void)createBodyLabel {
    self.bodyLabel = [[UILabel alloc] init];
    self.bodyLabel.numberOfLines = 0;
    self.bodyLabel.backgroundColor = [UIColor clearColor];
    self.bodyLabel.text = @"You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.";
    self.bodyLabel.textAlignment = NSTextAlignmentCenter;
    self.bodyLabel.font = [self bodyFont];
    self.bodyLabel.textColor = [UIColor colorWithWhite:0.35 alpha:1];
    [self.inviteView addSubview:self.bodyLabel];
}

- (void)createSubmitButton {
    self.submitButton = [[UIButton alloc] init];
    self.submitButton.backgroundColor = [UIColor colorWithRed:0.45 green:0.29 blue:0.79 alpha:1.0];
    self.submitButton.layer.cornerRadius = 5;
    self.submitButton.clipsToBounds = YES;
    self.submitButton.titleLabel.font = [self submitButtonFont];
    self.submitButton.titleLabel.textAlignment = NSTextAlignmentCenter;
    [self.submitButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.submitButton setTitle:@"I'd love to help!" forState:UIControlStateNormal];
    [self.submitButton addTarget:self action:@selector(handleSubmitClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.inviteView addSubview:self.submitButton];
}

- (void)createCancelButton {
    self.cancelButton = [[UIButton alloc] init];
    self.cancelButton.backgroundColor = [UIColor clearColor];
    self.cancelButton.clipsToBounds = YES;
    self.cancelButton.titleLabel.font = [self cancelButtonFont];
    self.cancelButton.titleLabel.textAlignment = NSTextAlignmentCenter;
    [self.cancelButton setTitleColor:[UIColor darkGrayColor] forState:UIControlStateNormal];
    [self.cancelButton setTitle:@"No thanks" forState:UIControlStateNormal];
    [self.cancelButton addTarget:self action:@selector(handleCancelClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.inviteView addSubview:self.cancelButton];
}

#pragma mark - Fonts

- (UIFont *)headerFont {
    return [UIFont fontWithName:@"Helvetica-Bold" size:15];
}

- (UIFont *)bodyFont {
    return [UIFont fontWithName:@"Helvetica" size:13];
}

- (UIFont *)submitButtonFont {
    return [UIFont fontWithName:@"Helvetica-Bold" size:11];
}

- (UIFont *)cancelButtonFont {
    return [UIFont fontWithName:@"Helvetica" size:9];
}

#pragma mark - View layout

- (void)layoutContainers {
    CGFloat headerImageHeight = (547.0 / 1600.0) * self.inviteView.frame.size.width;
    self.headerImageView.frame = CGRectMake(0, 0, self.inviteView.frame.size.width, headerImageHeight);
    UIBezierPath *maskPath;
    maskPath = [UIBezierPath bezierPathWithRoundedRect:self.headerImageView.bounds
                                     byRoundingCorners:(UIRectCornerTopLeft|UIRectCornerTopRight)
                                           cornerRadii:CGSizeMake(5, 5)];
    
    CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
    maskLayer.frame = self.bounds;
    maskLayer.path = maskPath.CGPath;
    self.headerImageView.layer.mask = maskLayer;
}

- (void)layoutText {
    CGSize headerLabelSize = [self sizeForString:self.headerLabel.text
                                        withFont:self.headerLabel.font
                                         andSize:CGSizeMake(self.inviteView.frame.size.width, 1000)];

    self.headerLabel.frame = CGRectMake(self.headerLabel.frame.origin.x,
                                        self.headerImageView.frame.size.height + 10,
                                        headerLabelSize.width,
                                        headerLabelSize.height);
    self.headerLabel.center = CGPointMake(self.headerImageView.center.x, self.headerLabel.center.y);

    
    CGSize bodyLabelSize = [self sizeForString:self.bodyLabel.text
                                      withFont:self.bodyLabel.font
                                       andSize:CGSizeMake(self.inviteView.frame.size.width - 20, 1000)];
    self.bodyLabel.frame = CGRectMake(0,
                                      self.headerLabel.frame.origin.y + self.headerLabel.frame.size.height + 10,
                                      bodyLabelSize.width,
                                      bodyLabelSize.height);
    self.bodyLabel.center = CGPointMake(self.headerImageView.center.x, self.bodyLabel.center.y);

}

- (void)layoutButtons {
    self.submitButton.frame = CGRectMake(0,
                                         self.bodyLabel.frame.origin.y + self.bodyLabel.frame.size.height + 10,
                                         self.headerImageView.frame.size.width / 2.0,
                                         30);
    self.submitButton.center = CGPointMake(self.headerImageView.center.x, self.submitButton.center.y);
    
    self.cancelButton.frame = CGRectMake(0,
                                         self.submitButton.frame.origin.y + self.submitButton.frame.size.height + 5,
                                         self.headerImageView.frame.size.width / 2.0,
                                         10);
    self.cancelButton.center = CGPointMake(self.headerImageView.center.x, self.cancelButton.center.y);
}

# pragma mark - Button Click Handlers

- (void)handleSubmitClick:(id)sender {
    [self.delegate didAcceptInviteView:self];
}

- (void)handleCancelClick:(id)sender {
    [self.delegate didCancelInviteView:self];
}

#pragma mark - Helpers

- (CGSize)sizeForString:(NSString *)string withFont:(UIFont *)font andSize:(CGSize)size {
    CGRect labelRect = [string boundingRectWithSize:size
                                            options:NSStringDrawingUsesLineFragmentOrigin
                                         attributes:@{NSFontAttributeName : font}
                                            context:nil];
    return CGSizeMake(ceil(labelRect.size.width),
                      ceil(labelRect.size.height));
}

# pragma mark - Public methods

- (void)showAndOnComplete:(void (^)(void))completion {
    
    // Fades in the primary view (inviteView)
    
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    [window addSubview:self];
    
    self.frame = self.superview.bounds;
    self.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    
    [UIView animateWithDuration:0.2
                          delay:0.5
                        options:UIViewAnimationOptionCurveEaseIn
                     animations:^{
                         self.backgroundColor = [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.6];
                         self.inviteView.alpha = 1.0;
                         self.showing = YES;
                     }
                     completion:^(BOOL finished) {
                         if (completion) {
                             completion();
                         }
                     }];
}

- (void)hideWithAnimation:(BOOL)animate completion:(void (^)(void))completion {
    
    // Fades out the primary view (inviteView)
    
    if (animate) {
        [UIView animateWithDuration:0.3
                         animations:^{
                             self.alpha = 0;
                         }
                         completion:^(BOOL finished) {
                             [self removeFromSuperview];
                             if (completion) {
                                 completion();
                             }
                             self.showing = NO;
                         }];
    } else {
        self.alpha = 0;
        if (completion) {
            completion();
        }
        self.showing = NO;
    }
}

@end
