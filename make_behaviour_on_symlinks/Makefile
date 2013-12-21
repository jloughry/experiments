target = hellow_world
source = $(target).c

$(target): $(source) Makefile
	cc -Wall -Werror -o $(target) $(source)
	mv $(target).exe $(target)

test:
	./$(target)

clean:
	rm -f $(target)

include common.mk

