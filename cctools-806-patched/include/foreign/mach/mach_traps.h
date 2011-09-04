#ifndef _MACH_MACH_TRAPS_H_
#define _MACH_MACH_TRAPS_H_

#include <mach/machine/vm_types.h>
#include <mach/boolean.h>

kern_return_t map_fd(
		     int fd,
		     vm_offset_t offset,
		     vm_offset_t *va,
		     boolean_t findspace,
		     vm_size_t size);


#endif
