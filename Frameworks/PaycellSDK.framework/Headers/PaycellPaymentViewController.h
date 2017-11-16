//
//  PaycellPaymentViewController.h
//  PaycellSDK
//
//  Created by Batuhan Erdogan on 9/1/16.
//  Copyright © 2016 Tmobtech. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PaycellPayment.h"
#import "PaycellPaymentResponse.h"

typedef NS_ENUM(NSInteger, PaycellErrorCode) {
    PaycellErrorCodeUserCancelled   = 300,
    PaycellErrorCodeException       = 500
};


#pragma mark - Delegates and notifications

@class PaycellPaymentViewController;

@protocol PaycellPaymentDelegate <NSObject>

@required
- (void)paycellPaymentViewController:(nonnull PaycellPaymentViewController *)paymentViewController
                  didCompletePayment:(nonnull PaycellPaymentResponse *)completedPaymentResponse;

- (void)paycellPaymentError:(nonnull PaycellPaymentViewController *)paymentViewController
               andErrorCode:(PaycellErrorCode)paycellErrorCode;

@end

#pragma mark - Interface

@interface PaycellPaymentViewController : UINavigationController

@property(nonatomic, weak, nullable) id<PaycellPaymentDelegate> paycellPaymentDelegate;

- (nullable instancetype)initWithPayment:(nonnull PaycellPayment*)payment
                                delegate:(nonnull id<PaycellPaymentDelegate>)delegate;


@end
