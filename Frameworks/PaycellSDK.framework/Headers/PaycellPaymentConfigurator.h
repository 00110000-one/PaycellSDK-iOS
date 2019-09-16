//
//  PaycellPaymentConfigurator.h
//  PaycellSDK
//
//  Created by Batuhan Erdogan on 8/24/16.
//  Copyright © 2016 Tmobtech. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, PaycellEnvironment) {
    PaycellEnvironmentDemo  = 1,
    PaycellEnvironmentTest  = 2,
    PaycellEnvironmentLive  = 3
};


@class UIImage;

@interface PaycellPaymentConfigurator : NSObject

@property(nonatomic, readonly, strong, nonnull)  NSString           *merchantCode;
@property(nonatomic, readonly, strong, nonnull)  NSString           *terminalCode;
@property(nonatomic, readonly, strong, nonnull)  NSString           *secureCode;
@property(nonatomic, readonly, strong, nonnull)  NSString           *language;
@property(nonatomic, readonly, strong, nonnull)  NSString           *hostAccount;
@property(nonatomic, readonly, strong, nonnull)  UIImage            *merchantLogo;
@property(nonatomic, readonly, assign         )  PaycellEnvironment environment;

+ (nonnull PaycellPaymentConfigurator*)sharedConfigurator;

- (void)setMerchantCode:(nonnull NSString*)merchantCode
		andTerminalCode:(nonnull NSString*)terminalCode
		  andSecureCode:(nonnull NSString*)secureCode
            andLanguage:(nonnull NSString*)language
         andHostAccount:(nonnull NSString*)hostAccount
        andMerchantLogo:(nullable UIImage*)merchantLogo
         andEnvironment:(PaycellEnvironment)envoirement;

+ (nonnull NSString *)libraryVersion;

@end
