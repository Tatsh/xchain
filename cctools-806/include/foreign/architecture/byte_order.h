#ifndef _ARCHITECTURE_BYTE_ORDER_H_
#define _ARCHITECTURE_BYTE_ORDER_H_

#include <stdint.h>

#include <libkern/OSByteOrder.h>

static __inline__
unsigned short 
NXSwapShort(
    unsigned short x
    )
{
  return ((((uint16_t)(x) & 0xff00) >> 8) | \
   (((uint16_t)(x) & 0x00ff) << 8));
}

static __inline__
unsigned int
NXSwapInt(
    unsigned int x
    )
{
  return ((((uint32_t)(x) & 0xff000000) >> 24) | \
	  (((uint32_t)(x) & 0x00ff0000) >>  8) | \
	  (((uint32_t)(x) & 0x0000ff00) <<  8) | \
	  (((uint32_t)(x) & 0x000000ff) << 24));
}

static __inline__
unsigned long
NXSwapLong(
    unsigned long inv
    )
{
  return (long)NXSwapInt((int)inv);
}

enum NXByteOrder {
  NX_UnknownByteOrder,
  NX_LittleEndian,
    NX_BigEndian
};


#endif
