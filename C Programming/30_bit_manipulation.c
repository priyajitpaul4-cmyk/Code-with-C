/*
    Program 30: Basic bitwise operations demo
    Topic: Bit Manipulation
    (New - from the roadmap's "Bit Manipulation" node. Shows the
    everyday tricks: checking even/odd with & instead of %, counting
    set bits, and swapping two numbers with XOR instead of a temp
    variable - contrast this with Programs 11-13.)
*/
#include <stdio.h>
#include "projects.h"

static int count_set_bits(int num)
{
    int count = 0;
    unsigned int n = (unsigned int)num;

    while (n != 0)
    {
        count += (n & 1);   /* check the last bit */
        n = n >> 1;         /* shift right to check the next bit */
    }
    return count;
}

void program30(void)
{
    int num, a, b;

    printf("--- Program 30: Bit Manipulation ---\n");

    printf("Enter a number to check even/odd and count set bits: ");
    scanf("%d", &num);

    if ((num & 1) == 0)
        printf("%d is even (last bit is 0)\n", num);
    else
        printf("%d is odd (last bit is 1)\n", num);

    printf("Number of set bits (1s) in %d is: %d\n", num, count_set_bits(num));

    printf("\nEnter two numbers to swap using XOR: ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swapping : a = %d, b = %d\n", a, b);
}
