/*
    Program 29: Activity selection - pick the maximum number of
                non-overlapping activities
    Topic: Greedy
    (New - from the roadmap's "Greedy" node. Sort activities by
    finish time, then always pick the next activity whose start time
    is not before the last selected activity's finish time. Picking
    the earliest finishing activity at each step is the "greedy
    choice" that provably gives the maximum count.)
*/
#include <stdio.h>
#include "projects.h"

#define MAX_ACTIVITIES 50

void program29(void)
{
    int start[MAX_ACTIVITIES], finish[MAX_ACTIVITIES];
    int n, i, j, count;
    int last_finish;

    printf("--- Program 29: Activity Selection (Greedy) ---\n");
    printf("Enter number of activities: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ACTIVITIES)
    {
        printf("Please enter a size between 1 and %d.\n", MAX_ACTIVITIES);
        return;
    }

    printf("Enter start and finish time for each activity:\n");
    for (i = 0; i < n; i++)
    {
        printf("Activity %d (start finish): ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    /* simple bubble sort by finish time (small n, so this is fine) */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                int ts = start[j];  start[j] = start[j + 1];   start[j + 1] = ts;
                int tf = finish[j]; finish[j] = finish[j + 1]; finish[j + 1] = tf;
            }
        }
    }

    printf("Selected activities (start, finish): (%d, %d) ", start[0], finish[0]);
    last_finish = finish[0];
    count = 1;

    for (i = 1; i < n; i++)
    {
        if (start[i] >= last_finish)
        {
            printf("(%d, %d) ", start[i], finish[i]);
            last_finish = finish[i];
            count++;
        }
    }

    printf("\nMaximum number of non-overlapping activities: %d\n", count);
}
