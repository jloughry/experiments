target = prime

executable = $(target).exe

CC=gcc
CFLAGS = -Wall -Wunreachable-code -Werror
DEBUG_FLAGS = -DDEBUG
PRODUCTION_FLAGS = -DNDEBUG
editor = vi

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(target).c Makefile
	$(CC) -o $@ $(CFLAGS) $(DEBUG_FLAGS) $<

test: $(executable)
	./$< 1
	./$< 2
	./$< 3
	./$< 4
	./$< 5
	./$< 6
	./$< 7
	./$< 65353
	./$< 101
	./$< 1001
	./$< 10001
	./$< 100001
	./$< 1000001
	./$< 10000001
	./$< 100000001
	./$< 1000000001
	./$< 10000000001
	./$< 100000000001
	./$< 1000000000001
	./$< 10000000000001
	./$< 100000000000001
	./$< 1000000000000001
	./$< 10000000000000001

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/common.mk

vi:
	$(editor) $(target).c

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable)

include common.mk

