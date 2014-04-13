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

3. It understands #t and #f booleans, and strings with or without embedded quotation
marks.

TODO
----
1. Add mutually recursive functions to parse expressions.

2. Build parse tree of an entire programme.

3. Walk the tree and interpret the programme.

Notes:
------

ANSI C does not guarantee `ungetc(3)` to work more than once; in several instances
we need to push back more than one character. One way to avoid the necessity is to
implement look-ahead, as in a LALR(1) parser; investigate how to do this with FILE
streams.

Two global variables are used&mdash;for now&mdash;to match the structure in the
[Wikipedia article](http://en.wikipedia.org/wiki/Recursive_descent_parser) on
&lsquo;Recursive descent parser&rsquo;. When I get it working and understand the
*algorithm* better, I'll remove the globabl variables and improve the structure
of the *programme*.

