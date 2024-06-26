#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <cstdint>
class InsertionSort
{
public:
    InsertionSort(int *arr, int n);
    ~InsertionSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void insertionSortRunningTimeCount(int *arr, int n);
    void insertionSortComparisonCount(int *arr, int n);
    double runningTime = 0;
    int64_t comparison = 0;
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
};

#endif