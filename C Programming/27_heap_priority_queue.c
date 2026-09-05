/*
    Program 27: Array based Min-Heap - insert and extract-min
    Topic: Heap / Priority Queue
    (New - from the roadmap's "Heap / Priority Queue" node. A binary
    min-heap is stored in a plain array: for index i, its children are
    at 2*i+1 and 2*i+2. "Bubble up" fixes the heap after an insert,
    "bubble down" fixes it after removing the smallest element.)
*/
#include <stdio.h>
#include "projects.h"

#define MAX_HEAP 100

static int heap[MAX_HEAP];
static int heap_size = 0;

static void swap_int(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void heap_insert(int value)
{
    int i;

    if (heap_size >= MAX_HEAP)
    {
        printf("Heap is full, cannot insert %d\n", value);
        return;
    }

    heap[heap_size] = value;
    i = heap_size;
    heap_size++;

    /* bubble up: while the new value is smaller than its parent, swap up */
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap_int(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

static int heap_extract_min(void)
{
    int min_value, i, smallest, left, right;

    if (heap_size == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }

    min_value = heap[0];
    heap_size--;
    heap[0] = heap[heap_size];

    /* bubble down: repeatedly swap with the smaller child until placed */
    i = 0;
    for (;;)
    {
        smallest = i;
        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < heap_size && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap_size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap_int(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return min_value;
}

void program27(void)
{
    int n, i, value, choice;

    heap_size = 0;

    printf("--- Program 27: Min-Heap / Priority Queue ---\n");
    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_HEAP)
    {
        printf("Please enter a size between 1 and %d.\n", MAX_HEAP);
        return;
    }

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        heap_insert(value);
    }

    printf("1. Extract the minimum once\n");
    printf("2. Extract all (prints numbers in sorted order)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Minimum extracted: %d\n", heap_extract_min());
    }
    else if (choice == 2)
    {
        printf("Extracted order: ");
        while (heap_size > 0)
            printf("%d ", heap_extract_min());
        printf("\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
