# Some notes on defeating cryptographic hash fingerprinting to detect particular file versions.

One way of rapidly detecting the presence of particular files of interest
(especially binary data files such as graphics or compiled programmes that
can't, generally, be easily modified the way text files can) that is resistant
to renaming is to search for matching cryptographic hash fingerprints instead
of file names. To defeat this method, in general it suffices to change one
bit of the file, which is enough to drastically alter the value of a good
cryptographic hash like SHA-1 (or SHA-256 or MD5). The trick is to flip a
bit innocuously or without detection in a binary file; some binary file formats
are more resistant to small random changes than others.

## Implementation Notes

If the binary file format contains an in-built check-sum, like some executable
file formats do, then it may be necessary to update the check-sum after modification
to ensure the check-sum is valid. The purpose, in general, is to disguise the file
from scanners whilst retaining the ability to open or use the file normally.

Some graphics file formats, *e.g.*, GIF89a, are tolerant of data being inserted
into the file, if the file format is respected. Others, *e.g.*, JPEG, are tolerant
of appended data. When modifying a graphics file, one should keep in mind the
colour palette, internal block structure, and other features of the file format
that might lend themselves to innocuous modification without seriously impacting
the usability of the graphic.

### Notes for further experiments

It would be interesting to try to modify the value of a single pixel of a
graphics file to a 'similar' value in the colour palette so that the modification
would be effectively invisible.

## Experiments

As an experiment, a GIF89a file was altered using the above-described method
as a test. Several arbitrary bytes were inserted near the end of the file *after*
the final `00` (hex) byte indicating the end of a block but before the final
`;` (hex 3B) byte indicating the end of the file.

## Results

The following hashes were measured before and after the changes to the file:

### MD5

`92d8eb85a01a4896d84486a332b02c82` (before)

`cd466d4ba8bc2003298fddd14f20090c` (after)

### SHA-1

`9dcd0d788175135c51fbba17b4ecdbe276aa66aa` (before)

`d6318b95468add3b4c5d350df58d8d08e756e17b` (after)

### SHA-256

`474becfdf470729f962f14f65a708583cd023b5ef6c721f7ba8d2e2aec07c8f2` (before)

`84b81db97c947eee24b41db19458b1ec63253e0ad39b5356955e77340417f734` (after)

Note that the size of the file also changed, because of the addition of arbitrary
bytes; it is no longer possible rapidly to identify the file by name, size, or
cryptographic hash.

## Viewer results

The file displays normally in some programmes but not others:

- Microsoft Windows XP (Service Pack 3) no longer recognised the file format
after the modification, in Windows Explorer; it would no automatically open
or display the file.

- Windows Picture and Fax Viewer, however, if specifically used to open the
file, did work.

- Firefox displayed the file normally.

- Paint opened the file normally.

- Inkscape failed to open the file.

## Interpretation

Some viewers depend on the file name extension, others look inside the file for a
magic number or other identifying mark to determine the type of a file for display.
Disguising a binary file from the latter type of programme is more difficult.

## Conclusions

It is possible to disguise at least one type of binary file from naïve searches
looking for a match on filename, size (even size on disk), and cryptographic hash
without making the file unusable to the programmes intended to read it.

