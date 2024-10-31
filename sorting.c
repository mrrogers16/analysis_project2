#include "sorting.h"
#include <string.h>
#include <time.h>

// File handling
int processControlFile(const char *control_file_name)
{
    FILE *control_file = fopen(control_file_name, "r");
    if (!control_file)
    {
        fprintf(stderr, "Error: Could not open control file %s\n", control_file_name);
        return 1;
    }

    int runs;
    if (fscanf(control_file, "%d", &runs) != 1)
    {
        fprintf(stderr, "Error: Invalid control file format\n");
        fclose(control_file);
        return 1;
    }

    for (int run = 0; run < runs; run++)
    {
        int N;
        char data_type;
        char sort_type;

        // Read in next line
        if (fscanf(control_file, "%d %c %c", &N, &data_type, &sort_type) != 3)
        {
            fprintf(stderr, "Error: Invalid control file format in run %d\n", run + 1);
            fclose(control_file);
            return 1;
        }

        if (N <= 0 || N >= 1000000)
        {
            fprintf(stderr, "Error: N must be between 1 and 999999 in run %d\n", run + 1);
            continue;
        }

        int *A = (int *)malloc(N * sizeof(int));
        if (!A)
        {
            fprintf(stderr, "Error: Memory allocation failed for run %d\n", run + 1);
            continue;
        }

        // Switch determining which data to generate
        switch (data_type)
        {
        case 'A':
            ascend(A, N);
            break;
        case 'D':
            descend(A, N);
            break;
        case 'V':
            vee(A, N);
            break;
        case 'Z':
            zigzag(A, N);
            break;
        case 'R':
            random_array(A, N);
            break;
        default:
            fprintf(stderr, "Error: Invalid data type '%c' in run %d\n", data_type, run + 1);
            free(A);
            continue;
        }

        // Sort data
        long comparisons = 0;
        switch (sort_type)
        {
        case 'I':
            comparisons = insertionSort(A, N);
            break;
        case 'Q':
            comparisons = quickSort(A, N);
            break;
        case 'M':
            comparisons = mergeSort(A, N);
            break;
        default:
            fprintf(stderr, "Error: Invalid sort type '%c' in run %d\n", sort_type, run + 1);
            free(A);
            continue;
        }

        // Output results
        printf("%d %c %c %ld\n", N, data_type, sort_type, comparisons);
        free(A);
    }
    fclose(control_file);
    return 0;
}
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
// Quick Sort helper to partition array and return pivot element index
long partition(int A[], int low, int high, long *comparisons)
{
    int pivot = A[high]; // Set pivot as last element
    int i = low - 1;     // Initialize i for elements <= pivot
    // Loop from low to high - 1 comparing each element with the pivot element
    for (int j = low; j < high; j++)
    {
        // Increment comparisons for each iteration
        (*comparisons)++;
        // If our current element is <= pivot...
        if (A[j] <= pivot)
        {
            // Move small element boundary right one
            i++;
            // Swap A[i] and A[j], placing smaller element in correct position
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // After our loop, we swap our pivot (A[high]) with A[i + 1] to place pivot in its final sorted position.
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;
    // Return the final position of the pivot element
    return i + 1;
}

void quickSortUtil(int A[], int low, int high, long *comparisons)
{
    // Base Case: Check if more than one element
    if (low < high)
    {
        int pi = partition(A, low, high, comparisons); // Retrieve and initialize our partition index (pi)
        // Using pi, recursively call quickSortUtil for both subarrays
        quickSortUtil(A, low, pi - 1, comparisons);  // Left of pivot
        quickSortUtil(A, pi + 1, high, comparisons); // Right of pivot
    }
}

long quickSort(int A[], int N)
{
    long comparisons = 0;                     // Initialize comparisons counter
    quickSortUtil(A, 0, N - 1, &comparisons); // Call quickSortUtil to start sorting entire array
    return comparisons;                       // Return count of comparisons
}

void merge(int A[], int left, int mid, int right, long *comparisons)
{
    int l_size = mid - left + 1; // Left subarray size
    int r_size = right - mid;    // Right subarray size

    // Initialize temp arrays for left and right subarrays
    int *L = (int *)malloc(l_size * sizeof(int));
    int *R = (int *)malloc(r_size * sizeof(int));

    // Copy data to temp arrays
    for (int i = 0; i < l_size; i++)
    {
        L[i] = A[left + 1]; // Left Subarray
    }
    for (int j = 0; j < r_size; j++)
    {
        R[j] = A[mid + 1 + j]; // Right Subarray
    }

    // Merge temp arrays back to A[left...right]
    int i = 0;    // Tracks position in L
    int j = 0;    // Tracks position in R
    int k = left; // Tracks A

    while (i < l_size && j < r_size)
    {
        (*comparisons)++; // Increment for each comparison between left and right
        // Find smaller element between L[i] and R[j]. Copy it to A[k]
        if (L[i] <= R[j])
        {
            A[k++] = L[i++]; // Left element is smaller or equal, so we increment i and k, and copy to A[k]
        }
        else
        {
            A[k++] = R[j++]; // Right element is smaller so we increment j and k, and copy to A[k]
        }
    }

    // Copy remaining elements from L to A if any
    while (i < l_size)
    {
        A[k++] = L[i++];
    }

    // Copyt remaining elements from R to A if any
    while (j < r_size)
    {
        A[k++] = R[j++];
    }

    // Free temp arrays L and R
    free(L);
    free(R);
}

void mergeSortUtil(int A[], int left, int right, long *comparisons)
{
    // Base Case: Check if more than one element
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Calculate midpoint to prevent int overflow for large arrays
        // Sort left half recursively
        mergeSortUtil(A, left, mid, comparisons);
        // Sort right half recursively
        mergeSortUtil(A, mid + 1, right, comparisons);
        // Merge the two arrays
        merge(A, left, mid, right, comparisons);
    }
}

long mergeSort(int A[], int N)
{
    long comparisons = 0;                     // Initalize comparisons counter
    mergeSortUtil(A, 0, N - 1, &comparisons); // Call recursive util function
    return comparisons;                       // Return total comparison count after sorting
}