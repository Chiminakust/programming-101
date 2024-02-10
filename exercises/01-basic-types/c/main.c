/*
 * Exercice 1: Basic type handling in C.
 */

#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define assert(condition)                                               \
    do {                                                                \
        if (!(condition)) {                                             \
            printf(KRED"----\tassert line %d fail\t\t----\n"KNRM, __LINE__); \
            return -1;                                                  \
        }                                                               \
    } while (0)

#define assert_near(x, expected, tolerance) \
    do {                                    \
        assert(((expected * (1 - tolerance)) <= x) && (x <= (expected * (1 + tolerance)))) \
    } while (0)

#define test_start() do {                               \
        printf(KBLU"----\t%s start\t\t\t----\n"KNRM, __func__); \
    } while(0)

#define test_pass() do {                                \
        printf(KGRN"----\t%s pass\t\t\t----\n"KNRM, __func__);  \
    } while(0)

static int run_all_tests(void);
static int test_addi(void);
static int test_addf(void);
static int test_maclaurin_sin(void);
static int test_maclaurin_cos(void);
static int test_fib(void);
static int test_string_to_int(void);
static int test_int_to_string(void);
// TODO: exercises for boolean manipulation

/*
 * 1.1 Create a function named addi that takes 2 integers and returns the
 * sum of the two.
 */
int
addi(int a, int b)
{
    return a + b;
}

/*
 * 1.2 Create a function named addf that takes two floating point numbers
 * and returns the sum of the two.
 */
float addf(float a, float b) {
    return a + b;
}

/*
 * 1.3 Create a function that returns the power of x to y.
 * All arguments and return types are floating point number.
 */

/*
 * 1.4 Maclaurin series of sin(x) and cos(x) to any Nth degree (check wikipedia).
 * Takes a float as argument and returns a float. Other arguments left as exercise.
 * Functions must be named maclaurin_sin and maclaurin_cos.
 */

/*
 * 1.5 Create a function called fib that returns the Nth term of the fibonacci sequence.
 */

/*
 * 1.6 Create a function called string_to_int that converts a string to an integer value.
 * The function takes a string as argument and returns an int.
 */

/*
 * 1.7 Create a function called int_to_string that converts an int
 * to its string representation. The function can modify an input argument
 * and return an error code or return the string.
 */

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

    assert(addf(1.3, 4.3) == 5.6);
    assert(addf(0, 4.3) == 4.3);

    test_pass();
    return 0;
}

static int
test_maclaurin_sin(void)
{

    return 0;
}

static int
test_maclaurin_cos(void)
{

    return 0;
}

static int
test_fib(void)
{
    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    assert(fib(5) == 5);
    assert(fib(6) == 8);
    assert(fib(19) == 4181);
    assert(fib(-1) == 0);
    return 0;
}

static int
test_string_to_int(void)
{
    return 0;
}

static int
test_int_to_string(void)
{
    return 0;
}
