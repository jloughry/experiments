rdp: recursive descent parser in Java
===

This is my experimental parser (in Java), loosely based on the one in the
[Wikipedia article](http://en.wikipedia.org/wiki/Recursive_descent_parser)
on *recursive descent parser* and adapted; in particular, the example grammar
is for a PL/0 language designed by Niklaus Wirth, and it shows: the productions
use semicolons as separators and end with a period. I think the example's
productions are expressed in an unclear manner; I prefer a clearer BNF that
maps more directly to functions.

My grammar is for a simplified Scheme variant; for now, beginning with
*s*-expressions.

Features
--------
1. It accepts all legal Scheme identifiers.

2. Numbers are integers only, but represented internally as `long long` int. Numbers
can have + or - signs on them, but no radix indicators or decimal points yet.

3. It understands #t and #f booleans, and strings with or without embedded quotation
marks.

4. A pre-processor (sed script) is used to remove comments before lexing. Following
convention, comments are replaced by a single space; newlines are left in place so
that the parser, eventually, can report sensible line numbers of syntax errors in the
source.

TODO
----
1. Add mutually recursive functions to parse expressions.

2. Build parse tree of an entire programme.

3. Walk the tree and interpret the programme.

4. Start parsing &lt;program&gt; from &lt;form&gt;*

5. Re-implement in Java from scratch, not using many library functions except for
safety until I get used to them and learn what's available.

Notes:
------

ANSI C does not guarantee `ungetc(3)` to work more than once; in several instances
we need to push back more than one character. One way to avoid the necessity is to
implement look-ahead, as in a LALR(1) parser; investigate how to do this with FILE
streams.

Two global variables are used&mdash;for now&mdash;to match the structure in the
[Wikipedia article](http://en.wikipedia.org/wiki/Recursive_descent_parser) on
&lsquo;Recursive descent parser&rsquo;. When I get it working and understand the
*algorithm* better, I'll remove the global variables and improve the structure
of the *programme*.

