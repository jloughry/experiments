target = html_in_scheme

source = $(target).scm

include ../Makefiles/git1.mk

vi:
	vi $(source)

include ../Makefiles/git2.mk

notes:
	(cd ../notes && make vi)

quotes:
	(cd ../notes && make quotes)

bibtex:
	(cd ../bibtex && make vi)

spell:
	aspell --lang=en check $(documentation)

clean:
	rm -f $(documentation).bak

