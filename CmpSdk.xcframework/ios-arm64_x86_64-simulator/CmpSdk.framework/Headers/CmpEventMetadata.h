//
//  CmpEventMetadata.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpEventMetadata_h
#define CmpEventMetadata_h
#import <Foundation/Foundation.h>
@interface CmpEventMetadata : NSObject <NSCoding>

@property (nonatomic, assign) NSUInteger id;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, assign) NSInteger consentUpdateCount;
@property (nonatomic, strong) NSString *operationType;
@property (nonatomic, strong) NSArray *history;
@end

#endif /* CmpEventMetadata_h */
