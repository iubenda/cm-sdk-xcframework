//
//  CmpErrorTypes.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 22.02.23.
//

#ifndef CmpErrorTypes_h
#define CmpErrorTypes_h

typedef NS_ENUM(NSUInteger, CmpErrorType) {
    CmpNetworkError = 100,
    CmpTimeoutError = 101,
    CmpConsentDataReadWriteError = 102,
    CmpUnknownError = 999
};

#endif /* CmpErrorTypes_h */
