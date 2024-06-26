#ifndef FLASHSORT_H
#define FLASHSORT_H
#include <cstdint>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstring>
class FlashSort
{
public:
    FlashSort(int *arr, int n);
    ~FlashSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void insertionSortComparisonCount(int *arr, int n);
    void flashSortRunningTimeCount(int n, int *a);
    void flashSortComparisonCount(int n, int *a);
    
    double runningTime = 0;
    int64_t comparison = 0;
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
};

#endif