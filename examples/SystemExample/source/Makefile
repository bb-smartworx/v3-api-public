NAME=SystemExample

CROSS_COMPILE=../../../toolchain/usr/bin/armv7l-timesys-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
CXX=$(CROSS_COMPILE)g++
CFLAGS=-march=armv7-a -mtune=cortex-a8 -g -pthread -mfloat-abi=softfp -mfpu=neon -ffast-math -O3 -fPIC
CPPFLAGS = -I../../../include/
LDFLAGS = -s -L../../../lib
LDLIBS = -lbbapi -ljson-c

MODULE_CGI_EXE = module_cgi
MODULE_CGI_OBJ = module_cgi.o

all: $(MODULE_CGI_EXE)

$(MODULE_EXE): $(MODULE_OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(MODULE_CGI_EXE): $(MODULE_CGI_OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(MODULE_EXE) $(MODULE_CGI_EXE) *.o

install:
	install -d $(DESTDIR)/bin/
	install -d $(DESTDIR)/www/		
	install -m 755 $(MODULE_CGI_EXE) $(DESTDIR)/bin/cgi
	ln -s ../bin/cgi $(DESTDIR)/www/index.cgi
	ln -s /etc/htpasswd $(DESTDIR)/www/.htpasswd
