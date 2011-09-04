#ifndef _AR_H_
#define _AR_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include <sys/types.h>

#define ARMAG           "!<arch>\n"     /* ar "magic number" */
#define SARMAG          8               /* strlen(ARMAG); */

#define AR_EFMT1        "#1/"           /* extended format #1 */

struct ar_hdr {
  char ar_name[16];               /* name */
  char ar_date[12];               /* modification time */
  char ar_uid[6];                 /* user id */
  char ar_gid[6];                 /* group id */
  char ar_mode[8];                /* octal file permissions */
  char ar_size[10];               /* size in bytes */
#define ARFMAG  "`\n"
  char ar_fmag[2];                /* consistency check */
};

#ifndef HAVE_STRMODE
void strmode(mode_t mode, char *bp);
#endif

#endif /* !_AR_H_ */
