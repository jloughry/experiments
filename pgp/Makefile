target = readme

editor = vi

source = $(target).md

temporary_files = consolidated_bibtex_file.bib README.md.bak

all::
	@echo "There is nothing to make in this directory. Try 'make readme'"

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

clean::
	rm -f $(temporary_files)

allclean: clean

include common.mk

