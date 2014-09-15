MODNAME := $(shell basename $$PWD)
TEMPDIR := /tmp/module
IMGDIR  ?= .
ROUTER  ?= 192.168.90.10

export DESTDIR := $(TEMPDIR)/$(MODNAME)

all:
	rm -rf $(DESTDIR)
	mkdir -p $(DESTDIR)
	cp -r merge/* $(DESTDIR)
	make -C source all install
	tar --exclude 'CVS' -C $(TEMPDIR) -czf $(IMGDIR)/$(MODNAME).tgz $(MODNAME)
	rm -rf $(DESTDIR)

clean:
	make -C source clean
	rm -f $(IMGDIR)/$(MODNAME).tgz

install: all
	curl -F file=@$(IMGDIR)/$(MODNAME).tgz --output /dev/null http://root:root@$(ROUTER)/module_add.cgi
