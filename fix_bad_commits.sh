#!/bin/sh

#
# This is a script to fix orphaned commits accidentally done as "Joe Loughry"
# (rjl@applied-math.org) instead of "jloughry" (joe.loughry@gmail.com) back
# before I established my current GitHub account. I don't want to lose the
# history of those changes, so reset them to the correct identity so they get
# credited properly in `git blame` from now on.
#

git filter-branch -f --env-filter '

an="$GIT_AUTHOR_NAME"
am="$GIT_AUTHOR_EMAIL"
cn="$GIT_COMMITTER_NAME"
cm="$GIT_COMMITTER_EMAIL"
 
if [ "$GIT_COMMITTER_EMAIL" = "rjl@applied-math.org" ]
then
	cn="jloughry"
	cm="joe.loughry@gmail.com"
fi
if [ "$GIT_AUTHOR_EMAIL" = "rjl@applied-math.org" ]
then
	an="jloughry"
	am="joe.loughry@gmail.com"
fi
 
export GIT_AUTHOR_NAME="$an"
export GIT_AUTHOR_EMAIL="$am"
export GIT_COMMITTER_NAME="$cn"
export GIT_COMMITTER_EMAIL="$cm"
'

