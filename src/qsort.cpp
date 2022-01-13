#include "../include/qsort.h"

#include <vector>
#include <cmath>

namespace sort {

void qsort(int arr[], int low, int high)
{
    if (low >= 0 && high >= 0 && low < high) {
        int pivot = partition(arr, low, high);
        qsort(arr, low, pivot);
        qsort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[(int)std::floor((high + low) / 2)];
    int left = low - 1;
    int right = high + 1;

    while (true) {
        do {
            left++;
        } while (arr[left] < pivot);
        do {
            right--;
        } while (arr[right] > pivot);
        if (left >= right) return right;
        swap(&arr[left], &arr[right]);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void msort(int arr[], int work[], int size)
{
    for (int width = 1; width < size; width *= 2) {
        for (int i = 0; i < size; i += width * 2) {
            merge(arr, i, std::min(i + width, size), std::min(i + width * 2, size), work);
        }
        copy(work, arr, size);
    }
}

void merge(int arr[], int left, int right, int end, int work[])
{
    int i = left;
    int j = right;
    for (int k = left; k < end; k++) {
        if (i < right && (j >= end || arr[i] <= arr[j])) {
            work[k] = arr[i++];
        } else {
            work[k] = arr[j++];
        }
    }
}

void copy(int src[], int dest[], int size)
{
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

} // namespace sort
