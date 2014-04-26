#!/bin/sh

#
# remove Scheme comments: semicolon to end of line. Following the usual
# convention, comments are replaced with a single space.
#

if [ $# -eq 0 ]; then
	echo "Usage: $0 file.scm"
	exit 1
fi

sed -e 's/;.*$/ /' $1

