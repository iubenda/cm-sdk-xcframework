//
//  CmpEventBus.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//

#ifndef CmpEventBus_h
#define CmpEventBus_h
#import "CmpEventType.h"
@interface CmpEventBus : NSObject

+ (instancetype)sharedBus;

- (void)publishEvent:(CmpEventType)eventType withDetails:(NSDictionary *)detailsOrNil;
- (void)subscribeToEventsWithCallback:(void(^)(CmpEventType eventType, NSDictionary *details))callback;
- (NSArray *)eventsForSession:(NSString *)sessionID;
- (NSArray *)eventsForHistory;
- (void)clearEventsForSession:(NSString *)sessionID;

@end
#endif /* CmpEventBus_h */
