#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char            uint8_t;
typedef signed char              sint8_t;
typedef unsigned short          uint16_t;
typedef signed short            sint16_t;
typedef unsigned int            uint32_t;
typedef signed int              sint32_t;
typedef unsigned long long int  uint64_t;
typedef signed long long int    sint64_t;
typedef float                  float32_t;
typedef double                 float64_t;

#define ZERO 0

typedef uint8_t Std_ReturnType;

#define E_OK       		 (Std_ReturnType)(0x01)
#define E_NOT_OK  		 (Std_ReturnType)(0x02)
/*
#define LIST_EMPTY       (Std_ReturnType)(0x03)
#define LIST_NOT_EMPTY   (Std_ReturnType)(0x04)
*/
#endif