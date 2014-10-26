#!/bin/sh

set -euo pipefail
IFS=$'\n\t'

echo -n "Signing the clipboard..."

/usr/local/bin/gpg2 \
	-u 0xEDC2ABE5 \
	--personal-digest-preferences SHA256 --clearsign \
	< /dev/clipboard \
	> /dev/clipboard && cat /dev/clipboard

if [ ! $? ]; then
	echo "Signed successfully"
else
	echo "A problem occurred."
fi

