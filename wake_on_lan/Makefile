target = WakeOnLan

executable = $(target).class
source = $(target).java

all: $(executable)

$(executable): $(source)
	javac $(source)
	chmod a+r,a+x $(executable)

vi:
	vi $(source)

test:
	java $(target) 192.168.0.255 00:26:b0:e9:a4:0c

