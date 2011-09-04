builddir = .
top_builddir = ..
srcdir = .
top_srcdir = ..
datarootdir = ${prefix}/share
prefix	= /home/tatsh/usr/i686-apple-darwin11
exec_prefix	= ${prefix}
mandir		= ${datarootdir}/man
includedir	= ${prefix}/include



INSTALL		= /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA	= ${INSTALL} -m 644
transform	= s&^&i686-apple-darwin11-&

MANPAGES1	= as.1 gprof.1 ld.1 nm.1 otool.1 ranlib.1 \
		segedit.1 size.1 strings.1 strip.1 lipo.1 \
		libtool.1 pagestuff.1 redo_prebinding.1 \
		nmedit.1 install_name_tool.1 checksyms.1 \
		seg_addr_table.1 ld64.1 codesign_allocate.1

MANPAGES3	= arch.3

MANPAGES5	= Mach-O.5 a.out.5 ranlib.5 stab.5

.PHONY: default install clean distclean

default:

install: 
	mkdir -p $(DESTDIR)$(mandir)
	mkdir -p $(DESTDIR)$(mandir)/man1
	mkdir -p $(DESTDIR)$(mandir)/man3
	mkdir -p $(DESTDIR)$(mandir)/man5
	for m in $(MANPAGES1); do				\
		$(INSTALL_DATA) $(srcdir)/$$m			\
			$(DESTDIR)$(mandir)/man1/`echo "$$m" | sed -e '$(transform)'`;		\
	done
	for m in $(MANPAGES3); do				\
		$(INSTALL_DATA) $(srcdir)/$$m			\
			$(DESTDIR)$(mandir)/man3/`echo "$$m" | sed -e '$(transform)'`;		\
	done
	for m in $(MANPAGES5); do				\
		$(INSTALL_DATA) $(srcdir)/$$m			\
			$(DESTDIR)$(mandir)/man5/`echo "$$m" | sed -e '$(transform)'`;		\
	done


clean:
