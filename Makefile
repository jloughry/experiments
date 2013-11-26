target = html_in_scheme

source = $(target).scm

all:
	@echo "There is nothing to build here."

vi:
	vi $(source)

spell:
	aspell --lang=en check README.md

clean:
	@echo "\"make clean\" doesn't do anything here"

include common.mk

