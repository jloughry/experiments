target = eicargen

executable = $(target).class
source = $(target).java

compile = javac
cflags = -Werror -Xlint:all
editor = vi

temporary_files = $(executable).stackdump consolidated_bibtex_file.bib

all:: $(executable)

#
# $@ is target; $< is first dependency; $^ is all dependencies; $? is all newer dependencies
#

$(executable): $(source) Makefile
	$(compile) $(cflags) $<

test: $(executable)
	java $(target)
	@echo
	@echo "All tests succeeded."

common.mk:
	ln -s /home/rjl/Documents/thesis/github/Makefiles/common.mk

vi:
	$(editor) $(target).java

makefile:
	$(editor) Makefile

commit_this:
	make allclean
	(cd ../.. && make commit)

commit-this: commit_this

clean::
	rm -f $(temporary_files)

allclean: clean
	rm -f $(executable)

include common.mk

