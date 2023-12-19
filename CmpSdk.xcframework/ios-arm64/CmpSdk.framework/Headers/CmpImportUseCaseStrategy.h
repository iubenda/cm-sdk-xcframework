//
//  ImportUseCaseStrategy.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 12.12.23.
//
#import "V2CmpUseCaseProtocol.h"
#import "V2CmpViewController.h"
#import "CmpImportUseCaseProtocol.h"
#import "CmpEventsProtocol.h"
#import "CmpSdk/CmpCallbackTypes.h"
#import "CmpBaseStrategy.h"
@interface CmpImportUseCaseStrategy : CmpBaseStrategy <CmpImportUseCaseProtocol>

- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler
                      cmpString:(NSString *)cmpString
              completionHandler:(CmpImportCompletionHandler)completionHandler;

@end
