target = optimal_gray_code_banker_sequence

rm = rm -f
cc = cc -Wall
edit = vi

all: $(target)

$(target): $(target).c
	$(cc) -o $@ $?
	mv $@.exe $@

clean:
	$(rm) $(target)

test: $(target)
	./$(target) 5

vi:
	$(edit) $(target).c

notes:
	(cd ../../notes && make vi)

quotes:
	(cd ../../notes && make quotes)

bibtex:
	(cd ../../bibtex && make vi)

