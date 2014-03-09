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

