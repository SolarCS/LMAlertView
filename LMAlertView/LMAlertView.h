//
//  LMAlertView.h
//  LMAlertViewDemo
//
//  Created by Lee McDermott on 11/11/2013.
//  Copyright (c) 2013 Bestir Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LMModalItemTableViewCell.h"

#ifdef USE_PRIVATE_SPRING_ANIMATION_CLASS
#define kSpringAnimationClassName CASpringAnimation

@interface CASpringAnimation : CABasicAnimation
- (float)damping;
- (double)durationForEpsilon:(double)arg1;
- (float)mass;
- (void)setDamping:(float)arg1;
- (void)setMass:(float)arg1;
- (void)setStiffness:(float)arg1;
- (void)setVelocity:(float)arg1;
- (float)stiffness;
- (float)velocity;
@end
#else
#import "RBBSpringAnimation.h"
#define kSpringAnimationClassName RBBSpringAnimation
#endif

@class LMAlertView;

@protocol LMAlertViewDelegate <NSObject>
- (void)alertView:(LMAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex;
- (void)willPresentAlertView:(LMAlertView *)alertView;
- (void)didPresentAlertView:(LMAlertView *)alertView;
- (void)alertView:(LMAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)alertView:(LMAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex;
@end

@interface LMAlertView : UIView <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic, strong, readonly) UIView *contentView;
@property (nonatomic) BOOL keepTopAlignment;
@property (weak) id<LMAlertViewDelegate> delegate;

@property(nonatomic) NSInteger cancelButtonIndex;
@property(nonatomic, readonly) NSInteger firstOtherButtonIndex;
@property(nonatomic, copy) NSString *message;
@property(nonatomic, readonly) NSInteger numberOfButtons;
@property(nonatomic, copy) NSString *title;
@property(nonatomic, readonly, getter=isVisible) BOOL visible;
@property(nonatomic) BOOL buttonsShouldStack;
@property(nonatomic) BOOL autoRotate;

- (id)initWithSize:(CGSize)size;
- (id)initWithViewController:(UIViewController *)viewController;
- (id)initWithTitle:(NSString *)title message:(NSString *)message delegate:(id)delegate cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;

- (void)setSize:(CGSize)size animated:(BOOL)animated;
- (void)setSize:(CGSize)size;
- (CGSize)size;

- (void)show;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;
- (NSInteger)addButtonWithTitle:(NSString *)title;
- (NSString *)buttonTitleAtIndex:(NSInteger)buttonIndex;

- (LMModalItemTableViewCell *)buttonCellForIndex:(NSInteger)buttonIndex;

@end
