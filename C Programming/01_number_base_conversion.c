/*
    Program 01: Display Hexadecimal, Decimal and Octal format of a given number
    Topic: Basic Input/Output
*/
#include <stdio.h>
#include "projects.h"

void program01(void)
{
    int num;
    printf("--- Program 01: Number Base Conversion ---\n");
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Decimal format is     : %d\n", num);
    printf("Hexadecimal format is : %x\n", num);
    printf("Octal format is       : %o\n", num);
}
