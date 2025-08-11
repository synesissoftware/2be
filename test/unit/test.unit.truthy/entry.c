/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.truthy.c
 *
 * Purpose: Unit-tests for 2be Truthy API
 *
 * Created: 11th August 2025
 * Updated: 11th August 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

/* 2be Header Files */
#include <2be/2be.h>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_falsey_1(void);
static void TEST_truey_1(void);
static void TEST_truthy_1(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.truthy", verbosity))
    {
        XTESTS_RUN_CASE(TEST_falsey_1);
        XTESTS_RUN_CASE(TEST_truey_1);
        XTESTS_RUN_CASE(TEST_truthy_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static char const* UNTRUTHY_STRINGS[] =
{
    "",
    "Copyright ©",
};

static char const* TRUTHY_FALSEY_STRINGS[] =
{
    "0",
    "false",
    " FALSE",
    "False",
    "FaLSe",
    "no",
    "No ",
    "NO",
    " Off ",
    "off",
    "OFF",
};

static char const* TRUTHY_TRUEY_STRINGS[] =
{
    "1",
    "true",
    "TRUE",
    "True",
    "tRuE",
    "yes",
    " YES",
    "Yes   ",
    "yEs",
};


static void TEST_falsey_1(void)
{
    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(UNTRUTHY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_FALSE(twob_string_is_falsey(UNTRUTHY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_FALSEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_TRUE(twob_string_is_falsey(TRUTHY_FALSEY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_TRUEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_FALSE(twob_string_is_falsey(TRUTHY_TRUEY_STRINGS[i]));
    }
}

static void TEST_truey_1(void)
{
    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(UNTRUTHY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_FALSE(twob_string_is_truey(UNTRUTHY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_FALSEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_FALSE(twob_string_is_truey(TRUTHY_FALSEY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_TRUEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_TRUE(twob_string_is_truey(TRUTHY_TRUEY_STRINGS[i]));
    }
}

static void TEST_truthy_1(void)
{
    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(UNTRUTHY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_FALSE(twob_string_is_truthy(UNTRUTHY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_FALSEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_TRUE(twob_string_is_truthy(TRUTHY_FALSEY_STRINGS[i]));
    }

    for (size_t i = 0; STLSOFT_NUM_ELEMENTS(TRUTHY_TRUEY_STRINGS) != i; ++i)
    {
        TEST_BOOLEAN_TRUE(twob_string_is_truthy(TRUTHY_TRUEY_STRINGS[i]));
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

