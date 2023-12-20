//
//  CmpImportUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//
#ifndef CmpImportUseCaseProtocol_h
#define CmpImportUseCaseProtocol_h
#import "CmpCallbackTypes.h"
@protocol CmpImportUseCaseProtocol <NSObject>
- (instancetype)initWithUseCase:(CmpUseCase)useCase eventHandler:(id<CmpEventsProtocol>)eventHandler
                      cmpString:(NSString *)cmpString
              completionHandler:(CmpImportCompletionHandler)completionHandler;
@end

#endif /* CmpImportUseCaseProtocol_h */
