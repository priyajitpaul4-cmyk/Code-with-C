/*
    Program 28: Print all permutations of a string
    Topic: Backtracking
    (New - from the roadmap's "Backtracking" node. Fix one character
    at the current position, recursively permute the rest, then swap
    back ("backtrack") before trying the next character in that
    position. This is the classic first backtracking example.)
*/
#include <stdio.h>
#include <string.h>
#include "projects.h"

static void swap_char(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

static void permute(char *str, int start, int len)
{
    int i;

    if (start == len - 1)
    {
        printf("%s\n", str);
        return;
    }

    for (i = start; i < len; i++)
    {
        swap_char(&str[start], &str[i]);
        permute(str, start + 1, len);
        swap_char(&str[start], &str[i]);   /* backtrack: undo the swap */
    }
}

void program28(void)
{
    char str[10];

    printf("--- Program 28: Permutations of a String ---\n");
    printf("Enter a short string (max 9 characters): ");
    scanf("%9s", str);

    printf("All permutations:\n");
    permute(str, 0, (int)strlen(str));
}
