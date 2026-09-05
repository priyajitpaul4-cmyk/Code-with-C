/*
    main.c
    Central menu-controller for the C Programming Lab project.
    This is the ONLY file containing main(). It shows a topic menu,
    then a program menu within that topic, and calls the matching
    function declared in projects.h. No program logic lives here.
*/

#include <stdio.h>
#include "projects.h"

typedef struct {
    int number;
    const char *title;
    void (*run)(void);
} Program;

typedef struct {
    const char *name;
    const Program *list;
    int count;
} Category;

static const Program basicPrograms[] = {
    {  1, "Number base conversion (dec/oct/hex)", program01 },
    {  2, "Largest and smallest of three numbers", program02 },
    {  3, "Class based on marks entered",          program03 },
    {  4, "Even or odd number",                    program04 },
    {  5, "Leap year check",                       program05 },
    {  6, "Spellings of numbers 1-10",              program06 },
    {  7, "Roots of a quadratic equation",         program07 },
    {  8, "Prime check (single number or range)",  program08 },
    {  9, "Print college name 20 times",            program09 },
    { 10, "Menu driven arithmetic (switch case)",  program10 }
};

static const Program operators[] = {
    { 11, "Swap two numbers using a third variable",   program11 },
    { 12, "Swap two numbers without a third variable", program12 },
    { 13, "Swap two numbers using pointers",           program13 }
};

static const Program functionsRecursion[] = {
    { 14, "Factorial (iterative)",      program14 },
    { 15, "Factorial (recursive)",      program15 },
    { 16, "Fibonacci series",           program16 },
    { 17, "GCD and LCM of two numbers", program17 }
};

static const Program numbers[] = {
    { 18, "Armstrong check (single number or range)", program18 },
    { 19, "Sum of digits of a number",                 program19 }
};

static const Program arraysHashing[] = {
    { 20, "Sum of numbers using an array",       program20 },
    { 21, "Smallest element of an array",        program21 },
    { 22, "Find duplicates in an array (hashing)", program22 }
};

static const Program strings[] = {
    { 23, "Check whether a string is a palindrome", program23 }
};

static const Program twoPointersSearching[] = {
    { 24, "Pair with a given sum in a sorted array",       program24 },
    { 25, "Maximum sum subarray of size k (sliding window)", program25 },
    { 26, "Binary search for a target",                    program26 }
};

static const Program heapPQ[] = {
    { 27, "Array based min-heap (insert / extract-min)", program27 }
};

static const Program backtracking[] = {
    { 28, "Print all permutations of a string", program28 }
};

static const Program greedy[] = {
    { 29, "Activity selection (max non-overlapping tasks)", program29 }
};

static const Program bitManipulation[] = {
    { 30, "Basic bitwise operations demo", program30 }
};

static const Program intervals[] = {
    { 31, "Merge overlapping intervals", program31 }
};

static const Program dynamicProgramming[] = {
    { 32, "Climbing stairs (1-D DP)", program32 }
};

static const Category categories[] = {
    { "Basic Programs",             basicPrograms,        10 },
    { "Operators",                  operators,             3 },
    { "Functions & Recursion",      functionsRecursion,    4 },
    { "Numbers",                    numbers,               2 },
    { "Arrays & Hashing",           arraysHashing,         3 },
    { "Strings",                    strings,               1 },
    { "Two Pointers & Searching",   twoPointersSearching,  3 },
    { "Heap / Priority Queue",      heapPQ,                1 },
    { "Backtracking",               backtracking,          1 },
    { "Greedy",                     greedy,                1 },
    { "Bit Manipulation",           bitManipulation,       1 },
    { "Intervals",                  intervals,             1 },
    { "Dynamic Programming",        dynamicProgramming,    1 }
};

#define TOTAL_CATEGORIES ((int)(sizeof(categories) / sizeof(categories[0])))

static int total_programs(void)
{
    int i, sum = 0;
    for (i = 0; i < TOTAL_CATEGORIES; i++)
        sum += categories[i].count;
    return sum;
}

/* Reads one integer safely; discards bad input instead of looping forever */
static int read_int(const char *prompt)
{
    int value, ch;
    printf("%s", prompt);

    while (scanf("%d", &value) != 1)
    {
        if (feof(stdin) || ferror(stdin))
            return -1;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        printf("Invalid input, try again.\n%s", prompt);
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
    return value;
}

static void show_main_menu(void)
{
    int i;
    printf("\n==============================\n");
    printf("      C PROGRAMMING LAB\n");
    printf("==============================\n");
    printf("Total programs: %d\n", total_programs());
    printf("------------------------------\n");
    for (i = 0; i < TOTAL_CATEGORIES; i++)
        printf("%2d. %s (%d)\n", i + 1, categories[i].name, categories[i].count);
    printf(" 0. Exit\n");
    printf("------------------------------\n");
}

static void show_category_menu(int index)
{
    const Category *cat = &categories[index];
    int choice, i;

    for (;;)
    {
        printf("\n---- %s ----\n", cat->name);
        for (i = 0; i < cat->count; i++)
            printf("%d. Program %02d: %s\n", i + 1, cat->list[i].number, cat->list[i].title);
        printf("0. Back to main menu\n");

        choice = read_int("Enter your choice: ");

        if (choice == -1 || choice == 0)
            return;

        if (choice >= 1 && choice <= cat->count)
            cat->list[choice - 1].run();
        else
            printf("Invalid choice. Try again.\n");
    }
}

int main(void)
{
    int choice;

    for (;;)
    {
        show_main_menu();
        choice = read_int("Enter your choice: ");

        if (choice == -1 || choice == 0)
        {
            printf("Exiting...\n");
            break;
        }

        if (choice >= 1 && choice <= TOTAL_CATEGORIES)
            show_category_menu(choice - 1);
        else
            printf("Invalid choice. Try again.\n");
    }

    return 0;
}
