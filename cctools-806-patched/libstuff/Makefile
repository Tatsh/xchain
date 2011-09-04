builddir = .
top_builddir = ..
srcdir = .
top_srcdir = ..



CC		= gcc
AR		= ar
RANLIB		= ranlib
CFLAGS		= -w -m32 -fno-builtin-round -fno-builtin-trunc
WARNINGS	=  -Wall -Wno-long-double -Wno-import
MDYNAMICNOPIC	= 
CPPFLAGS	= -m32
DEFS		= -DHAVE_CONFIG_H -D__LITTLE_ENDIAN__=1
LDFLAGS		= -m32
HAVE_PRIVEXT	= NO
HAVE_FOREIGN_HEADERS	= YES

ifeq ($(HAVE_PRIVEXT),NO)
INCPRIVEXT	= -include $(top_srcdir)/include/extern.h
endif

ifeq ($(HAVE_FOREIGN_HEADERS),YES)
FORHDRS		= -I$(top_srcdir)/include/foreign
endif

MYINCLUDES	= -I$(top_builddir)/include -I$(top_srcdir)/include \
			$(INCPRIVEXT) $(FORHDRS)
MYWARNINGS	= 
MYDEFS		= 

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

CFILES = allocate.c errors.c arch.c execute.c bytesex.c rnd.c hppa.c		\
	  swap_headers.c reloc.c version_number.c get_toc_byte_sex.c		\
	  best_arch.c fatals.c arch_usage.c ofile.c ofile_error.c print.c	\
	  set_arch_flag_name.c seg_addr_table.c dylib_table.c			\
	  breakout.c writeout.c checkout.c fatal_arch.c ofile_get_word.c	\
	  hash_string.c dylib_roots.c guess_short_name.c			\
	  SymLoc.c get_arch_from_host.c crc32.c macosx_deployment_target.c	\
	  symbol_list.c unix_standard_mode.c emulated.c apple_version.c

OBJS = $(CFILES:.c=.o)
OBJS64 = $(CFILES:.c=.64o)


.PHONY: default install clean distclean

default: libstuff.a libstuff64.a

libstuff.a: $(OBJS)
	$(AR) cru $@ $^
	$(RANLIB) $@

libstuff64.a: $(OBJS64)
	$(AR) cru $@ $^
	$(RANLIB) $@

$(OBJS): %.o: %.c
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

$(OBJS64): %.64o: %.c
	$(CC) $(MYCOMPILEFLAGS)  -DARCH64 -c -o $@ $<

clean:
	rm -r -f *.o *.64o
	rm -f libstuff.a libstuff64.a

install:
