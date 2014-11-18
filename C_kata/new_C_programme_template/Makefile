target = new_C_programme_template

executable = $(target).exe

CC=gcc
CFLAGS = -Wall -Wunreachable-code -Werror
editor = vi

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(target).c $(target).h Makefile
	$(CC) -o $@ $(CFLAGS) $<

test: $(executable)
	./$< 1
	./$< -1
	-./$< hello
	-./$< 10000000000000000000000000000000000000000000
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
	rm -f $(executable)

include common.mk

