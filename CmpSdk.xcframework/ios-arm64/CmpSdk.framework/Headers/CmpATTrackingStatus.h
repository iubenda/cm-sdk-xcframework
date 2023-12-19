//
//  CmpATTrackingStatus.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpATTStatus_h
#define CmpATTStatus_h

typedef NS_ENUM(NSUInteger, CmpATTrackingStatus) {
    CmpATTrackingNotDetermined = 0, // No information available
    CmpATTrackingAuthorized = 1,    // Authorized
    CmpATTrackingDenied = 2  // Restricted/Denied
};

#endif /* CmpATTStatus_h */

