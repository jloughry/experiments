#!/bin/sh

test_case_number=TC-2
command_line="skeleton 10"

echo -n "$test_case_number: "

./$command_line > $test_case_number.stdout 2> $test_case_number.stderr

if [ `diff -q $test_case_number.stdout $test_case_number.stdout_expected_result` ]; then
	echo -n "FAIL "
else
	echo -n "OK "
fi

if [ `diff -q $test_case_number.stderr $test_case_number.stderr_expected_result` ]; then
	echo "FAIL"
else
	echo "OK"
fi

