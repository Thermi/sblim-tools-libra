include setting.cmpi
VERSION=1

CFLAGS=-g -c -fPIC
LDFLAGS=-shared -Wl,-soname=$@.$(VERSION) -lc

all: libratools.so 

libratools.so: execscripts.o conf.o rastr.o monitors.o
	$(CC) $(LDFLAGS) $^ -o $@

install: libratools.so
	install -d $(COMMONLIB_OUT)
	install libratools.so $(COMMONLIB_OUT)/libratools.so
	/sbin/ldconfig -N -n $(COMMONLIB_OUT)

clean:
	rm -f ./*.so* ./*.o

