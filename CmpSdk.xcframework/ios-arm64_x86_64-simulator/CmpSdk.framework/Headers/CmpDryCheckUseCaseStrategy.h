//
//  DryUseCaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import <Foundation/Foundation.h>
#import "CmpSdk/CmpCallbackTypes.h"
#import "CmpSdk/CmpDryCheckUseCaseProtocol.h"
#import "CmpSdk/CmpEventsProtocol.h"
#import "CmpSdk/V2CmpUseCaseProtocol.h"
#import "CmpBaseStrategy.h"
@interface CmpDryCheckUseCaseStrategy : CmpBaseStrategy <CmpDryCheckUseCaseProtocol>
- (instancetype)initWithUseCase:(CmpUseCase)useCase openHandler:(CmpCompletionHandler)openHandler closeHandler:(CmpCompletionHandler)closeHandler eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end
