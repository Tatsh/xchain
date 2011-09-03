builddir = .
top_builddir = ..
srcdir = .
top_srcdir = ..

prefix	= /usr/local
exec_prefix	= ${prefix}
bindir		= ${exec_prefix}/bin
mandir		= ${prefix}/share/man



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
INSTALL_DATA	= ${INSTALL} -m 644
transform	= s&^&i686-apple-darwin11-&
RANLIBPROG      = $(shell echo ranlib | sed '$(transform)')

MYINCLUDES      = -I$(srcdir) -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) $(FORHDRS)
MYWARNINGS      =
MYDEFS          = -DBINDIR="\"$(bindir)\"" -DRANLIBPROG="\"$(RANLIBPROG)\""
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		= -lstuff

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 
	
MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

CFILES = append.c ar.c archive.c contents.c delete.c extract.c misc.c \
	move.c print.c replace.c 
OBJS = $(CFILES:.c=.o)

.c.o:
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

.PHONY: default install clean distclean

default: ar

ar: $(OBJS)
	$(CC) -o $@ $^ $(MYLINKFLAGS)

install: ar
	mkdir -p $(DESTDIR)$(bindir)
	mkdir -p $(DESTDIR)$(mandir)/man1
	mkdir -p $(DESTDIR)$(mandir)/man5
	$(INSTALL_PROGRAM) ar \
		$(DESTDIR)$(bindir)/`echo ar | sed '$(transform)'`
	$(INSTALL_DATA) $(srcdir)/ar.1 $(DESTDIR)$(mandir)/man1/`echo ar.1 | sed '$(transform)'`
	$(INSTALL_DATA) $(srcdir)/ar.5 $(DESTDIR)$(mandir)/man5/`echo ar.5 | sed '$(transform)'`


clean:
	rm -r -f *.o
	rm -f ar
