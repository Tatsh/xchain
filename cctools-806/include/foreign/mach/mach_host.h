#ifndef _mach_host_user_
#define _mach_host_user_

#include <mach/host_info.h>
#include <mach/mach_types.h>

kern_return_t host_info
(
 host_t host,
 host_flavor_t flavor,
 host_info_t host_info_out,
 mach_msg_type_number_t *host_info_outCnt
 );


#endif
