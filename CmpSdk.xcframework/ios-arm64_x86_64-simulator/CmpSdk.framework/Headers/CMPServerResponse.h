//
//  CMPServerResponse.h
//  GDPR
//

#import <Foundation/Foundation.h>

/**
 Object that provides the interface for storing and retrieving GDPR-related information
 */
@interface CMPServerResponse : NSObject

/**
 The Status that is beeing returned from the Server
 */
@property(nonatomic, retain) NSNumber *status;

/**
 The Message that is beeing returned from the Server
 */
@property(nonatomic, retain) NSString *message;

/**
 The Regulation Integer that is beeing returned from the Server
 */
@property(nonatomic, retain) NSNumber *regulation;

/**
 The Url that is beeing returned from the server and that should be called to show the WebView
 */
@property(nonatomic, retain) NSURL *url;

@end
