target = rdp

executable = $(target).class
source = $(target).java

compile = javac
editor = vi

testfile = length.scm
preprocessor = ./pre-process.sh

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(source) Makefile
	$(compile) $<

test: $(executable)
	java $(target)
	/bin/false
	-./$< file_that_does_not_exist
	$(preprocessor) $(testfile) | ./$<
	@echo
	@echo "All tests succeeded."

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/common.mk

vi:
	$(editor) $(target).java

makefile:
	$(editor) Makefile

commit_this:
	make allclean
	(cd ../.. && make commit)

commit-this: commit_this

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable)

include common.mk

