//
//  CustomInvitation.m
//  iPadExampleWithCustomInvitation
//
//  Copyright 2011 ForeSee Results. All rights reserved.
//

#import "CustomInvitation.h"
#import "CustomInvitationDelegate.h"

@implementation CustomInvitation

@synthesize delegate = delegate_;

- (void)dealloc {
  [[NSNotificationCenter defaultCenter] removeObserver:self 
                                                  name:UIDeviceOrientationDidChangeNotification 
                                                object:nil];
  [super dealloc];
}

- (id)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    self.backgroundColor = [UIColor clearColor];
    self.opaque = NO;
    self.alpha = 0;
    
    UIImage *inviteBackgroundGraphic = [UIImage imageNamed:@"InviteBack"];
    UIImageView *backgroundImageView = [[[UIImageView alloc] initWithImage:inviteBackgroundGraphic] autorelease];
    backgroundImageView.frame = CGRectMake(0, 0, self.frame.size.width, inviteBackgroundGraphic.size.height);
    backgroundImageView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [self addSubview:backgroundImageView];

    // Load the logo
    UIImage *foreseeLogo = [UIImage imageNamed:@"foreseeLogo"];
    CGSize logoSize = CGSizeMake(foreseeLogo.size.width*0.45f, foreseeLogo.size.height*0.45f);
    UIImageView *fsLogoView = [[[UIImageView alloc] initWithImage:foreseeLogo] autorelease];
    fsLogoView.frame = CGRectMake(frame.size.width-logoSize.width-20, 10, logoSize.width, logoSize.height);
    fsLogoView.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self addSubview:fsLogoView];
    
    // Add the label
    NSString *labelText = @"Help us improve our app!";
    CGSize labelSize = [labelText sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:25.0f]}];
    UILabel *inviteLabel = [[[UILabel alloc] initWithFrame:CGRectMake(30, 0, labelSize.width, self.frame.size.height)] autorelease];
    
    inviteLabel.backgroundColor = [UIColor clearColor];
    inviteLabel.font = [UIFont systemFontOfSize:25.0f];
    inviteLabel.textAlignment = NSTextAlignmentLeft;
    inviteLabel.numberOfLines = 1;
    inviteLabel.text = labelText;
    [self addSubview:inviteLabel];
    
    // Add the accept button
    UIButton *okButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage* greenButtonImg = [UIImage imageNamed:@"greenButton.png"];
    [okButton setFrame:CGRectMake(340, 20, greenButtonImg.size.width/1.5, greenButtonImg.size.height/1.5)];
    [okButton setBackgroundImage:greenButtonImg forState:UIControlStateNormal];
    [okButton setTitle:@"OK!" forState:UIControlStateNormal];
    [okButton addTarget:self action:@selector(handleOkClick:) forControlEvents:UIControlEventTouchUpInside];
    okButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self addSubview:okButton];
    
    // Add the reject button
    UIButton *noButton = [UIButton buttonWithType:UIButtonTypeCustom];
    UIImage* redButtonImg = [UIImage imageNamed:@"redButton.png"];
    [noButton setFrame:CGRectMake(465, 20, redButtonImg.size.width/1.5, redButtonImg.size.height/1.5)];
    [noButton setBackgroundImage:redButtonImg forState:UIControlStateNormal];
    [noButton setTitle:@"No" forState:UIControlStateNormal];
    [noButton addTarget:self action:@selector(handleCancelClick:) forControlEvents:UIControlEventTouchUpInside];
    noButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    [self addSubview:noButton];
    
    UIWindow *window = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
    
    self.layer.shadowPath = [UIBezierPath bezierPathWithRect:CGRectMake(0, 0, window.frame.size.height, self.bounds.size.height)].CGPath;
    self.layer.shadowOffset = CGSizeMake(0, 4);
    self.layer.shadowOpacity = 0.4;
    self.layer.masksToBounds = NO;
    
    [[NSNotificationCenter defaultCenter] addObserver:self 
                                             selector:@selector(handleRotation:) 
                                                 name:UIDeviceOrientationDidChangeNotification 
                                               object:nil];
  }
  return self;
}

# pragma mark - Invite display

// Show the invitation. Do whatever animation is necessary here. You do not need to add the invitation to the window.
- (void) show {
  UIWindow *window = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
  [window addSubview:self];
  
  [UIView animateWithDuration:1.5 
                   animations:^{
                     self.alpha = 1;
                   }
   ];
}

/**
 Remove the invitation, with animation if desired.
 */
- (void)hideWithAnimation:(BOOL)animate completion:(void (^)())completion {
  if (animate) {
    [UIView animateWithDuration:0.5 
                     animations:^{
                       self.alpha = 0;
                     } 
                     completion:^(BOOL finished) {
                       [self removeFromSuperview];
                       completion();
                     }
     ];
  }
  else {
    [self removeFromSuperview];
    completion();
  }
}

# pragma mark - Rotation

- (void)handleRotation:(id)sender {
  [self rotateWithAnimation:YES];
}

- (void)rotateWithAnimation:(BOOL)animate {
  UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];
  if (orientation == UIDeviceOrientationUnknown) {
    orientation = UIDeviceOrientationPortrait;
  }

  UIWindow *window = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
  
  float rotation = 0;
  CGPoint center = CGPointZero;
  CGSize newSize = CGSizeZero;
  switch (orientation) {
		case UIDeviceOrientationLandscapeRight:
			rotation = -M_PI / 2.0f;
      center = CGPointMake(self.frame.size.height / 2 + 63, window.frame.size.height / 2);
      newSize.width = window.frame.size.height;
      newSize.height = 80;
			break;
		case UIDeviceOrientationLandscapeLeft:
      center = CGPointMake(window.frame.size.width - self.frame.size.height / 2 - 63, window.frame.size.height / 2);
			rotation = M_PI / 2.0f;
      newSize.width = window.frame.size.height;
      newSize.height = 80;
			break;
		case UIDeviceOrientationPortrait:
      center = CGPointMake(window.frame.size.width / 2, 63 + 40);
			rotation = 0;
      newSize.width = window.frame.size.width;
      newSize.height = 80;
			break;
		case UIDeviceOrientationPortraitUpsideDown:
      center = CGPointMake(window.frame.size.width / 2, window.frame.size.height - 40 - 63);
      newSize.width = window.frame.size.width;
      newSize.height = 80;
			rotation = M_PI;
			break;
		default:
			return;
	}

  if (animate) {
    [UIView animateWithDuration:0.4 
                     animations:^{
                       self.center = center;
                       CGRect newBounds = CGRectMake(0, 0, newSize.width, newSize.height);
                       self.bounds = newBounds;
                       self.transform = CGAffineTransformMakeRotation(rotation);
                     }
     ];
  }
  else {
    self.center = center;
    CGRect newBounds = CGRectMake(0, 0, newSize.width, newSize.height);
    self.bounds = newBounds;
    self.transform = CGAffineTransformMakeRotation(rotation);
  }
}


# pragma mark - Invite button actions

- (void)handleOkClick:(id)sender {
	[self.delegate inviteViewClickedOKButton:self];
}

- (void)handleCancelClick:(id)sender {
	[self.delegate inviteViewClickedCancelButton:self];
}

@end
