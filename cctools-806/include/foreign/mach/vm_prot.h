#ifndef _MACH_VM_PROT_H_
#define _MACH_VM_PROT_H_

typedef int32_t             vm_prot_t;

#define VM_PROT_NONE    ((vm_prot_t) 0x00)

#define VM_PROT_READ    ((vm_prot_t) 0x01)      /* read permission */
#define VM_PROT_WRITE   ((vm_prot_t) 0x02)      /* write permission */
#define VM_PROT_EXECUTE ((vm_prot_t) 0x04)      /* execute permission */

#define VM_PROT_DEFAULT (VM_PROT_READ|VM_PROT_WRITE)
#define VM_PROT_ALL     (VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE)
#define VM_PROT_NO_CHANGE       ((vm_prot_t) 0x08)
#define VM_PROT_COPY            ((vm_prot_t) 0x10)
#define VM_PROT_WANTS_COPY      ((vm_prot_t) 0x10)


#endif
