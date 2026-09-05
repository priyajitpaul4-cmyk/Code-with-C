/*
    Program 32: Climbing stairs - count the number of distinct ways
                to climb n stairs, taking 1 or 2 steps at a time
    Topic: Dynamic Programming (1-D)
    (New - from the roadmap's "1-D Dynamic Programming" node. This is
    the same recurrence as Fibonacci (Program 16), but framed and
    solved bottom-up with a DP array: ways[i] = ways[i-1] + ways[i-2],
    since the last step taken to reach stair i was either 1 or 2.)
*/
#include <stdio.h>
#include "projects.h"

void program32(void)
{
    int n, i;
    int ways[100];

    printf("--- Program 32: Climbing Stairs (1-D DP) ---\n");
    printf("Enter number of stairs: ");
    scanf("%d", &n);

    if (n < 0 || n > 99)
    {
        printf("Please enter a value between 0 and 99.\n");
        return;
    }

    if (n == 0)
    {
        printf("Number of distinct ways: 1\n");
        return;
    }

    ways[1] = 1;
    if (n >= 2)
        ways[2] = 2;

    for (i = 3; i <= n; i++)
        ways[i] = ways[i - 1] + ways[i - 2];

    printf("Number of distinct ways to climb %d stairs: %d\n", n, ways[n]);
}
