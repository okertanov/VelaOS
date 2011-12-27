##    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
##    All rights reserved.

include ../src/Makefile.common

MODULE_NAME := DOC

SOURCES :=
TARGETS := documentation

documentation:

html: html/index.html
	doxygen

pdf: latex/Makefile
	$(MAKE) --no-print-directory -C latex
	$(MV) latex/refman.pdf ./VelaOS-Reference-Manual.pdf


.PHONY: html pdf

include ../src/Makefile.targets

