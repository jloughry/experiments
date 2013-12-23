experiments
===========

Making `makefile` dependent on `common.mk`
------------------------------------------

I have a `Makefile` that includes a `common.mk` similarly to the way it's done
in [FreeBSD](http://svnweb.freebsd.org/base/head/sys/modules/syscons/dragon/Makefile?view=markup).

Every Makefile include `common.mk` at the end, like this:

    include common.mk

In turn, there is a symlink in the current directory that points `common.mk` to the real
location of a single `common.mk` file.

However, if I have a target that depends on `Makefile` then I want that target to depend
implicitly on `common.mk` too. But the obvious way of saying it doesn't work:

    $(target): $(source) Makefile
        cc -Wall -Werror -o $(target) $(source)
    
    include common.mk

where in `common.mk` appears the dependency:

    Makefile: common.mk

What's *supposed* to happen is that Make checks the timestamp on `common.mk` and if it's
newer than `Makefile` then `Makefile` is considered to be out of date, so `$(target)` is
out of date, so the target gets rebuilt. But that doesn't work.

### How to make it work

Instead, `common.mk` must take some kind of positive action to force `Makefile` out of
date:

    Makefile: common.mk
        touch Makefile

This works. It's ugly, but it works.

