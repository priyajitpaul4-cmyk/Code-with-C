/*
    Program 05: Check whether a year is a leap year or not
    Topic: Conditional Statements
*/
#include <stdio.h>
#include "projects.h"

void program05(void)
{
    int year;
    printf("--- Program 05: Leap Year Check ---\n");
    printf("Enter year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");
}
