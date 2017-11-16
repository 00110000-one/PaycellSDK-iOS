//
//  PaycellPaymentResponse.h
//  PaycellSDK
//
//  Created by Batuhan Erdogan on 11/15/16.
//  Copyright © 2016 Tmobtech. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PaycellPaymentResponse : NSObject

@property (nonatomic, strong) NSString *installmentCount;
@property (nonatomic, strong) NSString *amount;
@property (nonatomic, strong) NSString *hashData;
@property (nonatomic, strong) NSString *paymentReferenceNumber;
@property (nonatomic, strong) NSString *acquirerbankCode;
@property (nonatomic, strong) NSString *approvalCode;
@property (nonatomic, strong) NSString *orderId;
@property (nonatomic, strong) NSString *paymentSecurity;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSString *reconcilationDate;

@end
