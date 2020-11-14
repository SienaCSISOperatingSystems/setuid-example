#
# Makefile for setuid example
#

PROGRAMS=setuid

all:	$(PROGRAMS)

setuid:	setuid.c
	gcc -o setuid setuid.c

clean::
	/bin/rm -f $(PROGRAMS) setuid.0 setuid.jcool

copies::
	cp setuid setuid.0
	chown root setuid.0
	chmod 4755 setuid.0
	cp setuid setuid.jcool
	chown jcool setuid.jcool
	chgrp www setuid.jcool
	chmod 6755 setuid.jcool
