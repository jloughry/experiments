target = hello_world
source = $(target).c

all:: $(target)

clean::
	rm -f $(target)

$(target): $(source) Makefile
	cc -Wall -Werror -o $(target) $(source)
	mv $(target).exe $(target)

test:
	./$(target)

include common.mk

