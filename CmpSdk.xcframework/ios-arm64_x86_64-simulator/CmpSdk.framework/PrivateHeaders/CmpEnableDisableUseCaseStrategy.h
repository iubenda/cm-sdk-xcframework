//
//  CmpEnableDisableUseCaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import "V2CmpUseCaseProtocol.h"
#import "V2CmpViewController.h"
#import "CmpEnableDisableUseCaseProtocol.h"
#import "CmpEventsProtocol.h"
#import "CmpSdk/CmpService.h"
#import "CmpSdk/CmpCallbackTypes.h"
#import "CmpBaseStrategy.h"
@interface CmpEnableDisableUseCaseStrategy : CmpBaseStrategy <CmpEnableDisableUseCaseProtocol>
- (instancetype)initWithUseCase:(CmpUseCase)useCase
                       purposes:(NSArray *)purposes
                        vendors:(NSArray *)vendors
                   updateVendor:(BOOL)updateVendor
             completionHandler:(CmpCompletionHandler)completionHandler
                  eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end
