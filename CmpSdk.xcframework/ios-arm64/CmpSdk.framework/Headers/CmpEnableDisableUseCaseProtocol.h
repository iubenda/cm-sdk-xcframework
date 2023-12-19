//
//  CmpEnableDisableUseCaseProtocol.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpEnableDisableUseCaseProtocol_h
#define CmpEnableDisableUseCaseProtocol_h
#import "CmpSdk/CmpUseCase.h"
#import "CmpSdk/CmpCallbackTypes.h"
@protocol CmpEnableDisableUseCaseProtocol <NSObject>

- (instancetype)initWithUseCase:(CmpUseCase)useCase
                       purposes:(NSArray *)purposes
                        vendors:(NSArray *)vendors
                   updateVendor:(BOOL)updateVendor
             completionHandler:(CmpCompletionHandler)completionHandler
                  eventHandler:(id<CmpEventsProtocol>)eventHandler;
@end

#endif /* CmpEnableDisableUseCaseProtocol_h */
