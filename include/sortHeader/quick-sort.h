#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <cstdint>
class QuickSort {
public:
    QuickSort(int *arr, int n);
    ~QuickSort();

    uint64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();

private:
    void quickSort(int *arr, int left, int right);
    int partition(int *arr, int left, int right);
    void quickSortWithComparisonCount(int *arr, int left, int right);
    int partitionWithComparisonCount(int *arr, int left, int right);
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
    int64_t comparison = 0;
    double runningTime = 0.0;
};

#endif // QUICKSORT_H