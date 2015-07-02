target = Makefile

source = $(target)

all::
	@echo "There is nothing to build here."

vi:
	vi $(source)

include common.mk

