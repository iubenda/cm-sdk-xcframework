//
//  CmpTCFConsentData.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpTCFConsentData_h
#define CmpTCFConsentData_h
@interface CmpTCFConsentData : NSObject

@property (nonatomic, strong) NSString *consentString;
@property (nonatomic, strong) NSNumber *version;
@property (nonatomic, assign) BOOL isCompliant;

@end

#endif /* CmpTCFConsentData_h */
