#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([cctools], [806], [ddrtist@gmail.com])
AC_CONFIG_SRCDIR([APPLE_LICENSE])
AC_CONFIG_HEADERS([include/config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_PROG_LEX
AC_PROG_YACC

AC_ARG_PROGRAM

case $target_os in
darwin*)
	:
	;;
*)
	AC_MSG_ERROR([$PACKAGE_NAME only supports targeting Darwin])
	;;
esac

case $target_cpu in
     arm)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 12, [Emulated CPU type])        
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 6, [Emulated CPU subtype])
        AC_DEFINE(DEFAULT_MACH_ARCH, "arm", [Default Mach architecture name])
	;;
     powerpc)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 18, [Emulated CPU type])        
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 100, [Emulated CPU subtype]) 
        AC_DEFINE(DEFAULT_MACH_ARCH, "ppc", [Default Mach architecture name])
	;;
     powerpc64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777234, [Emulated CPU type])        
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])        
        AC_DEFINE(DEFAULT_MACH_ARCH, "ppc64", [Default Mach architecture name])
	;;
     i?86)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 7, [Emulated CPU type])        
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 3, [Emulated CPU subtype])        
        AC_DEFINE(DEFAULT_MACH_ARCH, "i386", [Default Mach architecture name])
	;;
     x86_64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777223, [Emulated CPU type])        
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 3, [Emulated CPU subtype])        
        AC_DEFINE(DEFAULT_MACH_ARCH, "x86_64", [Default Mach architecture name])
	;;
     *)
	AC_MSG_ERROR([Unsupported target $target_cpu])
	;;
esac

# Checks for programs.
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_CC
AC_PROG_CXX

AC_CHECK_TOOL([HOST_RANLIB], [ranlib], :)
AC_CHECK_TOOL([HOST_AR], [ar], :)

ASTARGETS=""
conftargets=""
AC_MSG_CHECKING([for configured assembler targets])
AC_ARG_ENABLE([as-targets],
		AC_HELP_STRING([--enable-as-targets],
				[space-separated list ("arm", "ppc", "ppc64", "i386", "x86_64", "all")]),
		[conftargets="$enableval"],
		[conftargets="default"])

case "$conftargets" in
     all)
        ASTARGETS="ppc ppc64 i386 x86_64 arm"
	;;
     default)
	ASTARGETS="ppc ppc64 i386 x86_64 arm"
	;;
     yes)
	AC_MSG_ERROR([no assembler targets configured])
	;;
     no)
	AC_MSG_ERROR([no assembler targets configured])
	;;
     *)
	if [[ -z "$conftargets" ]]; then
	   AC_MSG_ERROR([no assembler targets configured])
	fi
	ASTARGETS="$conftargets"
	;;
esac

AC_MSG_RESULT([$ASTARGETS])
AC_SUBST([ASTARGETS], [$ASTARGETS]) 

AC_ARG_WITH([sysroot],
		AC_HELP_STRING([--with-sysroot],
				[filesystem root of cross build environment]),
		[AC_DEFINE_UNQUOTED([CROSS_SYSROOT],["$withval"],[filesystem root of cross build environment])])

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -mdynamic-no-pic"
AC_MSG_CHECKING([if -mdynamic-no-pic is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [AC_SUBST([MDYNAMICNOPIC],[-mdynamic-no-pic])
    AC_MSG_RESULT([yes])],
   [AC_SUBST([MDYNAMICNOPIC],[])
    AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -fno-builtin-round"
AC_MSG_CHECKING([if -fno-builtin-round is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [AC_MSG_RESULT([yes])],
   [CFLAGS=$ORIGCFLAGS
    AC_MSG_RESULT([no])]
)

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -fno-builtin-trunc"
AC_MSG_CHECKING([if -fno-builtin-trunc is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [AC_MSG_RESULT([yes])],
   [CFLAGS=$ORIGCFLAGS
    AC_MSG_RESULT([no])]
)

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -no-cpp-precomp"
supported=0
AC_MSG_CHECKING([if -no-cpp-precomp is supported])
AC_LANG_CONFTEST([[const char hw[] = "Hello, World\n";]])
rm -f conftest.$ac_objext conftest$ac_exeext
out=`$CC -c $CFLAGS $CPPFLAGS conftest.$ac_ext 2>&1`
if [[ $? -ne 0 ]]; then
   supported=0;
else
   unrecog=`echo $out | grep unrecog | wc -l`
   if [[ $unrecog -gt 0 ]]; then
      supported=0;
   else
      supported=1;
   fi
fi

if [[ $supported -eq 1 ]]; then
   AC_MSG_RESULT([yes])
else
   CFLAGS="$ORIGCFLAGS"
   AC_MSG_RESULT([no])
fi
rm -f conftest.$ac_objext conftest$ac_exeext conftest.$ac_ext

WARNINGS=""

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wall"
AC_MSG_CHECKING([if -Wall is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wall"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-long-double"
AC_MSG_CHECKING([if -Wno-long-double is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";
		   void* should_warn = 5;
		   ]])],
   [WARNINGS="$WARNINGS -Wno-long-double"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-import"
AC_MSG_CHECKING([if -Wno-import is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";
		   void* should_warn = 5;
		   ]])],
   [WARNINGS="$WARNINGS -Wno-import"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

AC_SUBST([WARNINGS], [$WARNINGS])

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -x objective-c"
OBJC="-x objective-c"
AC_MSG_CHECKING([if -x objective-c is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[@class foo;
void bar(void) {
     [foo alloc];
}
]])],
   [AC_DEFINE(HAVE_OBJC, 1, [Have Objective-C support])
    AC_MSG_RESULT([yes])],
   [OBJC=""
    AC_MSG_RESULT([no])]
)
AC_SUBST([OBJC], [$OBJC])
CFLAGS=$ORIGCFLAGS

AC_MSG_CHECKING([if __private_extern__ is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[__private_extern__ int foo;]])],
   [AC_SUBST([HAVE_PRIVEXT], [YES])
    AC_MSG_RESULT([yes])],
   [AC_SUBST([HAVE_PRIVEXT], [NO])
    AC_MSG_RESULT([no])]
)

ORIGLDFLAGS=$LDFLAGS
LDFLAGS="-multiply_defined suppress"
AC_MSG_CHECKING([if -multiply_defined suppress is supported])
AC_LINK_IFELSE([AC_LANG_PROGRAM()],
	[AC_MSG_RESULT([yes])],
	[LDFLAGS="$ORIGLDFLAGS"
	 AC_MSG_RESULT([no])]
)

AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h errno.h limits.h])
if [[ "x$OBJC" != "x" ]]; then
   ORIGCFLAGS=$CFLAGS
   CFLAGS="$CFLAGS $OBJC"
   AC_CHECK_HEADERS([objc/objc-runtime.h])
   CFLAGS="$ORIGCFLAGS"
fi

AC_MSG_CHECKING([for max unsigned long long])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[#if HAVE_LIMITS_H
			 #include <limits.h>
		     #endif
		     unsigned long long a = ULLONG_MAX;]])],
   [AC_MSG_RESULT([ULLONG_MAX])],
   [AC_COMPILE_IFELSE(
	[AC_LANG_SOURCE([[#if HAVE_LIMITS_H
			      #include <limits.h>
			 #endif
			 unsigned long long a = 18446744073709551615ULL;]])],
	[AC_DEFINE(ULLONG_MAX, [18446744073709551615ULL], [max unsigned long long])
	 AC_MSG_RESULT([18446744073709551615ULL])],
	[AC_MSG_RESULT([none]) ]
	)
    ]
)

AC_CHECK_FUNCS([atexit bzero fchdir ftruncate getattrlist getpagesize gettimeofday memchr memmove memset NSIsSymbolNameDefined qsort_r qsort realpath sqrt strcasecmp strchr strdup strerror strlcat strmode strncasecmp strrchr strstr strtol strtoul utime])

AC_CHECK_DECLS([getc_unlocked])
AH_VERBATIM([HAVE_DECL_GETC_UNLOCKED_REPLACEMENT],
[/* For systems that don't have getc_unlocked, use getc  */
#if !HAVE_DECL_GETC_UNLOCKED
# define getc_unlocked(a) getc(a)
#endif])

case $host_os in
     darwin*)
	AC_SUBST([HAVE_FOREIGN_HEADERS],[NO])
	;;
     *)
	AC_SUBST([HAVE_FOREIGN_HEADERS],[YES])
	AC_SUBST([EMULATED_OBJ], [emulated.c])
	AC_C_BIGENDIAN([AC_SUBST([ENDIAN_FLAG],[-D__BIG_ENDIAN__=1])],
			[AC_SUBST([ENDIAN_FLAG],[-D__LITTLE_ENDIAN__=1])])
	;;
esac

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_FUNC_OBSTACK
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_CHOWN
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC

# Remove otool if you do not have an Objective-C++ compiler
COMPONENTS="ar as include libstuff libmacho ld man misc otool"
AC_SUBST([COMPONENTS], [$COMPONENTS])

AC_CONFIG_FILES([Makefile include/Makefile libstuff/Makefile libmacho/Makefile])
AC_CONFIG_FILES([ar/Makefile])
AC_CONFIG_FILES([as/Makefile])
for ast in $ASTARGETS; do
    case $ast in
    ppc)
	AC_CONFIG_FILES([as/ppc/Makefile:as/ppc/Makefile.in:as/Makefile.arch.in])
	;;
    ppc64)
	AC_CONFIG_FILES([as/ppc64/Makefile:as/ppc64/Makefile.in:as/Makefile.arch.in])
	;;
    i386)
	AC_CONFIG_FILES([as/i386/Makefile:as/i386/Makefile.in:as/Makefile.arch.in])
	;;
    x86_64)
	AC_CONFIG_FILES([as/x86_64/Makefile:as/x86_64/Makefile.in:as/Makefile.arch.in])
    ;;
    arm)
	AC_CONFIG_FILES([as/arm/Makefile:as/arm/Makefile.in:as/Makefile.arch.in])
	;;
    *)
	AC_MSG_ERROR([Unrecognized assembler target $ast])
	;;
    esac
done
AC_CONFIG_FILES([ld/Makefile])
AC_CONFIG_FILES([man/Makefile])
AC_CONFIG_FILES([misc/Makefile])
AC_CONFIG_FILES([otool/Makefile])

AC_OUTPUT
