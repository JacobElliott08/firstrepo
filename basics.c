#include <stdio.h>
#include <limits.h>
#include <float.h>

void primitive_types(void) {
    char c = 'A';
    unsigned char uc = 255;
    short s = -32000;
    unsigned short us = 65000;
    int i = -123456;
    unsigned int ui = 123456;
    long l = -123456789L;
    unsigned long ul = 123456789UL;
    float f = 3.14f;
    double d = 3.14159265358979;
    long double ld = 3.14159265358979L;

    printf("--- Primitive Data Types ---\n");
    printf("char           : size=%lu bytes, value=%c\n", (unsigned long) sizeof(c), c);
    printf("unsigned char  : size=%lu bytes, value=%u, max=%d\n", (unsigned long) sizeof(uc), uc, UCHAR_MAX);
    printf("short          : size=%lu bytes, value=%hd, min=%d, max=%d\n", (unsigned long) sizeof(s), s, SHRT_MIN, SHRT_MAX);
    printf("unsigned short : size=%lu bytes, value=%hu, max=%d\n", (unsigned long) sizeof(us), us, USHRT_MAX);
    printf("int            : size=%lu bytes, value=%d, min=%d, max=%d\n", (unsigned long) sizeof(i), i, INT_MIN, INT_MAX);
    printf("unsigned int   : size=%lu bytes, value=%u, max=%u\n", (unsigned long) sizeof(ui), ui, UINT_MAX);
    printf("long           : size=%lu bytes, value=%ld, min=%ld, max=%ld\n", (unsigned long) sizeof(l), l, LONG_MIN, LONG_MAX);
    printf("unsigned long  : size=%lu bytes, value=%lu, max=%lu\n", (unsigned long) sizeof(ul), ul, ULONG_MAX);
    printf("float          : size=%lu bytes, value=%f, max=%e\n", (unsigned long) sizeof(f), f, FLT_MAX);
    printf("double         : size=%lu bytes, value=%f, max=%e\n", (unsigned long) sizeof(d), d, DBL_MAX);
    printf("long double    : size=%lu bytes, value=%Lf\n", (unsigned long) sizeof(ld), ld);
    printf("\n");
}

void conditionals(void) {
    int number = 42;

    printf("--- If / Else If / Else ---\n");
    if (number < 0) {
        printf("%d is negative\n", number);
    } else if (number == 0) {
        printf("%d is zero\n", number);
    } else if (number % 2 == 0) {
        printf("%d is positive and even\n", number);
    } else {
        printf("%d is positive and odd\n", number);
    }
    printf("\n");
}

void switch_statement(void) {
    int day = 3;

    printf("--- Switch Statement ---\n");
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
        case 7:
            printf("Weekend\n");
            break;
        default:
            printf("Invalid day\n");
            break;
    }
    printf("\n");
}

void loops(void) {
    int i;
    int count;
    int n;

    printf("--- For Loop ---\n");
    for (i = 0; i < 5; i++) {
        printf("for iteration: %d\n", i);
    }

    printf("--- While Loop ---\n");
    count = 0;
    while (count < 5) {
        printf("while iteration: %d\n", count);
        count++;
    }

    printf("--- Do While Loop ---\n");
    n = 0;
    do {
        printf("do-while iteration: %d\n", n);
        n++;
    } while (n < 5);
    printf("\n");
}

void static_arrays(void) {
    int numbers[5] = {10, 20, 30, 40, 50};
    char letters[3] = {'x', 'y', 'z'};
    double prices[4] = {1.5, 2.25, 3.75, 4.0};
    
    int grid[2][3] = {{1, 2, 3}, 
                      {4, 5, 6}};
    int i;
    int row;
    int col;

    printf("--- Static Array Allocation ---\n");
    printf("int array (size=%lu): ", (unsigned long) (sizeof(numbers) / sizeof(numbers[0])));
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("char array (size=%lu): ", (unsigned long) (sizeof(letters) / sizeof(letters[0])));
    for (i = 0; i < 3; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");

    printf("double array (size=%lu): ", (unsigned long) (sizeof(prices) / sizeof(prices[0])));
    for (i = 0; i < 4; i++) {
        printf("%.2f ", prices[i]);
    }
    printf("\n");

    /* 2D static array */
    printf("2D array:\n");
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    primitive_types();
    conditionals();
    switch_statement();
    loops();
    static_arrays();
    return 0;
}
