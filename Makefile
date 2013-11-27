target = html_in_scheme

source = $(target).scm

all::
	@echo "There is nothing to build here."

vi:
	vi $(source)

include common.mk

