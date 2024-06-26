#ifndef BINARYINSERTIONSORT_H
#define BINARYINSERTIONSORT_H
#include <cstdint>
class BinaryInsertionSort
{
public:
    BinaryInsertionSort(int *arr, int n);
    ~BinaryInsertionSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    int BinarySearchRunningTimeCount(int* a, int item, int left, int right);
    void BinaryInsertionSortRunningTimeCount(int *arr, int n);
    int BinarySearchWithComparisons(int* a, int item, int left, int right);
    void BinaryInsertionSortComparisonCount(int *arr, int n);
    double runningTime = 0;
    int64_t comparison = 0;
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
};

#endif