#ifndef _MACH_MACHINE_VM_TYPES_H_
#define _MACH_MACHINE_VM_TYPES_H_

#include <stdint.h>

typedef uint32_t        natural_t;
typedef int32_t         integer_t;

typedef natural_t       vm_offset_t;
typedef natural_t       vm_size_t;

typedef uint64_t        mach_vm_address_t;
typedef uint64_t        mach_vm_offset_t;
typedef uint64_t        mach_vm_size_t;

typedef vm_offset_t             pointer_t;
typedef vm_offset_t             vm_address_t;



#endif
