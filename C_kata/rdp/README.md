rdp: recursive descent parser
===

This is my experimental parser, loosely based on the one in the
[Wikipedia article](http://en.wikipedia.org/wiki/Recursive_descent_parser)
on *recursive descent parser* and adapted; in particular, the example grammar
is for a PL/0 language designed by Niklaus Wirth, and it shows: the productions
use semicolons as separators and end with a period. I think the example's
productions are expressed in an unclear manner; I prefer a clearer BNF that
maps more directly to functions.

My grammar is for a simplified Scheme variant; for now, beginning with *s*-expressions.

Features
--------
1. It accepts all legal Scheme identifiers.

2. Numbers are integers only, but represented internally as `long long` int. Numbers
can have + or - signs on them, but no radix indicators or decimal points yet.

TODO
----
1. Add mutually recursive functions to parse expressions.

2. Build parse tree of an entire programme.

3. Walk the tree and interpret the programme.

