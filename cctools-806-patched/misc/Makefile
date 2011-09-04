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
LDPROG		= $(shell echo ld | sed '$(transform)')
LD64PROG	= $(shell echo ld64 | sed '$(transform)')
LIPO            = $(shell echo lipo | sed '$(transform)')

MYINCLUDES      = -I$(builddir) -I$(srcdir) -I$(top_builddir)/include \
			-I$(top_srcdir)/include $(INCPRIVEXT) $(FORHDRS)
MYWARNINGS      = 
MYDEFS          = -DBINDIR="\"$(bindir)\"" -DLDPROG="\"$(LDPROG)\"" \
			-DLD64PROG="\"$(LD64PROG)\"" -DLIPO="\"$(LIPO)\""
MYLDFLAGS	= -L$(top_builddir)/libstuff
MYLIBS		= -lstuff

MYCOMPILEFLAGS	= $(WARNINGS) $(MYWARNINGS) $(DEFS) $(MYDEFS) \
	$(CPPFLAGS) $(MYINCLUDES) $(CFLAGS) $(MDYNAMICNOPIC) 

MYLINKFLAGS	= $(LDFLAGS) $(MYLDFLAGS) $(MYLIBS)

PROGRAMS = checksyms lipo size strings nm libtool redo_prebinding seg_addr_table \
		seg_hack install_name_tool indr strip nmedit segedit pagestuff \
		ranlib codesign_allocate

CFILES_checksyms	= checksyms.c
OBJS_checksyms	= $(CFILES_checksyms:.c=.o)

CFILES_lipo	= lipo.c
OBJS_lipo	= $(CFILES_lipo:.c=.o)

CFILES_size	= size.c
OBJS_size	= $(CFILES_size:.c=.o)

CFILES_strings	= strings.c
OBJS_strings	= $(CFILES_strings:.c=.o)

CFILES_nm	= nm.c
OBJS_nm		= $(CFILES_nm:.c=.o)

CFILES_libtool	= libtool.c
OBJS_libtool	= $(CFILES_libtool:.c=.o)

CFILES_ranlib	= libtool.c
OBJS_ranlib	= ranlib.o

CFILES_redo_prebinding	= redo_prebinding.o
OBJS_redo_prebinding	= $(CFILES_redo_prebinding:.c=.o)

CFILES_seg_addr_table	= seg_addr_table.c
OBJS_seg_addr_table	= $(CFILES_seg_addr_table:.c=.o)

CFILES_seg_hack	= seg_hack.c
OBJS_seg_hack	= $(CFILES_seg_hack:.c=.o)

CFILES_codesign_allocate	= codesign_allocate.c
OBJS_codesign_allocate		= $(CFILES_codesign_allocate:.c=.o)

CFILES_install_name_tool	= install_name_tool.c
OBJS_install_name_tool		= $(CFILES_install_name_tool:.c=.o)

CFILES_indr	= indr.c
OBJS_indr	= $(CFILES_indr:.c=.o)

CFILES_strip	= strip.c
OBJS_strip	= $(CFILES_strip:.c=.o)

CFILES_nmedit	= strip.c
OBJS_nmedit	= nmedit.o

CFILES_segedit	= segedit.c
OBJS_segedit	= $(CFILES_segedit:.c=.o)

CFILES_pagestuff	= pagestuff.c
OBJS_pagestuff	= $(CFILES_pagestuff:.c=.o)

.c.o:
	$(CC) $(MYCOMPILEFLAGS) -c -o $@ $<

.PHONY: default clean distclean install

default: $(PROGRAMS)

ranlib.o: libtool.c
	$(CC) -DRANLIB $(MYCOMPILEFLAGS) -c -o $@ $<

nmedit.o: strip.c
	$(CC) -DNMEDIT $(MYCOMPILEFLAGS) -c -o $@ $<

checksyms: $(OBJS_checksyms)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
lipo: $(OBJS_lipo)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
size: $(OBJS_size)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
strings: $(OBJS_strings)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
nm: $(OBJS_nm)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
libtool: $(OBJS_libtool)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
redo_prebinding: $(OBJS_redo_prebinding)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
seg_addr_table: $(OBJS_seg_addr_table)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
seg_hack: $(OBJS_seg_hack)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
codesign_allocate: $(OBJS_codesign_allocate)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
install_name_tool: $(OBJS_install_name_tool)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
indr: $(OBJS_indr)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
strip: $(OBJS_strip)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
nmedit: $(OBJS_nmedit)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
segedit: $(OBJS_segedit)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
pagestuff: $(OBJS_pagestuff)
	$(CC) -o $@ $^ $(MYLINKFLAGS)
ranlib: $(OBJS_ranlib)
	$(CC) -o $@ $^ $(MYLINKFLAGS)

install: $(PROGRAMS)
	mkdir -p $(DESTDIR)$(bindir)
	for p in $(PROGRAMS); do					\
		$(INSTALL_PROGRAM) $$p 					\
			$(DESTDIR)$(bindir)/`echo $$p | sed '$(transform)'`;	\
	done
clean:
	rm -r -f *.o
	rm -f $(PROGRAMS)
