// 
// main.m
//  

#import <Cocoa/Cocoa.h>

OSErr QuitAppleEventHandler(const AppleEvent * appleEvt, AppleEvent * reply, UInt32 refcon) {
    // userCanceledErr to cancel logout
    return userCanceledErr;
}

int main(int argc, char ** argv) {
    OSErr err;

    // Install quit event handler.

    err = AEInstallEventHandler(kCoreEventClass,
                                kAEQuitApplication,
                                NewAEEventHandlerUPP((AEEventHandlerProcPtr)QuitAppleEventHandler),
                                0,
                                false);

    if (err != noErr)
        ExitToShell();

    return NSApplicationMain(argc, (const char **) argv);
}

