target = WakeOnLan

executable = $(target).class
source = $(target).java

all:: $(executable)

$(executable): $(source)
	javac $(source)
	chmod a+r,a+x $(executable)

vi:
	vi $(source)

clean::
	rm $(executable)

install: private-install-WakeOnLan

test:
	java $(target) 192.168.0.255 00:26:b0:e9:a4:0c
	java $(target) 192.168.0.255 00-26-b0-e9-a4-0c
	java $(target) mkl.local 00:26:b0:e9:a4:0c
	-java $(target) mkl.local 1
	-java $(target) mkl.local 00:26:b0:g9:a4:0c
	-java $(target) mkl.local 
	-java $(target) localhost 00-26-b0-e9-a4-0c foo

include common.mk
include private.mk

