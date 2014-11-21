`alert`
-------

Call the Win32 API from within Cygwin to make an alert box pop up.

I'm not sure whether I want a modal dialogue box or not. What I want is
something I can schedule with `at` like this:

````shell
$ at 20 min alert "Get the cake out of the oven."
````

The options in the Win32 MessageBox function are presently set to
`MB_OK|MB_ICONINFORMATION` but can optionally include:

- `MB_APPLMODAL` (the default)
- `MB_SYSTEMMODAL` (topmost)
- `MB_TASKMODAL` (like Application Modal but works when there's no current
window)

The return code from MessageBox() tells what button the user pressed. There
are other parameters as above to make OK/Cancel boxes, Yes/No boxes, and
others.

Where I learnt this
===================

http://stackoverflow.com/questions/9981499/how-do-i-call-the-win32-api-from-a-cygwin-program

