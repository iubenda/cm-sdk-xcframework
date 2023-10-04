//
//  CmpButtonEvent.m
//  CmpSdk
//
//  Created by Skander Ben Abdelmalak on 16.03.23.
//
#ifndef CmpButtonEvents_h
#define CmpButtonEvents_h
typedef NS_ENUM(NSInteger, CmpButtonEvent) {
    CmpButtonEventUnknown = 0,
    CmpButtonEventAcceptAll = 1,
    CmpButtonEventRejectAll = 2,
    CmpButtonEventSave = 3,
    CmpButtonEventClose = 4
};

#endif /* CmpButtonEvents_h */
