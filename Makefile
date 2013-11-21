target = html_in_scheme

source = $(target).scm
documentation = README.md

#
# Note: make requires that we set the value of a variable OUTSIDE any rules.
#

timestamp = `date +%Y%m%d.%H%M`

vi:
	vi $(source)

notes:
	(cd ../notes && make vi)

quotes:
	(cd ../notes && make quotes)

bibtex:
	(cd ../bibtex && make vi)

commit:
	git add .
	git commit -am "commit from Makefile $(timestamp)"
	make sync

sync:
	git pull --rebase
	git push

readme:
	vi $(documentation)

spell:
	aspell --lang=en check $(documentation)

clean:
	rm -f $(documentation).bak

