# stuff to include in every test Makefile

SHELL = /bin/sh

# set default to be host
ARCH ?= $(shell arch)

# set default to be all
VALID_ARCHS ?= "ppc ppc64 i386"

# if run within Xcode, add the just built tools to the command path
ifdef BUILT_PRODUCTS_DIR
	PATH := ${BUILT_PRODUCTS_DIR}:${PATH}
endif

LD			= ld
OBJECTDUMP	= ObjectDump
MACHOCHECK	= machocheck

OTOOL = otool
ifeq (${ARCH},ppc64)
OTOOL = otool64
endif
ifeq (${ARCH},x86_64)
OTOOL = otool64
endif


CC		 = gcc-4.0 -arch ${ARCH}
CCFLAGS = -Wall -std=c99
ASMFLAGS =

CXX		  = g++-4.0 -arch ${ARCH}
CXXFLAGS = -Wall

RM      = rm
RMFLAGS = -rf

# utilites for Makefiles
PASS_IFF			= ${TESTROOT}/bin/pass-iff-exit-zero.pl
PASS_IFF_EMPTY		= ${TESTROOT}/bin/pass-iff-no-stdin.pl
PASS_IFF_STDIN		= ${TESTROOT}/bin/pass-iff-stdin.pl
PASS_IFF_GOOD_MACHO	= ${TESTROOT}/bin/pass-iff-exit-zero.pl ${MACHOCHECK}
FAIL_IFF			= ${TESTROOT}/bin/fail-iff-exit-zero.pl
FAIL_IF_BAD_MACHO	= ${TESTROOT}/bin/fail-if-exit-non-zero.pl ${MACHOCHECK}
FAIL_IF_SUCCESS         = ${TESTROOT}/bin/fail-if-exit-zero.pl
FAIL_IF_EMPTY		= ${TESTROOT}/bin/fail-if-no-stdin.pl
FAIL_IF_STDIN		= ${TESTROOT}/bin/fail-if-stdin.pl
