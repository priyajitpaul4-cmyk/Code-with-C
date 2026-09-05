/*
    Program 31: Merge overlapping intervals
    Topic: Intervals
    (New - from the roadmap's "Intervals" node. Sort the intervals by
    start time, then walk through them once: if the current interval
    starts before (or exactly when) the last merged one ends, merge
    them by extending the end; otherwise start a new merged interval.)
*/
#include <stdio.h>
#include "projects.h"

#define MAX_INTERVALS 50

void program31(void)
{
    int start[MAX_INTERVALS], end[MAX_INTERVALS];
    int n, i, j;
    int merged_start[MAX_INTERVALS], merged_end[MAX_INTERVALS];
    int merged_count = 0;

    printf("--- Program 31: Merge Overlapping Intervals ---\n");
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_INTERVALS)
    {
        printf("Please enter a size between 1 and %d.\n", MAX_INTERVALS);
        return;
    }

    printf("Enter each interval as: start end\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &start[i], &end[i]);

    /* simple bubble sort by start time (small n, so this is fine) */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (start[j] > start[j + 1])
            {
                int ts = start[j]; start[j] = start[j + 1]; start[j + 1] = ts;
                int te = end[j];   end[j] = end[j + 1];     end[j + 1] = te;
            }
        }
    }

    merged_start[0] = start[0];
    merged_end[0] = end[0];
    merged_count = 1;

    for (i = 1; i < n; i++)
    {
        if (start[i] <= merged_end[merged_count - 1])
        {
            /* overlaps the last merged interval: extend it if needed */
            if (end[i] > merged_end[merged_count - 1])
                merged_end[merged_count - 1] = end[i];
        }
        else
        {
            merged_start[merged_count] = start[i];
            merged_end[merged_count] = end[i];
            merged_count++;
        }
    }

    printf("Merged intervals: ");
    for (i = 0; i < merged_count; i++)
        printf("[%d, %d] ", merged_start[i], merged_end[i]);
    printf("\n");
}
