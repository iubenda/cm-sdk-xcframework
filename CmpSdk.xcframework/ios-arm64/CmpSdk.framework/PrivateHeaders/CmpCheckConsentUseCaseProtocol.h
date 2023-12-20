//
//  CmpCheckConsentUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpCheckConsentUseCaseProtocol_h
#define CmpCheckConsentUseCaseProtocol_h

@protocol CmpCheckConsentUseCaseProtocol <NSObject>
- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end


#endif /* CmpCheckConsentUseCaseProtocol_h */
