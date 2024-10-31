#include "sorting.h"

// Insertion Sort
long insertionSort(int A[], int N)
{ // Initialize comparison counter
    long comparisons = 0;
    // Starting from index 1, loop through entire array. A[0] is technically sorted at this point - remember that
    for (int i = 1; i < N; i++)
    {
        // Set current element as key to be placed in sorted portion
        int key = A[i];
        // Initialize j to represent the last index of the sorted portion at i - 1
        int j = i - 1;
        // Shift elements in sorted portion to right until correct position for key is found
        while (j >= 0 && (++comparisons && A[j] > key))
        {
            A[j + 1] = A[j];
            // Move left one to keep comparing with previous
            j--;
        }
        // When A[j] <= key (while loop exit), we count this add this final comparison.
        if (j >= 0)
        {
            comparisons++;
        }
        // Finally, place key in correct position in sorted portion
        A[j + 1] = key;
    }
    // Return total number of comparisons made during the given sort
    return comparisons;
}

// Quick Sort helper partition
long partition(int A[], int low, int high, long *comparisons)
{
    int pivot = A[high]; // Set pivot as last element 
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        (*comparisons)++;
        if ()
    }
}
