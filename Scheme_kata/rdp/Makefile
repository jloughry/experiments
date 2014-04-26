target = rdp

source = $(target).scheme

scheme = /usr/bin/guile
editor = vi

testfile = length.scm
preprocessor = ./pre-process.sh

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: test

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

test:
	make test_1
	@echo
	@echo "All tests succeeded."

test_1: # testfile
	$(scheme) -l $(testfile)

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/$@

vi:
	$(editor) $(source)

testfile:
	$(editor) $(testfile)

makefile:
	$(editor) Makefile

commit_this:
	make allclean
	(cd ../.. && make commit)

# convenience target in case I mistype it:
commit-this: commit_this

clean::
	rm -f $(temporary_files)

allclean: clean

include common.mk

