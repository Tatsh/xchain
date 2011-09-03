ARCH    =   arm

CFILES_arm =	arm.c
MYDEFS_arm =	-DARM
MYLIBS_arm =	-lstuff

VPATH=/arm

all:	default

.PHONY:	all
builddir = .
top_builddir = ../..
srcdir = .
top_srcdir = ../..

prefix	= /usr/local
exec_prefix	= ${prefix}
libexecdir	= ${exec_prefix}/libexec

VPATH = ./..

CC              = gcc
WARNINGS	=  -Wall -Wno-long-double -Wno-import
CFLAGS          = -g -O2 -fno-builtin-round -fno-builtin-trunc
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
         symbols.c write_object.c xmalloc.c $(CFILES_$(ARCH))

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
