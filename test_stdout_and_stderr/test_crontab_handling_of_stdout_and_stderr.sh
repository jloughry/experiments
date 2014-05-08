#!/bin/sh

home=/Users/andrealoughry
stdout_logfile=$home/results_of_stdout_test.txt
stderr_logfile=$home/results_of_stderr_test.txt

rm -f $logfile
$home/test_stdout_and_stderr.exe >> $stdout_logfile
$home/test_stdout_and_stderr.exe >> $stderr_logfile 2>&1

