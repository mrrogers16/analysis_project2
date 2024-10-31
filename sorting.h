#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>

// IO Process
int processControlFile(const char *control_file_name);

// Data generation functions
void ascend(int A[], int N);
void descend(int A[], int N);
void vee(int A[], int N);
void zigzag(int A[], int N);
void random_array(int A[], int N);

// Sorting Algos
long insertionSort(int A[], int N);
long quickSort(int A[], int N);
long mergeSort(int A[], int N);

#endif