#ifndef COUNTINGSORT_H 
#define COUNTINGSORT_H 
#include <cstdint>
class CountingSort
{
public:
    CountingSort(int *arr, int n);
    ~CountingSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void countingSortRunningTimeCount(int n, int *arr);
    void countingSortComparisonCount(int n, int *arr);
    int findMaxTimeCount(int* arr, int n);
    int findMaxComparisonCount(int* arr, int n);
    double runningTime = 0;
    int64_t comparison = 0;
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
};

#endif