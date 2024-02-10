#ifndef UTILS_H_
#define UTILS_H_

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
            printf(KRED"----\tassert line %d fail\n"KNRM, __LINE__); \
            return -1;                                                  \
        }                                                               \
    } while (0)

#define assert_near(x, expected, tolerance)                             \
	do { \
		assert(is_near(x, expected, tolerance)); \
	} while (0)

#define test_start() do {                               \
        printf(KBLU"----\t%s start\n"KNRM, __func__); \
    } while(0)

#define test_pass() do {                                \
        printf(KGRN"----\t%s pass\n"KNRM, __func__);  \
    } while(0)

int
is_near(double x, double expected, double tolerance)
{
	double lower = expected * (1 - tolerance);
	double upper = expected * (1 + tolerance);
	if (lower > upper) {
		return (upper <= x) && (x <= lower);
	} else {
		return (lower <= x) && (x <= upper);
	}
}

#endif // UTILS_H_
