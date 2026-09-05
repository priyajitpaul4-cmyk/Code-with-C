/*
    Program 24: Find a pair with a given sum in a sorted array
    Topic: Two Pointers
    (New - from the roadmap's "Two Pointers" node. One pointer starts
    at the beginning, one at the end; they move toward each other
    based on whether the current sum is too small or too large. This
    finds the pair in O(n) instead of checking every pair in O(n^2).)
*/
#include <stdio.h>
#include "projects.h"

void program24(void)
{
    int arr[100];
    int n, i, target, left, right, sum;
    int found = 0;

    printf("--- Program 24: Two Pointers - Pair With Given Sum ---\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 1 || n > 100)
    {
        printf("Please enter a size between 2 and 100.\n");
        return;
    }

    printf("Enter %d elements in ascending (sorted) order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    left = 0;
    right = n - 1;

    while (left < right)
    {
        sum = arr[left] + arr[right];
        if (sum == target)
        {
            printf("Pair found: %d + %d = %d\n", arr[left], arr[right], target);
            found = 1;
            break;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    if (!found)
        printf("No pair adds up to %d\n", target);
}
