#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>

// Data generation functions
void ascend(int A[], int N);
void descend(int A[], int N);
void vee(int A[], int N);
void zigzag(int A[], int N);
void random_array(int A[], int N);

// Sorting Algos
long insertSort(int A[], int N);
long quickSort(int A[], int N);
long mergeSort(int A[], int N);


#endif 