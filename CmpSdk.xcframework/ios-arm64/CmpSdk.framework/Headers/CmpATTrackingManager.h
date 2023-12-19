//
//  CmpATTrackingManager.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 15.12.23.
//

#ifndef CmpATTrackingManager_h
#define CmpATTrackingManager_h
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <Foundation/Foundation.h>
#import <CmpSdk/CmpEventListenerTypes.h>

API_AVAILABLE(ios(14))
@interface CmpATTrackingManager : NSObject

@property (nonatomic, copy) CmpATTrackingStatusChangedListener statusChangeCallback;

+ (instancetype)sharedManager;
- (void)requestATTPermissionWithCompletion:(void (^)(ATTrackingManagerAuthorizationStatus status))completion API_AVAILABLE(ios(14));
- (ATTrackingManagerAuthorizationStatus)getStoredATTStatus API_AVAILABLE(ios(14));
- (NSDate *)getLastUpdatedTimestamp;
- (NSDictionary *)checkATTStatusChange;
@end

#endif /* CmpATTrackingManager_h */
