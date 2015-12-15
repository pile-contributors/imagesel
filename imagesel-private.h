/**
 * @file imagesel-private.h
 * @brief Declarations for ImageSel class
 * @author Nicu Tofan <nicu.tofan@gmail.com>
 * @copyright Copyright 2014 piles contributors. All rights reserved.
 * This file is released under the
 * [MIT License](http://opensource.org/licenses/mit-license.html)
 */

#ifndef GUARD_IMAGESEL_PRIVATE_H_INCLUDE
#define GUARD_IMAGESEL_PRIVATE_H_INCLUDE

#include <imagesel/imagesel-config.h>

#if 0
#    define IMAGESEL_DEBUGM printf
#else
#    define IMAGESEL_DEBUGM black_hole
#endif

#if 0
#    define IMAGESEL_TRACE_ENTRY printf("IMAGESEL ENTRY %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define IMAGESEL_TRACE_ENTRY
#endif

#if 0
#    define IMAGESEL_TRACE_EXIT printf("IMAGESEL EXIT %s in %s[%d]\n", __func__, __FILE__, __LINE__)
#else
#    define IMAGESEL_TRACE_EXIT
#endif


static inline void black_hole (...)
{}

#endif // GUARD_IMAGESEL_PRIVATE_H_INCLUDE
