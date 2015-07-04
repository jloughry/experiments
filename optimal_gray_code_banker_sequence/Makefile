target = optimal_gray_code_banker_sequence

chart = order-5_graph.dot

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
	$(edit) $(chart)

chart:
	dot -T pdf $(chart) -o order-5_graph.pdf

notes:
	(cd ../../notes && make vi)

quotes:
	(cd ../../notes && make quotes)

bibtex:
	(cd ../../bibtex && make vi)

