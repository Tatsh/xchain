/* ----------------------------------------------------------------------------
 *   iphone-binutils: development tools for the Apple iPhone       07/12/2007
 *   Copyright (c) 2007 Patrick Walton <pcwalton@uchicago.edu> but freely
 *   redistributable under the terms of the GNU General Public License.
 *
 *   ld/arm_reloc.h: relocation for the ARM 
 * ------------------------------------------------------------------------- */

#ifndef ARM_RELOC_H
#define ARM_RELOC_H

#include <mach-o/reloc.h>
#include "ld.h"
#include "sections.h"

extern void arm_reloc(char *contents, struct relocation_info *
    relocs, struct section_map *section_map, struct live_refs *refs, unsigned
    long reloc_index);

#endif

