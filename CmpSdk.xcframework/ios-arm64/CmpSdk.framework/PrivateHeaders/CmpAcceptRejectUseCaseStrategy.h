//
//  AcceptRejectUseCaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import "V2CmpUseCaseProtocol.h"
#import "V2CmpViewController.h"
#import "CmpEventsProtocol.h"
#import "CmpAcceptRejectUseCaseProtocol.h"
#import "CmpSdk/CmpService.h"
#import "CmpSdk/CmpCallbackTypes.h"
#import "CmpBaseStrategy.h"
@interface CmpAcceptRejectUseCaseStrategy : CmpBaseStrategy <CmpAcceptRejectUseCaseProtocol>
- (instancetype)initWithUseCase:(CmpUseCase)useCase completion:(CmpCompletionHandler)handler eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end
