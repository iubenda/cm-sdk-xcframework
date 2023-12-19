//
//  NormalUseCaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import "CmpBaseStrategy.h"
#import "CmpEventsProtocol.h"
#import "V2CmpUseCaseProtocol.h"
#import "V2CmpViewController.h"
#import "CmpSdk/CmpService.h"
#import "CmpSdk/CmpCheckConsentUseCaseProtocol.h"
@interface CmpCheckConsentUseCaseStrategy : CmpBaseStrategy <CmpCheckConsentUseCaseProtocol>

- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler;

@end
