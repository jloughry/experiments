# Some notes on an algorithm for approximately matching character strings.

Licence plate numbers, *e.g.*, may contain characters that are easily confused,
especially in poor conditions, such as "1" and "I", or "O" and "0". To avoid
false negatives, use a fuzzy matching algorithm like
[this](https://github.com/jloughry/experiments/blob/master/fuzzy/fuzzymatch.sh):

````
tr -dc "[:alnum:]" \
tr "[:lower:]" "[:upper:]" \
tr $regular_alphabet $strange_alphabet)
````

## Implementation Notes

First, ignore anything not in `[A-Z][0-9]` (in particular, dashes are ignored). Then
convert the string to upper case. Finally, collapse commonly confused characters
to a single representation, then match to the target after the same transformations
have been made to it.

````
% tr -dc "[:alnum:]"
% tr "[:lower:]" "[:upper:]"
% tr "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" "ABCOEFGHIIKLMNOPORSTVVVXY2OI234S6789"
````

## Testing

````
% ./fuzzymatch.sh tk42iO TK-4210
Match!
% ./fuzzymatch.sh tk42iO 012-ABC
no match
% ./fuzzymatch.sh 012abc 012ABC
Match!
````
## Notes for Improvement

It would be preferable to accept either "V" or "W" for all of "U", "V", and "W".

