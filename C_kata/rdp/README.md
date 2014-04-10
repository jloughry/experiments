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

