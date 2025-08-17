/* /////////////////////////////////////////////////////////////////////////
 * File:    diagnosticm/diagnosticm.h
 *
 * Purpose: Main header file for Diagnosticm (C-API).
 *
 * Created: 11th August 2025
 * Updated: 17th August 2025
 *
 * Home:    https://github.com/synesissoftware/2be/
 *
 * Copyright (c) 2025, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer;
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution;
 * - Neither the name of the copyright holder nor the names of its
 *   ontributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file 2be/2be.h
 *
 * [C, C++] Main header file for 2be (C-API).
 */

#ifndef TWOB_INCL_TWOB_H_DIAGNOSTICISM
#define TWOB_INCL_TWOB_H_DIAGNOSTICISM

#ifndef TWOB_DOCUMENTATION_SKIP_SECTION
# define TWOB_VER_TWOB_H_TWOB_MAJOR  0
# define TWOB_VER_TWOB_H_TWOB_MINOR  0
# define TWOB_VER_TWOB_H_TWOB_PATCH  8
# define TWOB_VER_TWOB_H_TWOB_EDIT   9
#endif /* !TWOB_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

/**
 * \def TWOB_VER_MAJOR
 *
 * The Major version number of the 2be library
 *
 * \def TWOB_VER_MINOR
 *
 * Minor version number of the 2be library
 *
 * \def TWOB_VER_PATCH
 *
 * The patch number of the 2be library
 *
 * \def TWOB_VER
 *
 * The composite version of the 2be library
 */

#define TWOB_VER_MAJOR          0
#define TWOB_VER_MINOR          0
#define TWOB_VER_PATCH          3
#define TWOB_VER_ALPHABETA      0x41

#define TWOB_VER \
    (0\
        |   (   TWOB_VER_MAJOR       << 24   ) \
        |   (   TWOB_VER_MINOR       << 16   ) \
        |   (   TWOB_VER_PATCH       <<  8   ) \
        |   (   TWOB_VER_ALPHABETA   <<  0   ) \
    )


/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <stdint.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def TWOB_CALL(rc)
 *
 * T.B.C.
 */
#ifndef TWOB_CALL
# ifdef __cplusplus
#  define TWOB_CALL(rt)                                     extern "C" rt
# else
#  define TWOB_CALL(rt)                                     rt
# endif
#endif

#if 0
#elif defined(STLSOFT_NOEXCEPT)
# define TWOB_NOEXCEPT                                      STLSOFT_NOEXCEPT
#else
# if 0
# elif defined(__cplusplus)
#  if 0
#  elif __cplusplus >= 201103L
#   define TWOB_NOEXCEPT                                    noexcept
#  else
#   define TWOB_NOEXCEPT                                    throw()
#  endif
# else
#  define TWOB_NOEXCEPT
# endif
#endif


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef uint32_t                                            twob_uint32_t;



/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Obtains the Diagnosticism version (at time of compilation)
 *
 * @note Can be called without having initialised the API.
 *
 * @see twob_api_init.
 */
TWOB_CALL(twob_uint32_t)
twob_api_version(void) TWOB_NOEXCEPT;



/** Initialises the API.
 *
 */
TWOB_CALL(int)
twob_api_init(
    twob_uint32_t   init_flags
,   void*           init_param
) TWOB_NOEXCEPT;

/** Uninitialises the API.
 *
 */
TWOB_CALL(void)
twob_api_uninit(void) TWOB_NOEXCEPT;

/** Indicates that the given string, when trimmed, is classified as "truthy"
 * and is deemed as "falsey".
 */
TWOB_CALL(int)
twob_string_is_falsey(
    char const* s
) TWOB_NOEXCEPT;

/** Indicates that the given string, when trimmed, is classified as "truthy"
 * and is deemed as "truey".
 */
TWOB_CALL(int)
twob_string_is_truey(
    char const* s
) TWOB_NOEXCEPT;

/** Indicates that the given string, when trimmed, is classified as "truthy"
 * (and is deemed as either "falsey" or "truey").
 */
TWOB_CALL(int)
twob_string_is_truthy(
    char const* s
) TWOB_NOEXCEPT;


/* /////////////////////////////////////////////////////////////////////////
 * API functions (C++)
 */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !TWOB_INCL_TWOB_H_DIAGNOSTICISM */

/* ///////////////////////////// end of file //////////////////////////// */
