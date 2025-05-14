#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define test_printf(format, ...)                          \
    do {                                                  \
        int ret_orig = printf(format, ##__VA_ARGS__);     \
        int ret_ft = ft_printf(format, ##__VA_ARGS__);    \
        printf(" -> Orig: %d, ft_printf: %d\n", ret_orig, ret_ft); \
    } while (0)

int main(void)
{
    int x = 42;
    void *null_ptr = NULL;

    printf("\n--- Testing %%c ---\n");
    test_printf("Char: %c\n", 'A');
    test_printf("Char: %c\n", 0);
    test_printf("Char: %c\n", 127);
    test_printf("Multiple chars: %c %c %c\n", 'a', 'b', 'c');

    printf("\n--- Testing %%s ---\n");
    test_printf("String: %s\n", "Hello, World!");
    test_printf("Empty string: %s\n", "");
    test_printf("NULL string: %s\n", (char *)NULL);

    printf("\n--- Testing %%p ---\n");
    test_printf("Pointer: %p\n", &x);
    test_printf("Pointer: %p\n", null_ptr);
    test_printf("Pointer: %p\n", (void *)LONG_MAX);

    printf("\n--- Testing %%d and %%i ---\n");
    test_printf("Decimal: %d\n", 42);
    test_printf("Integer: %i\n", -42);
    test_printf("Zero: %d\n", 0);
    test_printf("Max int: %d\n", INT_MAX);
    test_printf("Min int: %d\n", INT_MIN);

    printf("\n--- Testing %%u ---\n");
    test_printf("Unsigned: %u\n", 42);
    test_printf("Unsigned zero: %u\n", 0);
    test_printf("Unsigned max: %u\n", UINT_MAX);

    printf("\n--- Testing %%x and %%X ---\n");
    test_printf("Hex lowercase: %x\n", 42);
    test_printf("Hex uppercase: %X\n", 42);
    test_printf("Hex zero: %x\n", 0);
    test_printf("Hex max (x): %x\n", UINT_MAX);
    test_printf("Hex max (X): %X\n", UINT_MAX);

    printf("\n--- Testing %% ---\n");
    test_printf("Just percent: %%\n");
    test_printf("Double percent: %%%%\n");

    printf("\n--- Testing Mixed Formats ---\n");
    test_printf("Mix: %c %s %p %d %i %u %x %X %%\n", 'Z', "Test", &x, 123, -456, 789, 255, 255);
    test_printf("Mix 2: %s %d %c %x %% %p\n", "mix2", -123, 'Z', 255, &x);

    printf("\n--- Testing Edge Cases ---\n");
    test_printf("Empty format: %s\n", "");
    test_printf("No specifiers\n");
    test_printf("Large number: %d\n", INT_MAX);
    test_printf("Large unsigned: %u\n", UINT_MAX);
    test_printf("NULL string: %s\n", (char *)NULL);
    test_printf("Null pointer: %p\n", NULL);

    printf("\n--- Stress Tests ---\n");
    test_printf("Long string: %s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    test_printf("Many args: %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6);
    test_printf("All zeroes: %d %i %u %x %X\n", 0, 0, 0, 0, 0);

    printf("\n=== Testing Complete ===\n");
    return 0;
}
