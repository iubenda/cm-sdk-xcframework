//
//  CmpAcceptRejectUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpAcceptRejectUseCaseProtocol_h
#define CmpAcceptRejectUseCaseProtocol_h
#import "CmpCallbackTypes.h"
#import "CmpSdk/CmpUseCase.h"
@protocol CmpAcceptRejectUseCaseProtocol <NSObject>
- (instancetype)initWithUseCase:(CmpUseCase)useCase completion:(CmpCompletionHandler)handler eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end

#endif /* CmpAcceptRejectUseCaseProtocol_h */
