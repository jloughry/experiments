target = optimal_gray_code_banker_sequence

chart_source = order-5_graph.dot
pdf_file = order-5_graph.pdf

rm = rm -f
cc = cc -Wall
edit = vi

all: $(target) $(pdf_file)

$(target): $(target).c
	$(cc) -o $@ $?
	mv $@.exe $@

clean:
	$(rm) $(target) $(pdf_file)

test: $(target)
	./$(target) 5

vi:
	$(edit) $(chart_source)

$(pdf_file): $(chart_source)
	dot -T pdf $(chart_source) -o $(pdf_file)

notes:
	(cd ../../notes && make vi)

quotes:
	(cd ../../notes && make quotes)

bibtex:
	(cd ../../bibtex && make vi)

