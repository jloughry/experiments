`Do Not Shutdown`
-----------------

While this programme is running, the user is prevented from shutting down
or rebooting the system.

The inspiration came from a
[StackExchange article](http://stackoverflow.com/questions/5375709/application-not-preventing-shutdown-on-mac);
here is a slightly modified version of that code:

````
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
````

The code is derived from the
[article](https://developer.apple.com/library/mac/technotes/tn2062/_index.html)
on kiosk mode.

