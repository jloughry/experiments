target = rdp

executable = $(target).class
source = $(target).java

compile = javac
cflags = -Werror -Xlint:all
editor = vi

testfile = length.scm
preprocessor = ./pre-process.sh

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(source) Makefile
	$(compile) $(cflags) $<

test: $(executable)
	make test_1
	make test_2
	make test_3
	make test_4
	@echo
	@echo "All tests succeeded."

test_1: # with no arguments:
	-java $(target)

test_2: # with a nonexistent file:
	-java $(target) file_that_does_not_exist

test_3: # with a valid filename on the command line:
	java $(target) $(testfile)

test_4: # with input piped via the preprocessor:
	# $(preprocessor) $(testfile) | ./$<

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

