#ifndef STRLCPY_H
#define STRLCPY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"

#ifndef HAVE_STRLCPY
size_t strlcpy(char *dst, const char *src, size_t siz);
#endif

#ifdef __cplusplus
}
#endif

#endif

