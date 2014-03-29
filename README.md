experiments
===========

open research data

This is a place for experiments.

HTML_in_Scheme
--------------

Bare-bones notes on a concept for writing HTML in s-exprs.  Trying to do it *without* lots of
quotation marks.

Optimal-Gray-Code-Banker-Sequence
---------------------------------

A program by which is found, by exhaustive search, whether an optimal Gray code banker's sequence
exists for a given *n*.

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

