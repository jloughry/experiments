target = skeleton
executable = $(target).exe

CC=gcc
CC_FLAGS = -Wall -Wunreachable-code
DEBUG_FLAGS = -DDEBUG
PRODUCTION_FLAGS = -DNDEBUG
editor = vi

#
# This Makefile will always re-build, because it doesn't know whether the currently
# existing executable, if it's up to date, is debug or production.
#

all:: production

objects = skeleton.o usage.o

$(executable): $(objects) Makefile
	$(CC) $(CC_FLAGS) -o $(executable) $(objects)

temporary_files = *.o $(executable).stackdump

c_sources = skeleton.c usage.c
all_sources = $(c_sources) skeleton.h

vi:
	$(editor) $(target).c

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable)

production: $(all_sources) Makefile
	make allclean
	$(CC) $(CFLAGS) $(PRODUCTION_FLAGS) -c $(c_sources)
	make $(executable)
	strip $(executable)

debug: $(sources) Makefile
	make allclean
	$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -c $(c_sources)
	make $(executable)

test:
	@echo -n "TC-1: "; if [ `./$(executable)`      ]; then echo "FAIL"; else echo "OK"; fi
	@echo -n "TC-2: "; if [ `./$(executable) 10 > /dev/null`   ]; then echo "FAIL"; else echo "OK"; fi
	@echo -n "TC-3: "; if [ `./$(executable) -T`   ]; then echo "FAIL"; else echo "OK"; fi
	@echo -n "TC-4: "; if [ `./$(executable) T`    ]; then echo "FAIL"; else echo "OK"; fi
	@echo -n "TC-5: "; if [ `./$(executable) 10 T` ]; then echo "FAIL"; else echo "OK"; fi

help:
	@echo "This Makefile has the following useful targets:"
	@echo "    production    $(executable) without assertions or debug symbols"
	@echo "    debug         $(executable) with assertions"
	@echo "    test          run a series of tests automatically"
	@echo "    clean         remove temporary files"
	@echo "    allclean      remove everything that can be regenerated automatically"
	@echo "    vi            edit the main programme"
	@echo "Executing make with no arguments will build production."

include common.mk

