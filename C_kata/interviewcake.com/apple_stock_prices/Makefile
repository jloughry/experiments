target = apple_stock_prices

executable = $(target).exe

CC=gcc
CFLAGS = -Wall -Wunreachable-code -Werror
DEBUG_FLAGS = -DDEBUG
PRODUCTION_FLAGS = -DNDEBUG
editor = vi

temporary_files = 

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(target).c Makefile
	$(CC) -o $@ $(CFLAGS) $(DEBUG_FLAGS) $<

test: $(executable)
	./$<

vi:
	$(editor) $(target).c

clean::
	rm -f $(temporary_files) consolidated_bibtex_file.bib

allclean: clean
	rm -f $(executable)

include common.mk

