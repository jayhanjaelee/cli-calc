/**
 * @file test.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-24 23:46
 */

#include <stdio.h>
#include "calc.h"
#include "greatest.h"

TEST add(void) {
    struct calculator calc = {
        1,1,'+'
    };
    calculate(&calc);
    ASSERT_EQ(calc.total, 2);
    PASS();
};

TEST subtract(void) {
    struct calculator calc = {
        1,1,'-'
    };
    calculate(&calc);
    ASSERT_EQ(calc.total, 0);
    PASS();
}

TEST multiply(void) {
    struct calculator calc = {
        2,5,'*'
    };
    calculate(&calc);
    ASSERT_EQ(calc.total, 10);
    PASS();
}

TEST divide(void) {
    struct calculator calc = {
        10,2,'/'
    };
    calculate(&calc);
    ASSERT_EQ(calc.total, 5);
    PASS();
}

/* Suites can group multiple tests with common setup. */
SUITE(the_suite) {
    RUN_TEST(add);
    RUN_TEST(subtract);
    RUN_TEST(multiply);
    RUN_TEST(divide);
}

/* Add definitions that need to be in the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line options, initialization. */
    RUN_SUITE(the_suite);
    GREATEST_MAIN_END();        /* display results */
}
