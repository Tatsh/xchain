#ifndef _MACH_INIT_
#define _MACH_INIT_

#include <mach/mach_types.h>

extern  mach_port_t     mach_task_self_;

extern mach_port_t mach_task_self(void);
extern mach_port_t mach_host_self(void);
extern mach_port_t mach_thread_self(void);

#define mach_task_self() mach_task_self_

#define current_task()  mach_task_self()

extern    vm_size_t       vm_page_size;

kern_return_t mach_port_deallocate
(
 ipc_space_t task,
 mach_port_name_t name
 );


#endif
