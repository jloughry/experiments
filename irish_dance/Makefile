target = irish_dance_school_year_2013-14

pdf = $(target).pdf

latex_cmd=pdflatex
editor = vi

source = $(target).tex
temporary_files = *.aux *.log

all:: $(pdf)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(pdf): $(source) Makefile
	$(latex_cmd) $<
	while ( \
		pdflatex $(basename $<) ; \
		grep "Rerun to get" $($basename $<).log > /dev/null \
	) do true ; done

vi:
	$(editor) $(source)

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(pdf)

include common.mk

