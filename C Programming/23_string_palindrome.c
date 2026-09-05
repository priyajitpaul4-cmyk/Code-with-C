/*
    Program 23: Check whether a string is a palindrome
    Topic: Strings
*/
#include <stdio.h>
#include <string.h>
#include "projects.h"

void program23(void)
{
    char str[100];
    int i, len, is_palindrome = 1;

    printf("--- Program 23: String Palindrome Check ---\n");
    printf("Enter a string: ");
    scanf("%99s", str);

    len = (int)strlen(str);

    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
        printf("\"%s\" is a palindrome\n", str);
    else
        printf("\"%s\" is not a palindrome\n", str);
}
