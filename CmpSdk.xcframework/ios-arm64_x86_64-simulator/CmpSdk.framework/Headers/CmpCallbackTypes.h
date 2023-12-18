//
//  CmpCallbackTypes.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 14.12.23.
//

#ifndef CmpCallbackTypes_h
#define CmpCallbackTypes_h
typedef void (^CmpCompletionHandler)(void);
typedef void (^CmpImportCompletionHandler)(bool result, NSString *message);
#endif /* CmpCallbackTypes_h */
