/*
    Program 03: Display First class, Second class, etc. according to the marks entered
    Topic: Conditional Statements (if-else ladder)
*/
#include <stdio.h>
#include "projects.h"

void program03(void)
{
    int marks;
    printf("--- Program 03: Class Based on Marks ---\n");
    printf("Enter your marks: ");
    scanf("%d", &marks);

    if (marks >= 90)
        printf("First class\n");
    else if (marks >= 80 && marks <= 89)
        printf("Second class\n");
    else if (marks >= 60 && marks <= 79)
        printf("Third class\n");
    else if (marks >= 40 && marks <= 59)
        printf("Fourth class\n");
    else
        printf("Fail\n");
}
