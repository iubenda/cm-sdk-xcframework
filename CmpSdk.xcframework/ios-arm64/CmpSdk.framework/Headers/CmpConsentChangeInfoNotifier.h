//
//  CmpConsentChangeInfoNotifier.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpConsentChangeInfoNotifier_h
#define CmpConsentChangeInfoNotifier_h

#import "CmpConsentDTO.h"
#import "CmpSdk/CmpConsentChangeInfo.h"
@interface CmpConsentChangeInfoNotifier : NSObject

@property (nonatomic, strong) CmpConsentChangeInfo *cmpConsentChangeInfo;

- (instancetype)initWithOldConsent:(CmpConsentDTO *)oldConsent newConsent:(CmpConsentDTO *)newConsent;

- (void)postNotificationsIfNeeded;
@end

#endif /* CmpConsentChangeInfo_h */
