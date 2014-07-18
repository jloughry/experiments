#!/bin/bash

set -euo pipefail
IFS=$'\n\t'

if [ $# -ne 2 ]; then
	echo "Usage: $0 pattern target"
	exit 1
fi

pattern=$1
target=$2

# The "strange_alphabet" unifies values commonly confused, e.g., "1" and "I".

regular_alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
strange_alphabet="ABCOEFGHIIKLMNOPORSTVVVXY2OI234S6789"

pattern_transformed=$(echo $pattern \
	| tr -dc "[:alnum:]" \
	| tr "[:lower:]" "[:upper:]" \
	| tr $regular_alphabet $strange_alphabet)

target_transformed=$(echo $target \
	| tr -dc "[:alnum:]" \
	| tr "[:lower:]" "[:upper:]" \
	| tr $regular_alphabet $strange_alphabet)

if [ "$pattern_transformed" == "$target_transformed" ]; then
	echo "Match!"
else
	echo "no match"
fi

