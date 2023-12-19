//
//  CmpChangeItemFactory.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 17.12.23.
//

#ifndef CmpChangeItemFactory_h
#define CmpChangeItemFactory_h
#import "CmpChangeItem.h"

@interface CmpChangeItemFactory : NSObject

+ (CmpChangeItem *)createChangeItemFromDictionary:(NSDictionary *)dict;

@end


#endif /* CmpChangeItemFactory_h */
