#
#   @copyright  Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
#   @license    BSD
#

include Makefile.common

all:
	$(MAKE) -C lib/xen mini-os-$@
	$(MAKE) -C boot $@
	$(MAKE) -C lib/syslib $@
	$(MAKE) -C lib/lua $@

clean:
	$(MAKE) -C lib/xen mini-os-$@
	$(MAKE) -C boot $@
	$(MAKE) -C lib/syslib $@
	$(MAKE) -C lib/lua $@

.PHONY: all clean

