#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <cstdint>
#include <chrono>

class RadixSort
{
public:
    RadixSort(int *arr, int n);
    ~RadixSort();
    int64_t getComparison();
    double getRunningTime();
    
    int* getTempArr();
    int* getTempArr2();
    int getSize();

private:
    void radixSort(int *arr, int n);
    int getMax(int *arr, int n);
    void countSort(int *arr, int n, int digit);

    void radixSortWithComparisonCount(int *arr, int n);
    int getMaxWithComparisonCount(int *arr, int n);
    void countSortWithComparisonCount(int *arr, int n, int digit);

    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
    int64_t comparison = 0;
    double runningTime = 0.0;
};

#endif // RADIXSORT_H