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

#include <assert.h>
#include <ctype.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define DIMENSION_OF_(ar)                                   (sizeof((ar)) / sizeof((ar)[0]))

#define SLICE_FROM_LITERAL_(s)                              { DIMENSION_OF_(s) - 1, s }


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct twob_truthy_slice_m_t
{
    size_t      n;
    char const* s;
};
#define SLICE_T_                                            struct twob_truthy_slice_m_t

typedef int (*twob_truthy_cmp_fn_t)(
    const void  *lhs
,   const void  *rhs
) TWOB_NOEXCEPT;


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

static
SLICE_T_
slice_from_s_(
    char const* s
) TWOB_NOEXCEPT
{
    if (NULL == s)
    {
        SLICE_T_ slice = { 0, "" };

        return slice;
    }
    else
    {
        SLICE_T_ slice = { strlen(s), s };

        return slice;
    }
}

static
SLICE_T_
slice_trim_from_slice_(
    SLICE_T_ const* slice
) TWOB_NOEXCEPT
{
    assert(NULL != slice);

    {
        SLICE_T_ r = *slice;

        for (; 0 != r.n; )
        {
            if (isspace(r.s[0]))
            {
                --r.n;
                ++r.s;
            }
            else
            {
                break;
            }
        }

        for (; 0 != r.n; )
        {
            if (isspace(r.s[r.n - 1]))
            {
                --r.n;
            }
            else
            {
                break;
            }
        }

        return r;
    }
}

static
int
slice_compare_(
    SLICE_T_ const* lhs
,   SLICE_T_ const* rhs
) TWOB_NOEXCEPT
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    {
        size_t const    n   =   (lhs->n < rhs->n) ? lhs->n : rhs->n;
        int const       r   =   strncmp(lhs->s, rhs->s, n);

        if (0 == r)
        {
            if (lhs->n < rhs->n)
            {
                return -1;
            }

            if (lhs->n > rhs->n)
            {
                return +1;
            }
        }

        return r;
    }
}

static
int
slice_compare_ignore_case_(
    SLICE_T_ const* lhs
,   SLICE_T_ const* rhs
) TWOB_NOEXCEPT
{
    assert(NULL != lhs);
    assert(NULL != rhs);

    {
        size_t const    n   =   (lhs->n < rhs->n) ? lhs->n : rhs->n;
        int const       r   =   strncasecmp(lhs->s, rhs->s, n);

        if (0 == r)
        {
            if (lhs->n < rhs->n)
            {
                return -1;
            }

            if (lhs->n > rhs->n)
            {
                return +1;
            }
        }

        return r;
    }
}

static
int
precise_contains_(
    SLICE_T_ const  ar[]
,   size_t          n
,   SLICE_T_ const* slice
) TWOB_NOEXCEPT
{
    assert(NULL != ar || 0 == n);
    assert(NULL != slice);

    {
        return bsearch(
            slice
        ,   ar, n
        ,   sizeof(SLICE_T_)
        ,   (twob_truthy_cmp_fn_t)slice_compare_
        ) != NULL;
    }
}

static
int
contains_ignore_case_(
    SLICE_T_ const  ar[]
,   size_t          n
,   SLICE_T_ const* slice
) TWOB_NOEXCEPT
{
    assert(NULL != ar || 0 == n);
    assert(NULL != slice);

    {
        for (size_t i = 0; n != i; ++i)
        {
            int const r = slice_compare_ignore_case_(&ar[i], slice);

            if (0 == r)
            {
                return 1;
            }
        }

        return 0;
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * global state
 */


/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

static
SLICE_T_ const
FALSEY_PRECISE_STRINGS[] =
{
    SLICE_FROM_LITERAL_("0"),
    SLICE_FROM_LITERAL_("FALSE"),
    SLICE_FROM_LITERAL_("False"),
    SLICE_FROM_LITERAL_("NO"),
    SLICE_FROM_LITERAL_("No"),
    SLICE_FROM_LITERAL_("OFF"),
    SLICE_FROM_LITERAL_("Off"),
    SLICE_FROM_LITERAL_("false"),
    SLICE_FROM_LITERAL_("no"),
    SLICE_FROM_LITERAL_("off"),
};

static
SLICE_T_ const
TRUEY_PRECISE_STRINGS[] =
{
    SLICE_FROM_LITERAL_("1"),
    SLICE_FROM_LITERAL_("ON"),
    SLICE_FROM_LITERAL_("On"),
    SLICE_FROM_LITERAL_("TRUE"),
    SLICE_FROM_LITERAL_("True"),
    SLICE_FROM_LITERAL_("YES"),
    SLICE_FROM_LITERAL_("Yes"),
    SLICE_FROM_LITERAL_("on"),
    SLICE_FROM_LITERAL_("true"),
    SLICE_FROM_LITERAL_("yes"),
};

static
SLICE_T_ const
FALSEY_LOWERCASE_STRINGS[] =
{
    SLICE_FROM_LITERAL_("false"),
    SLICE_FROM_LITERAL_("no"),
    SLICE_FROM_LITERAL_("off"),
    SLICE_FROM_LITERAL_("0"),
};

static
SLICE_T_ const
TRUEY_LOWERCASE_STRINGS[] =
{
    SLICE_FROM_LITERAL_("true"),
    SLICE_FROM_LITERAL_("yes"),
    SLICE_FROM_LITERAL_("on"),
    SLICE_FROM_LITERAL_("1"),
};


/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

TWOB_CALL(int)
twob_truthy_init(
    twob_uint32_t   init_flags
,   void*           init_param
)
{
    ((void)&init_flags);
    ((void)&init_param);

    return 0;
}

TWOB_CALL(void)
twob_truthy_uninit(void)
{
}


TWOB_CALL(int)
twob_string_is_falsey(
    char const* s
) TWOB_NOEXCEPT
{
    SLICE_T_ const slice = slice_from_s_(s);

    /* 1. precise */

    if (precise_contains_(FALSEY_PRECISE_STRINGS, DIMENSION_OF_(FALSEY_PRECISE_STRINGS), &slice))
    {
        return 1;
    }
    else
    {
        SLICE_T_ const trimmed = slice_trim_from_slice_(&slice);

        /* 2. trimmed and lowercase */

        if (contains_ignore_case_(FALSEY_LOWERCASE_STRINGS, DIMENSION_OF_(FALSEY_LOWERCASE_STRINGS), &trimmed))
        {
            return 1;
        }
    }

    return 0;
}

TWOB_CALL(int)
twob_string_is_truey(
    char const* s
) TWOB_NOEXCEPT
{
    SLICE_T_ const slice = slice_from_s_(s);

    /* 1. precise */

    if (precise_contains_(TRUEY_PRECISE_STRINGS, DIMENSION_OF_(TRUEY_PRECISE_STRINGS), &slice))
    {
        return 1;
    }
    else
    {
        SLICE_T_ const trimmed = slice_trim_from_slice_(&slice);

        /* 2. trimmed and lowercase */

        if (contains_ignore_case_(TRUEY_LOWERCASE_STRINGS, DIMENSION_OF_(TRUEY_LOWERCASE_STRINGS), &trimmed))
        {
            return 1;
        }
    }

    return 0;
}

/** Indicates that the given string, when trimmed, is classified as "truthy"
 * (and is deemed as either "falsey" or "truey").
 */
TWOB_CALL(int)
twob_string_is_truthy(
    char const* s
) TWOB_NOEXCEPT
{
    SLICE_T_ const slice = slice_from_s_(s);

    /* 1. precise (true) */

    if (precise_contains_(TRUEY_PRECISE_STRINGS, DIMENSION_OF_(TRUEY_PRECISE_STRINGS), &slice))
    {
        return 1;
    }

    if (precise_contains_(FALSEY_PRECISE_STRINGS, DIMENSION_OF_(FALSEY_PRECISE_STRINGS), &slice))
    {
        return 1;
    }

    {
        SLICE_T_ const trimmed = slice_trim_from_slice_(&slice);

        /* 2. trimmed and lowercase */

        if (contains_ignore_case_(TRUEY_LOWERCASE_STRINGS, DIMENSION_OF_(TRUEY_LOWERCASE_STRINGS), &trimmed))
        {
            return 1;
        }

        if (contains_ignore_case_(FALSEY_LOWERCASE_STRINGS, DIMENSION_OF_(FALSEY_LOWERCASE_STRINGS), &trimmed))
        {
            return 1;
        }
    }

    return 0;
}



/* ///////////////////////////// end of file //////////////////////////// */
