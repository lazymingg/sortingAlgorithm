#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <cstdint>
class HeapSort
{
public:
    HeapSort(int *arr, int n);
    ~HeapSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void heapify(int *arr, int current, int size);
    void heapSort(int *arr, int size);
    void heapifyWithComparisonCount(int *arr, int current, int size);
    void heapSortWithComparisonCount(int *arr, int size);
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
    int64_t comparison = 0;
    double runningTime = 0;
};

#endif // HEAPSORT_H