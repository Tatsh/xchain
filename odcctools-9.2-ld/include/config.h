/* include/config.h.  Generated from config.h.in by configure.  */
/* include/config.h.in.  Generated from configure.ac by autoheader.  */

/* filesystem root of cross build environment */
/* #undef CROSS_SYSROOT */

/* Default Mach architecture name */
#define DEFAULT_MACH_ARCH "i386"

/* Emulated CPU subtype */
#define EMULATED_HOST_CPU_SUBTYPE 3

/* Emulated CPU type */
#define EMULATED_HOST_CPU_TYPE 7

/* Define to 1 if you have the declaration of `getc_unlocked', and to 0 if you
   don't. */
#define HAVE_DECL_GETC_UNLOCKED 1

/* For systems that don't have getc_unlocked, use getc  */
#if !HAVE_DECL_GETC_UNLOCKED
# define getc_unlocked(a) getc(a)
#endif

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the `getattrlist' function. */
/* #undef HAVE_GETATTRLIST */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `NSIsSymbolNameDefined' function. */
/* #undef HAVE_NSISSYMBOLNAMEDEFINED */

/* Have Objective-C support */
#define HAVE_OBJC 1

/* Define to 1 if you have the <objc/objc-runtime.h> header file. */
/* #undef HAVE_OBJC_OBJC_RUNTIME_H */

/* Define to 1 if you have the `qsort' function. */
#define HAVE_QSORT 1

/* Define to 1 if you have the `qsort_r' function. */
#define HAVE_QSORT_R 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if you have the `strmode' function. */
/* #undef HAVE_STRMODE */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "odcctools@opendarwin.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "odcctools"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "odcctools 622.3od16"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "odcctools"

/* Define to the version of this package. */
#define PACKAGE_VERSION "622.3od16"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* max unsigned long long */
/* #undef ULLONG_MAX */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1
