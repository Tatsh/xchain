builddir = .
top_builddir = ..
srcdir = .
top_srcdir = ..

prefix	= /usr/local
exec_prefix	= ${prefix}
libexecdir	= ${exec_prefix}/libexec
bindir		= ${exec_prefix}/bin



CC              = gcc
CFLAGS          = -g -O2 -fno-builtin-round -fno-builtin-trunc
WARNINGS	=  -Wall -Wno-long-double -Wno-import
MDYNAMICNOPIC   = 
CPPFLAGS        = 
DEFS            = -DHAVE_CONFIG_H -D__LITTLE_ENDIAN__=1
LDFLAGS         = 
HAVE_PRIVEXT    = NO
HAVE_FOREIGN_HEADERS    = YES

ifeq ($(HAVE_PRIVEXT),NO)
INCPRIVEXT      = -include $(top_srcdir)/include/extern.h
endif

ifeq ($(HAVE_FOREIGN_HEADERS),YES)
FORHDRS         = -I$(top_srcdir)/include/foreign
endif

INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
transform	= s&^&i686-apple-darwin11-&

MYINCLUDES      = -I$(srcdir) -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) \
			$(FORHDRS)
MYWARNINGS      = 
MYDEFS          = -DNeXT_MOD
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		= -lstuff

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

ASTARGETS = ppc ppc64 i386 x86_64 arm

CFILES = driver.c
OBJS = $(CFILES:.c=.o)

.c.o:
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

.PHONY: default install clean distclean $(ASTARGETS)

default: driver $(ASTARGETS)

$(ASTARGETS):
	cd $@ && $(MAKE)

driver: $(OBJS)
	$(CC) -o $@ $^ $(MYLINKFLAGS)

install: driver install-arch
	mkdir -p $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) driver \
		$(DESTDIR)$(bindir)/`echo as | sed '$(transform)'`

install-arch:
	for ast in $(ASTARGETS); do				\
		(cd $${ast} && $(MAKE) install) || exit 1;	\
	done

clean:
	rm -r -f *.o
	rm -f driver
	for ast in $(ASTARGETS); do			\
		(cd $${ast} && $(MAKE) $@) || exit 1;	\
	done
