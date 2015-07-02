experiments
===========

*(open research data)*

This is a place for experiments.

## [Benford's Law](https://github.com/jloughry/experiments/blob/master/Benfords_Law/README.md)

An experiment showing how easy it is to tell the difference between "real" and "fake"
data by looking at probability distribution functions.

## [Fingerprint](https://github.com/jloughry/experiments/blob/master/fingerprint/README.md)

Some notes on defeating cryptographic hash fingerprinting of files for the purpose
of detecting particular versions of those files.

## [fuzzy matching of licence plate numbers](https://github.com/jloughry/experiments/blob/master/fuzzy/README.md)

Some notes on an algorithm for approximately matching licence plate numbers, ignoring
commonly confused characters like "1" and "I" or "O" and "0".

HTML_in_Scheme
--------------

Bare-bones notes on a concept for writing HTML in s-exprs.  Trying to do it *without* lots of
quotation marks.

Optimal-Gray-Code-Banker-Sequence
---------------------------------

A program by which is found, by exhaustive search, whether an optimal Gray code banker's sequence
exists for a given *n*.

The file `order_5.txt` will be a PIC description containing an optimal
order-5 tree.

make_behaviour_on_symlinks
--------------------------

Why won't `make` detect that an included file is out of date? Is it because the included
file is on the other side of a symbolic link? GNU Make is supposed to work correctly in
that situation. Find out the solution here.

available_dot_com_names_in_usr_dict_words
-----------------------------------------

This is the list of `/usr/dict/words` that are not already registered as domain names
from [HN](https://news.ycombinator.com/item?id=7365998) but sorted by length.

Sorting by length is an interesting programming problem; it can't be done by a regular
expression. One way is to use a mask:

    % sed -e "s/./x/g" < original.txt > mask.txt
    % paste mask.txt original.txt | sort | cut -f 2
    % rm mask.txt

Eliminating the temporary file:

    % sed -e "s/./x/g" < list.txt | paste - list.txt | sort | cut -f 2

We can eliminate the `paste` by using `sed`'s hold buffer, but at the cost of another
regexp to get rid of the spurious newline inserted by `sed`:

    % sed -e "h;s/./x/g;G;s/\n/\t/" list.txt | sort | cut -f2

*How it works: **h** copies the pattern buffer into the hold space, then `s/./x/g` is run
on the pattern buffer to build a mask. Commands are separated by semicolons. **G** appends
the hold space to the pattern space (with a newline between), and `s/\n/\t/` changes that
newline to a tab which is the delimiter expected by `cut` later on. Lines that look like
`xxxx word` sort by the length of the mask, then the mask is thrown away by `cut`.

The line can be shortened slightly removing spaces that are not strictly needed:

    % sed -e"h;s/./x/g;G;s/\n/\t/" list.txt|sort|cut -f2

`irish_dance`
-------------

To extract a list of events from Google Calendar, use the command line tools. Once the
[`googlecl`](https://code.google.com/p/googlecl) package has been installed, do this:


````
$ google calendar list --date 2013-08-26,2014-03-25 --cal "Miranda's Things"
````

OUSS_logo
---------

The logo of the [Oxford University Scientific Society](http://users.ox.ac.uk/~science/),
founded in 1882.

The colour is Oxford Blue, Pantone 282, RGB $(0,33,71)$ or in hexadecimal, \verb,#002147,
according to [this reference](http://www.ox.ac.uk/branding_toolkit/the_brand_colours/).

C_kata
------

This is a series of *kata* type exercises in C. So far, the working ones are:

- [`binary_search_tree`](https://github.com/jloughry/experiments/tree/master/C_kata/binary_search_tree/)
*an implementation of a binary search tree*
- [`bloom_filter`](https://github.com/jloughry/experiments/tree/master/C_kata/bloom_filter/)
*very simple Bloom filter*
- [`framework`](https://github.com/jloughry/experiments/tree/master/C_kata/framework/)
*copy this directory to begin writing a new C programme quickly*
- [`free_the_wrong_pointer`](https://github.com/jloughry/experiments/tree/master/C_kata/free_the_wrong_pointer/)
*What happens if you give free() a different value from what malloc() provided? Undefined behaviour (UB).*
- [`google_docs`](https://github.com/jloughry/experiments/tree/master/C_kata/google_docs/)
*an experimental implementation of automatically generated unit tests*
- [`hash`](https://github.com/jloughry/experiments/tree/master/C_kata/hash/)
*implement a hash table using arrays*
- [`interviewcake.com`](https://github.com/jloughry/experiments/tree/master/C_kata/interviewcake.com/)
*the &ldquo;Apple Stock Prices&rdquo; problem from [interviewcake.com](http://interviewcake.com).
- [`mergesort`](https://github.com/jloughry/experiments/tree/master/C_kata/mergesort/)
*merge sort*
- [`shellsort`](https://github.com/jloughry/experiments/tree/master/C_kata/shellsort/)
*Shell sort*
- [`rdp`](https://github.com/jloughry/experiments/tree/master/C_kata/rdp/)
*recursive descent parser* (beginnings of a Scheme interpreter)
- [`scheme_syntax_highlighter`](https://github.com/jloughry/experiments/tree/master/C_kata/scheme_syntax_highlighter/)
*the beginnings of a syntax highlighter for Scheme* (based on `wikipedia_article_parser`)
TODO: parse comments as if they were a chunked variable; this will allow the syntax
highlighter to get at their contents.
- [`simple_repl`](https://github.com/jloughry/experiments/tree/master/C_kata/simple_repl/)
*read-eval-print loop*
- [`sort`](https://github.com/jloughry/experiments/tree/master/C_kata/sort/)
*a functional version of quicksort using linked lists&mdash;not the in-place variant*
- [`stack`](https://github.com/jloughry/experiments/tree/master/C_kata/stack/)
*an extensible stack implementation using linked lists* (also implements a queue
using a pair of stacks, the second demo problem from [interviewcake.com](http://interviewcake.com)).
- [`string_reverse`](https://github.com/jloughry/experiments/tree/master/C_kata/string_reverse/)
*using no library functions, in constant space*
- [`wikipedia_article_parser`](https://github.com/jloughry/experiments/tree/master/C_kata/wikipedia_article_parser/)
*from the Wikipedia article "Recursive_descent_parser"*
- [`factorial`](https://github.com/jloughry/experiments/tree/master/C_kata/factorial/)
*just a little warmup: visually indicate recursion depth*

All of these are working and reasonably complete; all memory allocated is freed, and
no global variables are used. The code is fairly functional in design. Things are mostly
dynamically allocated so that unlimited numbers of them can be created, used concurrently,
and destroyed when no longer needed. Thread safety is not considered. In the `hash` example,
`assert()` is used freely, but hasn't been used much elsewhere (it's an example of style).

The style used throughout, with the exception of `assert()`, is pedantic. Cleverness is
eschewed in favour of clarity and reliability.

### TODO

The `wikipedia_article_parser` is working, but needs be extended to parse names of
identifiers and remember them; in addition, for doing proper syntax highlighting,
it needs to not merely parse comments as spaces but parse them as units and remember
the contents of the comment so it can be syntax-highlighted in the proper place in
the output. Make a copy of the working `wikipedia_article_parser` and call it
`scheme_syntax_highlighter` to start with.

J_kata
------

This is a series of *kata*-type exercises in Java. So far, they consist of:

- [`eicargen`](https://github.com/jloughry/experiments/tree/master/J_kata/eicargen/)
*a programme to write a file containing the EICAR standard anti-virus test
file, after Didier Stevens*
- [`logic`](https://github.com/jloughry/experiments/tree/master/J_kata/logic/)
*the difference between programmers and human beings*
- [`newtons_method`](https://github.com/jloughry/experiments/tree/master/J_kata/newtons_method/)
*find the square root of a number using Newton-Rafson iteration (not quite)*
- [`rdp`](https://github.com/jloughry/experiments/tree/master/J_kata/rdp/)
*recursive descent parser* (the beginnings of a Scheme interpreter).
- [`temp`](https://github.com/jloughry/experiments/tree/master/J_kata/temp/)
*Cory Morales's code* (TempoDB) to debug.

Perl_kata
---------

Useful moves in Perl:

- [`formatted_elapsed_time`](https://github.com/jloughry/experiments/tree/master/Perl_kata/formatted_elapsed_time/)
*call Perl in a shell script to format seconds as days, hours, minutes, seconds*

Scheme_kata
-----------

More *kata*s in Scheme. So far, the set consist of:

- [`rdp`](https://github.com/jloughry/experiments/tree/master/Scheme_kata/rdp/)
*recursive descent parser* (the beginnings of a new Scheme interpreter).

Test Programmes
---------------

- [`test_stdout_and_stderr`](https://github.com/jloughry/experiments/tree/master/test_stdout_and_stderr#readme)
is a small test programme to verify that stderr gets properly redirected when
the idiom `... >> logfile 2>&1` is used in a shell script that gets called
from **cron**.

Drawings
--------

This is a place for drawings in SVG and PDF and PostScript.

- [`TARDIS`](https://github.com/jloughry/experiments/tree/master/drawings/TARDIS#readme) contains
drawings for M's new door.

`pgp`
-----

A place for experiments with PGP (and GnuPG)

Wake-On-Lan
-----------

- [wake_on_lan](https://github.com/jloughry/experiments/tree/master/wake_on_lan/#readme)
contains Java code from [http://www.jibble.org/wake-on-lan/](http://www.jibble.org/wake-on-lan/)
to send the necessary UDP packet to wake up a machine from sleep.

`alert`
-------

- [`alert`](https://github.com/jloughry/experiments/tree/master/alert/#readme)
is a command line utility to pop up a notice box from Cygwin under Windows.

`Xcode`
-------

- [`Do Not Shutdown`](https://github.com/jloughry/experiments/tree/master/Xcode/#readme)
is a utility to prevent user temporarily from shutting down or rebooting
the system; for Mac OS X.

TODO
----

1. Improve commenting throughout C_kata sections.

2. Extend repl or rdp into a functioning Scheme interpreter beginning with
&lt;program&gt; and &lt;form&gt;.

3. Develop knowledge of Java idioms and libraries in rdp.

