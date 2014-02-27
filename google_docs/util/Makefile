target = are_you_sure

CC=gcc
CC_FLAGS = -Wall -Wunreachable-code -Werror
editor = vi

all:: $(target)

vi:
	vi $(target).c

$(target): $(target).c Makefile
	$(CC) $(CC_FLAGS) -o $@ $(target).c
	mv $@.exe $@

test: $(target)
	@if (./$(target)) then \
		echo "You're sure." ; \
	else \
		echo "You're not sure." ; \
	fi

allclean:
	rm $(target)

include common.mk

