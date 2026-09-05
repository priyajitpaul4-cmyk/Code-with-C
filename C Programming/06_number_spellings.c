/*
    Program 06: Display the spelling (in words) of a number entered by the user (1-10)
    Topic: Switch Case + Functions
*/
#include <stdio.h>
#include "projects.h"

static void digit_to_word(int digit)
{
    switch (digit)
    {
        case 1:  printf("One\n");   break;
        case 2:  printf("Two\n");   break;
        case 3:  printf("Three\n"); break;
        case 4:  printf("Four\n");  break;
        case 5:  printf("Five\n");  break;
        case 6:  printf("Six\n");   break;
        case 7:  printf("Seven\n"); break;
        case 8:  printf("Eight\n"); break;
        case 9:  printf("Nine\n");  break;
        case 10: printf("Ten\n");   break;
        default: printf("Please enter a number between 1 and 10\n"); break;
    }
}

void program06(void)
{
    int digit;
    printf("--- Program 06: Number Spellings (1-10) ---\n");
    printf("Enter number in digit: ");
    scanf("%d", &digit);
    digit_to_word(digit);
}
