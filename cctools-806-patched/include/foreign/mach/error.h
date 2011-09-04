#ifndef _ERROR_H
#define _ERROR_H

#include <mach/kern_return.h>

#define err_none                (mach_error_t)0
#define ERR_SUCCESS             (mach_error_t)0
#define ERR_ROUTINE_NIL         (mach_error_fn_t)0

#define err_system(x)           (((x)&0x3f)<<26)
#define err_sub(x)              (((x)&0xfff)<<14)

#define err_get_system(err)     (((err)>>26)&0x3f)
#define err_get_sub(err)        (((err)>>14)&0xfff)
#define err_get_code(err)       ((err)&0x3fff)

#define system_emask            (err_system(0x3f))
#define sub_emask               (err_sub(0xfff))
#define code_emask              (0x3fff)


typedef kern_return_t   mach_error_t;


#endif
