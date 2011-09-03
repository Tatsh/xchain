INFERIORS=ar as checksyms codesign_allocate indr install_name_tool ld libtool lipo nm nmedit \
	otool otool64 pagestuff ranlib redo_prebinding seg_addr_table segedit \
	seg_hack size strings strip
RESULTS=$(INFERIORS:%=arm-apple-darwin-%)

all:	$(RESULTS)

arm-apple-darwin-%:	valwrap.c
	gcc -Wall -DPROGRAM_TO_INVOKE=\"arm-apple-darwin-core-$*\" -D__USE_GNU -o $@ $^

install:
	for x in $(RESULTS); do install -c $$x /usr/local/bin/$$x; done

clean:
	rm -f $(RESULTS)	

.PHONY:	all install clean

