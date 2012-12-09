target = html_in_scheme

source = $(target).scm

vi:
	vi $(source)

notes:
	(cd ../notes && make vi)

quotes:
	(cd ../notes && make quotes)

bibtex:
	(cd ../bibtex && make vi)

