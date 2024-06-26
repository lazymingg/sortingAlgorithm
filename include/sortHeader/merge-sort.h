#ifndef MERGESORT_H
#define MERGESORT_H
#include <cstdint>
class MergeSort
{
public:
    MergeSort(int *arr, int n);
    ~MergeSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void merge(int *arr, int l, int m, int r);
    void mergeSort(int *arr, int l, int r);

    
    void mergeWithComparisonCount(int *arr, int l, int m, int r);
    void mergeSortWithComparisonCount(int *arr, int l, int r);

    
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
    int64_t comparison = 0;
    double runningTime = 0.0;
};

#endif // MERGESORT_H