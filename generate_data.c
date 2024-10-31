#include "sorting.h"

void ascend(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        // increment i and create ascending array
        A[i] = i + 1;
    }
}

void descend(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        // decrement N and create descending array
        A[i] = N - i;
    }
}

void vee(int A[], int N)
{
    int mid = N / 2;
    int val = N;
    // Add every other value up to midpoint
    for (int i = 0; i < mid; i++)
    {
        A[i] = val;
        val -= 2;
    }
    
    // Set initial value of val to handle the other half of the array. If even, val = 1, if odd val = 2
    if(N % 2 == 0)
    {
        val = 1;
    }
    else
    {
        val = 2;
    }
    // Starting a the new val, add every other val to A[i] finishing up our vee
    for(int i = mid; i < N; i++)
    {
        A[i] = val;
        val += 2;
    }
}

void zigzag(int A[], int N)
{
    int left = N;
    int right = 1;
    // Iterate from i to N
    for (int i = 0; i < N; i++)
    {
        // If i is even assign to left and decrement left
        if (i % 2 == 0)
        {
            A[i] == left--;
        }
        // If i is odd assign to right and increment right
        else
        {
            A[i] = right++;
        }
    }
}

void random_array(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % (N + 1); // Random integer between 0 and N
    }
}
