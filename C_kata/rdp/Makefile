target = rdp

executable = $(target).exe

CC=gcc
CFLAGS = -Wall -Wunreachable-code -Werror
DEBUG_FLAGS = -DDEBUG
PRODUCTION_FLAGS = -DNDEBUG
editor = vi

testfile = length.scm

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(target).c $(target).h Makefile
	$(CC) -o $@ $(CFLAGS) $(DEBUG_FLAGS) $<

test: $(executable)
	./$< $(testfile)

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/common.mk

vi:
	$(editor) $(target).c

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable)

include common.mk

