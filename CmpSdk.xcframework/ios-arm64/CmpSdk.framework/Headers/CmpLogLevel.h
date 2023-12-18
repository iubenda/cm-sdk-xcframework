//
//  CmpLogLevel.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 15.12.23.
//

#ifndef CmpLogLevel_h
#define CmpLogLevel_h

typedef NS_ENUM(NSInteger, CmpLogLevel) {
    CmpLogLevelVerbose = 4,
    CmpLogLevelDebug = 3,
    CmpLogLevelInfo = 2,
    CmpLogLevelWarning = 1,
    CmpLogLevelError = 0
};

#endif /* CmpLogLevel_h */
