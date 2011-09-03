#ifndef _STUFF_SYMBOL_H_
#define _STUFF_SYMBOL_H_

#include "stuff/target_arch.h"
#include <mach-o/nlist.h>

struct symbol {
    char *name;
    char *indr_name;
    uint64_t n_value;
    int is_thumb;
};

#endif /* _STUFF_SYMBOL_H_ */
