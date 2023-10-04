//
//  Metadata.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 23.02.23.
//

#ifndef Metadata_h
#define Metadata_h

@interface Metadata : NSObject <NSSecureCoding>

@property(nonatomic, copy) NSString *name;
@property(nonatomic, strong) id value;
@property(nonatomic, copy) NSString *type;

@end

#endif /* Metadata_h */
