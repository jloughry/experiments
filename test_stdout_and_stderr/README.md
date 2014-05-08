`test_stdout_and_stderr`
========================

A small utility programme that outputs a message on stdout and another
on stderr so I can see what goes where.

Background of the Problem
-------------------------

I had a problem with `rsync` in a shell script that was being called by
`cron` on Mac OS X. The `rsync` programme was failing and, when run
manually as *root* it would show an error message, but the output
captured by the shell script run from `crontab` didn't. I began to wonder
if the `2&>1` at the end of the `rsync` command line in the shell script
was not properly redirecting stderr to stdout.

Procedure
---------

Compile the C programme shown below and call the executable from a shell
script via `cron` like this:

````
#!/bin/sh

home=/Users/andrealoughry
stdout_logfile=$home/results_of_stdout_test.txt
stderr_logfile=$home/results_of_stderr_test.txt

rm -f $logfile
$home/test_stdout_and_stderr.exe >> $stdout_logfile
$home/test_stdout_and_stderr.exe >> $stderr_logfile 2>&1

````

The shell script calls the executable in two different ways so as to tell
unambigously whether `stderr` output is getting recorded or not.

Source Code
-----------

#### *test_stdout_and_stderr.c*

````
#include "test_stdout_and_stderr.h"

int main(void) {
	fprintf(stdout, "Firstly, this goes to stdout.\n");
	fprintf(stderr, "Secondly, this goes to stderr.\n");
	return EXIT_SUCCESS;
}

````

#### *test_stdout_and_stderr.h*

````
#include <stdio.h>
#include <stdlib.h>

````

