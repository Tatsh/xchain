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
OBJC		= -x objective-c
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

MYINCLUDES      = -I$(builddir) -I$(srcdir) -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) $(FORHDRS)
MYWARNINGS      = 
MYDEFS          = 
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		=

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

CFILES = main.c ofile_print.c m68k_disasm.c i860_disasm.c \
         m88k_disasm.c i386_disasm.c ppc_disasm.c hppa_disasm.c \
         sparc_disasm.c arm_disasm.c
MFILES = print_objc.c print_objc2_32bit.c print_objc2_64bit.c

OBJS = $(CFILES:.c=.o)
OBJS64 = $(CFILES:.c=.64o)

MOBJS = $(MFILES:.c=.o)
MOBJS64 = $(MFILES:.c=.64o)

.PHONY: default clean distclean install

default: otool otool64

$(OBJS): %.o: %.c
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

$(OBJS64): %.64o: %.c
	$(CC) $(MYCOMPILEFLAGS) -DARCH64 -c -o $@ $<

otool: $(OBJS) ofile.o $(MOBJS)
	$(CC) -o $@ $^ $(MYLINKFLAGS) -lstuff

otool64: $(OBJS64) ofile.64o $(MOBJS64)
	$(CC) -o $@ $^ $(MYLINKFLAGS) -lstuff64

ofile.o: $(top_srcdir)/libstuff/ofile.c
	$(CC) -DOTOOL $(MYCOMPILEFLAGS) -c -o $@ $<
ofile.64o: $(top_srcdir)/libstuff/ofile.c
	$(CC) -DOTOOL $(MYCOMPILEFLAGS) -DARCH64 -c -o $@ $<

$(MOBJS): %.o: %.c
	$(CC) $(OBJC) $(MYCOMPILEFLAGS) -c -o $@ $<
$(MOBJS64): %.64o: %.c
	$(CC) $(OBJC) $(MYCOMPILEFLAGS) -DARCH64 -c -o $@ $<

install: otool otool64
	mkdir -p $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) otool \
		$(DESTDIR)$(bindir)/`echo otool | sed '$(transform)'`
	$(INSTALL_PROGRAM) otool64 \
		$(DESTDIR)$(bindir)/`echo otool64 | sed '$(transform)'`

clean:
	rm -r -f *.o *.64o
	rm -f otool otool64
