builddir = .
top_builddir = ..
srcdir = .
top_srcdir = ..

prefix		= /home/tatsh/usr/i686-apple-darwin11
exec_prefix	= ${prefix}
bindir		= ${exec_prefix}/bin



CC              = gcc
CFLAGS          = -w -m32 -fno-builtin-round -fno-builtin-trunc
WARNINGS	=  -Wall -Wno-long-double -Wno-import
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
transform       = s&^&i686-apple-darwin11-&
LD64PROG	= $(shell echo ld64 | sed '$(transform)')

MYINCLUDES      = -I$(builddir) -I$(srcdir) -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) $(FORHDRS)
MYWARNINGS      = 
MYDEFS          = -DDEBUG -DBINDIR="\"$(bindir)\"" -DLD64PROG="\"$(LD64PROG)\""
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		= -lstuff -luuid

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

CFILES = ld.c pass1.c objects.c sections.c cstring_literals.c symbols.c \
         fvmlibs.c layout.c specs.c pass2.c generic_reloc.c rld.c sets.c \
         4byte_literals.c 8byte_literals.c literal_pointers.c dylibs.c \
         indirect_sections.c mod_sections.c i860_reloc.c ppc_reloc.c \
         m88k_reloc.c hppa_reloc.c sparc_reloc.c coalesced_sections.c uuid.c \
	 debugcompunit.c debugline.c arm_reloc.c

OBJS = $(CFILES:.c=.o) 
.c.o:
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

.PHONY: default clean distclean install

default: ld

ld: $(OBJS)
	$(CC) -o $@ $^ $(MYLINKFLAGS)

install: ld
	mkdir -p $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) ld \
		$(DESTDIR)$(bindir)/`echo ld | sed '$(transform)'`

clean:
	rm -r -f *.o
	rm -f ld
