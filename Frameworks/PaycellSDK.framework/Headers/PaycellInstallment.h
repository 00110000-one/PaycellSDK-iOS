//
//  PaycellInstallment.h
//  PaycellSDK
//
//  Created by Batuhan Erdogan on 9/19/16.
//  Copyright © 2016 Tmobtech. All rights reserved.
//

#import <Foundation/Foundation.h>

#define INSTALLMENT_DCB     @"DCB"
#define INSTALLMENT_CARD    @"CREDIT_CARD"

typedef NS_ENUM(NSInteger,  PaycellInstallmentBrand) {
    PaycellInstallmentBrand_UNDEFINED   = 0,
    PaycellInstallmentBrand_BONUS       = 1,
    PaycellInstallmentBrand_WORLD       = 2,
    PaycellInstallmentBrand_CARDFINANS  = 3,
    PaycellInstallmentBrand_AXESS       = 4,
    PaycellInstallmentBrand_ADVANTAGE   = 5,
    PaycellInstallmentBrand_PARAF       = 6,
    PaycellInstallmentBrand_MAXIMUM     = 7,
    PaycellInstallmentBrand_TURKCELL    = 8,
};

@interface PaycellInstallment : NSObject

@property(nonatomic, readonly, strong, nonnull) NSString                    *installmentTotalAmount;
@property(nonatomic, readonly, assign)          int                         installmentCount;
@property(nonatomic, readonly, assign)          PaycellInstallmentBrand     installmentCardBrand;
@property(nonatomic, readonly, strong, nonnull) NSString                    *installmentLineId;
@property(nonatomic, readonly, strong, nonnull) NSString                    *installmentMethodType;


- (nullable instancetype)initWithTotalAmount:(nonnull NSString*)installmentTotalAmount
                            installmentCount:(int)installmentCount
                        installmentCardBrand:(PaycellInstallmentBrand)installmentCardBrand
                           installmentLineId:(nonnull NSString*)installmentLineId
                       installmentMethodType:(nonnull NSString*)installmentMethodType;

+ (nonnull NSString*)getCardBrandString:(PaycellInstallmentBrand)brandEnum;

@end
