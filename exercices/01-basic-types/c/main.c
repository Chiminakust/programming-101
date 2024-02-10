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

#define test_start() do {                               \
        printf(KBLU"----\t%s start\t\t\t----\n"KNRM, __func__); \
    } while(0)

#define test_pass() do {                                \
        printf(KGRN"----\t%s pass\t\t\t----\n"KNRM, __func__);  \
    } while(0)

static int run_all_tests(void);
static int test_addi(void);
static int test_addf(void);

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
    assert(addf(1.4, 4.3) == 5.6);

    test_pass();
    return 0;
}
