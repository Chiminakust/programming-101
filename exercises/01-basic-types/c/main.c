/*
 * Exercice 1: Basic type handling in C.
 */

#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "solutions.c"

static int run_all_tests(void);
static int test_addi(void);
static int test_addf(void);
static int test_is_even(void);
static int test_powerf(void);
static int test_factorial(void);
static int test_maclaurin_sin(void);
static int test_maclaurin_cos(void);
static int test_fib(void);
static int test_string_to_int(void);
static int test_int_to_string(void);

int
main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	return run_all_tests();
}

static int
run_all_tests(void)
{
	printf("Test start.\n");

	if (test_addi()) {
		return -1;
	}

	if (test_addf()) {
		return -1;
	}

    if (test_is_even()) {
        return -1;
    }

    if (test_powerf()) {
        return -1;
    }

    if (test_factorial()) {
        return -1;
    }

	if (test_maclaurin_sin()) {
		return -1;
	}

	if (test_maclaurin_cos()) {
		return -1;
	}

	if (test_fib()) {
		return -1;
	}

	if (test_string_to_int()) {
		return -1;
	}

	if (test_int_to_string()) {
		return -1;
	}

	printf("All tests succeeded\n");
	return 0;
}

static int
test_addi(void)
{
	test_start();

	assert(addi(1, 2) == 3);
	assert(addi(100, -2) == 98);

	test_pass();
	return 0;
}

static int
test_addf(void)
{
	test_start();

	assert_near(addf(1.3, 4.3), 5.6, 0.01);
	assert_near(addf(0, 4.3), 4.3, 0.01);

	test_pass();
	return 0;
}

static int
test_is_even(void)
{
    test_start();

    assert(is_even(0) == 1);
    assert(is_even(-1) == 0);
    assert(is_even(1) == 0);
    assert(is_even(2) == 1);

    test_pass();
    return 0;
}

static int
test_powerf(void)
{
	test_start();
    assert_near(powerf(2, 4), 16, 0.01);

	test_pass();
    return 0;
}

static int
test_factorial(void)
{
	test_start();
    assert(factorial(0) == 1);
    assert(factorial(1) == 1);
    assert(factorial(2) == 2);
    assert(factorial(3) == 6);
    assert(factorial(8) == 40320);

	test_pass();
    return 0;
}

static int
test_maclaurin_sin(void)
{
	test_start();

    assert_near(maclaurin_sin(0, 7), sin(0), 0.05);
    assert_near(maclaurin_sin(0.1, 7), sin(0.1), 0.05);
    assert_near(maclaurin_sin(2, 7), sin(2), 0.05);
    assert_near(maclaurin_sin(3, 7), sin(3), 0.05);
    assert_near(maclaurin_sin(1.1, 7), sin(1.1), 0.05);
    assert_near(maclaurin_sin(4, 7), sin(4), 0.05);

	test_pass();
	return 0;
}

static int
test_maclaurin_cos(void)
{
	test_start();
    assert_near(maclaurin_cos(0, 7), cos(0), 0.05);
    assert_near(maclaurin_cos(0.1, 7), cos(0.1), 0.05);
    assert_near(maclaurin_cos(1.1, 7), cos(1.1), 0.05);
    assert_near(maclaurin_cos(3, 7), cos(3), 0.05);
    assert_near(maclaurin_cos(4, 7), cos(4), 0.05);

	test_pass();
	return 0;
}

static int
test_fib(void)
{
	test_start();

	assert(fib(0) == 0);
	assert(fib(1) == 1);
	assert(fib(2) == 1);
	assert(fib(3) == 2);
	assert(fib(4) == 3);
	assert(fib(5) == 5);
	assert(fib(6) == 8);
	assert(fib(19) == 4181);
	assert(fib(-1) == 0);

	test_pass();
	return 0;
}

static int
test_string_to_int(void)
{
	test_start();

    assert(string_to_int("123") == 123);
    assert(string_to_int("-10") == -10);
    assert(string_to_int("abc") == 0);

	test_pass();
	return 0;
}

static int
test_int_to_string(void)
{
    char testbuf[64] = {0};

	test_start();

    int_to_string(123, testbuf);
    assert(strcmp(testbuf, "123") == 0);

    int_to_string(-1, testbuf);
    assert(strcmp(testbuf, "-1") == 0);

	test_pass();
	return 0;
}
