/* /////////////////////////////////////////////////////////////////////////
 * File:    src/2be.c
 *
 * Purpose: Primary implementation file for 2be core library.
 *
 * Created: 11th August 2025
 * Updated: 11th August 2025
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


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <2be/2be.h>


/* /////////////////////////////////////////////////////////////////////////
 * function declarations
 */

TWOB_CALL(int)
twob_truthy_init(
    twob_uint32_t   init_flags
,   void*           init_param
) TWOB_NOEXCEPT;

TWOB_CALL(void)
twob_truthy_uninit(void) TWOB_NOEXCEPT;


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * global state
 */


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

TWOB_CALL(twob_uint32_t)
twob_api_version(void) TWOB_NOEXCEPT
{
    return TWOB_VER;
}


TWOB_CALL(int)
twob_api_init(
    twob_uint32_t   init_flags
,   void*           init_param
) TWOB_NOEXCEPT
{
    int const r_truthy = twob_truthy_init(init_flags, init_param);

    if (0 != r_truthy)
    {
        return r_truthy;
    }

    return 0;
}

TWOB_CALL(void)
twob_api_uninit(void) TWOB_NOEXCEPT
{
    twob_truthy_uninit();
}


/* ///////////////////////////// end of file //////////////////////////// */
