#include "string.h"

#ifdef TEST_ENV

#include "test_group.h"

void test1() { printf("%d\n", 1); }
void test2() { printf("%d\n", 2); }
void test3() { printf("%d\n", 3); }
void test4() { printf("%d\n", 4); }

declare_test_group(string, 4, test1, test2, test3, test4);

#endif
