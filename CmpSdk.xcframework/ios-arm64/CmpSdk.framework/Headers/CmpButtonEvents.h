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

// Map the integer value to a CmpButtonEvent object using a switch statement
//CmpButtonEvent buttonEvent;
//switch (buttonEventValue) {
//    case 0:
//        buttonEvent = CmpButtonEventUnknown;
//        break;
//    case 1:
//        buttonEvent = CmpButtonEventAcceptAll;
//        break;
//    case 2:
//        buttonEvent = CmpButtonEventRejectAll;
//        break;
//    case 3:
//        buttonEvent = CmpButtonEventSave;
//        break;
//    case 4:
//        buttonEvent = CmpButtonEventClose;
//        break;
//    default:
//        buttonEvent = CmpButtonEventUnknown;
//        break;
//}
