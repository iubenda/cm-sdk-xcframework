//
//  V2CmpViewController.h
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.12.23.
//
#ifndef V2CmpViewController_h
#define V2CmpViewController_h
#import <UIKit/UIKit.h>
#import "CmpSdk/V2WebViewManager.h"
#import "CmpUseCase.h"
#import "V2CmpUseCaseProtocol.h"
@interface V2CmpViewController : UIViewController <UIGestureRecognizerDelegate>

@property (nonatomic, strong) V2WebViewManager *webViewManager;
@property (nonatomic, strong) id<V2CmpUseCaseProtocol> strategy;

- (void)closeViewController;

@end
#endif /* V2CmpViewController_h */
