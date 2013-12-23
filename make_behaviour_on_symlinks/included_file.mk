#
# This is a file to be included by Make, but Make will only see
# a symlink to this file. Will it correctly determine that the
# build is out of date if this file is changed? Make will have
# to look through the symlink to do it.
#

Makefile: common.mk
	touch Makefile

