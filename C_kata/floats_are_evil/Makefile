float = floats_are_evil
double = doubles_are_evil

executables = $(float) $(double)

all: $(float) $(double)

$(float): $(float).c
	gcc -Wall -Werror -pedantic -o $@ $<
	mv $@.exe $@

$(double): $(double).c
	gcc -Wall -Werror -pedantic -o $@ $<
	mv $@.exe $@

test:
	./$(float)
	./$(double)

clean:
	rm -fv $(executables)

