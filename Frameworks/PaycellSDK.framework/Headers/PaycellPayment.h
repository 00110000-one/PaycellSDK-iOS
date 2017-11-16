//
//  PaycellPayment.h
//  PaycellSDK
//
//  Created by Batuhan Erdogan on 9/19/16.
//  Copyright © 2016 Tmobtech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaycellInstallment.h"


@interface PaycellPayment : NSObject


@property(nonatomic, readonly, strong, nonnull)  NSString                       *paymentCurrency;
@property(nonatomic, readonly, strong, nonnull)  NSString                       *paymentSecurityOption;
@property(nonatomic, readonly, strong, nonnull)  NSString                       *paymentAmount;
@property(nonatomic, readonly, strong, nonnull)  NSString                       *paymentReferenceNumber;
@property(nonatomic, readonly, strong, nullable) NSArray <PaycellInstallment*>  *paymentInstallmentPlans;
@property(nonatomic, readonly, strong, nonnull)  NSString                       *paymentMerchantHashData;


- (nullable instancetype)initWithAmount:(nonnull NSString*)paymentAmount
                               currency:(nonnull NSString*)paymentCurrency
                         securityOption:(nonnull NSString*)paymentSecurityOption
                        referenceNumber:(nonnull NSString*)paymentReferenceNumber
                       installmentPlans:(nullable NSArray <PaycellInstallment*> *)paymentInstallmentPlans;




@end
