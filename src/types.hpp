#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;
typedef volatile f32 vf32;
typedef volatile f64 vf64;

#ifdef __cplusplus
static_assert(sizeof(s8) == 1 && sizeof(u8) == 1, "8 bit number isn't 1 byte big");
static_assert(sizeof(s16) == 2 && sizeof(u16) == 2, "16 bit number isn't 2 bytes big");
static_assert(sizeof(s32) == 4 && sizeof(u32) == 4, "32 bit number isn't 4 bytes big");
static_assert(sizeof(s64) == 8 && sizeof(u64) == 8, "64 bit number isn't 8 bytes big");
static_assert(sizeof(f32) == 4, "32 bit floating point number isn't 4 bytes big");
static_assert(sizeof(f64) == 8, "64 bit floating point number isn't 8 bytes big");
#endif