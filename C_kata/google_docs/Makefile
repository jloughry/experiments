target = skeleton
executable = $(target).exe

CC=gcc
CC_FLAGS = -Wall -Wunreachable-code -Werror
DEBUG_FLAGS = -DDEBUG
PRODUCTION_FLAGS = -DNDEBUG
editor = vi
are_you_sure = util/are_you_sure

#
# This Makefile will always re-build, because it doesn't know whether the currently
# existing executable, if it's up to date, is debug or production.
#

all:: production

objects = skeleton.o usage.o

$(executable): $(objects) Makefile
	$(CC) $(CC_FLAGS) -o $(executable) $(objects)

captured_output_files = TC-*.stdout TC-*.stderr
temporary_files = *.o $(executable).stackdump $(captured_output_files)

c_sources = skeleton.c usage.c
all_sources = $(c_sources) skeleton.h

test_cases = TC-1.stdout_expected_result TC-1.stderr_expected_result \
	TC-2.stdout_expected_result TC-2.stderr_expected_result \
	TC-3.stdout_expected_result TC-3.stderr_expected_result \
	TC-4.stdout_expected_result TC-4.stderr_expected_result \
	TC-5.stdout_expected_result TC-5.stderr_expected_result

vi:
	$(editor) $(target).c

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable) $(are_you_sure)

distclean: allclean
	rm -f $(test_cases)

production: $(all_sources) Makefile
	make allclean
	$(CC) $(CC_FLAGS) $(PRODUCTION_FLAGS) -c $(c_sources)
	make $(executable)
	strip $(executable)

debug: $(sources) Makefile
	make allclean
	$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -c $(c_sources)
	make $(executable)

$(are_you_sure): $(are_you_sure).c
	(cd util && make)

generate_test_case_data: $(are_you_sure)
	@echo
	@echo "This target should only be used with a known-good executable."
	@if (./$(are_you_sure)) then \
		./$(executable)      > TC-1.stdout_expected_result 2> TC-1.stderr_expected_result ; \
		./$(executable) 10   > TC-2.stdout_expected_result 2> TC-2.stderr_expected_result ; \
		./$(executable) -T   > TC-3.stdout_expected_result 2> TC-3.stderr_expected_result ; \
		./$(executable) T    > TC-4.stdout_expected_result 2> TC-4.stderr_expected_result ; \
		./$(executable) 10 T > TC-5.stdout_expected_result 2> TC-5.stderr_expected_result ; \
		true ; \
		echo "All test cases have been regenerated." ; \
	fi

test: $(executable) $(test_cases)
	@rm -f $(captured_output_files)
	@./TC-1.sh
	@./TC-2.sh
	@./TC-3.sh
	@./TC-4.sh
	@./TC-5.sh

help:
	@echo "This Makefile has the following useful targets:"
	@echo "    production               build $(executable) without assertions or debug symbols"
	@echo "    debug                    build $(executable) with assertions"
	@echo "    test                     run a series of tests automatically"
	@echo "    clean                    remove temporary files"
	@echo "    allclean                 remove everything that can be regenerated automatically"
	@echo "    distclean	            even remove test cases"
	@echo "    generate_test_case_data  rebuild test cases"
	@echo "    vi                       edit the main programme"
	@echo "Executing make with no arguments will build production."

include common.mk

