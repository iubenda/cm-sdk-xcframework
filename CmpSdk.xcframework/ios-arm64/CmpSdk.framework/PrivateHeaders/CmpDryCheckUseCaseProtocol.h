//
//  CmpDryCheckUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpCheckUseCaseProtocol_h
#define CmpCheckUseCaseProtocol_h
#import "CmpSdk/CmpCallbackTypes.h"
#import "CmpSdk/CmpEventsProtocol.h"
#import "CmpSdk/CmpUseCase.h"
@protocol CmpDryCheckUseCaseProtocol <NSObject>
- (instancetype)initWithUseCase:(CmpUseCase)useCase openHandler:(CmpCompletionHandler)openHandler closeHandler:(CmpCompletionHandler)closeHandler eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end

#endif /* CmpCheckUseCaseProtocol_h */
