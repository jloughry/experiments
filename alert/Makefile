target = alert

executable = $(target).exe

CC=g++
CFLAGS = -Wall -Wunreachable-code -Werror
editor = vi

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(target).c $(target).h Makefile
	$(CC) -o $@ $(CFLAGS) $<
	mv $(executable) $(target)

test: $(target)
	- ./$<
	./$< "This is a test."
	-./$< too many command line arguments
	@echo
	@echo "All tests passed."

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/common.mk

vi:
	$(editor) $(target).c

header:
	$(editor) $(target).h

commit_this:
	(cd ../.. && make commit)

commit-this: commit_this

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(target)

include common.mk

