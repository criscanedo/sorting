#ifndef _QSORT_H
#define _QSORT_H

#include <vector>

namespace sort {

void qsort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void msort(int arr[], int work[], int size);
void merge(int arr[], int left, int right, int end, int work[]);
void copy(int src[], int dest[], int size);

} // namespace sort

#endif // _QSORT_H
