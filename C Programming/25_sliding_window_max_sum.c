/*
    Program 25: Maximum sum subarray of size k (Sliding Window)
    Topic: Sliding Window
    (New - from the roadmap's "Sliding Window" node. Instead of
    recomputing the sum of every window of size k from scratch, we
    "slide" it: subtract the element leaving the window and add the
    element entering it. This turns an O(n*k) approach into O(n).)
*/
#include <stdio.h>
#include "projects.h"

void program25(void)
{
    int arr[100];
    int n, k, i;
    int window_sum = 0, max_sum;

    printf("--- Program 25: Sliding Window - Max Sum Subarray of Size k ---\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter window size k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n)
    {
        printf("k must be between 1 and %d.\n", n);
        return;
    }

    for (i = 0; i < k; i++)
        window_sum += arr[i];

    max_sum = window_sum;

    for (i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    printf("Maximum sum of a subarray of size %d is: %d\n", k, max_sum);
}
