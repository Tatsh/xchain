ARCH	=	ppc64

CFILES_ppc64	=	ppc.c
MYDEFS_ppc64	=	-DPPC -DARCH64
MYLIBS_ppc64	=	-lstuff64
builddir = .
top_builddir = ../..
srcdir = .
top_srcdir = ../..

prefix	= /home/tatsh/usr/i686-apple-darwin11
exec_prefix	= ${prefix}
libexecdir	= ${exec_prefix}/libexec

VPATH = ./..

CC              = gcc
WARNINGS	=  -Wall -Wno-long-double -Wno-import
CFLAGS          = -w -m32 -fno-builtin-round -fno-builtin-trunc
MDYNAMICNOPIC   = 
CPPFLAGS        = -m32
DEFS            = -DHAVE_CONFIG_H -D__LITTLE_ENDIAN__=1
LDFLAGS         = -m32
HAVE_PRIVEXT    = NO
HAVE_FOREIGN_HEADERS    = YES

ifeq ($(HAVE_PRIVEXT),NO)
INCPRIVEXT      = -include $(top_srcdir)/include/extern.h
endif

ifeq ($(HAVE_FOREIGN_HEADERS),YES)
FORHDRS         = -I$(top_srcdir)/include/foreign
endif

INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM	= ${INSTALL}

MYINCLUDES      = -I$(builddir) -I$(srcdir)/.. -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) $(FORHDRS)
MYWARNINGS      =
MYDEFS          = -DNeXT_MOD $(MYDEFS_$(ARCH))
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		= $(MYLIBS_$(ARCH))

MYCOMPILEFLAGS  = $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

CFILES = app.c as.c atof-generic.c atof-ieee.c expr.c fixes.c flonum-const.c \
         flonum-copy.c flonum-mult.c frags.c hash.c hex-value.c input-file.c \
         input-scrub.c layout.c messages.c obstack.c read.c sections.c \
         symbols.c write_object.c xmalloc.c dwarf2dbg.c $(CFILES_$(ARCH))

OBJS = $(CFILES:.c=.o) 

%.o:	%.c
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

.PHONY: default clean distclean install

default: as

as: $(OBJS)
	$(CC) -o $@ $^ $(MYLINKFLAGS)

install: as
	mkdir -p $(DESTDIR)$(libexecdir)/gcc/darwin/$(ARCH)
	$(INSTALL_PROGRAM) as $(DESTDIR)$(libexecdir)/gcc/darwin/$(ARCH)/as

clean::
	rm -r -f *.o
	rm -f as
