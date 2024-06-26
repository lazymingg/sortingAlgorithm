#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <cstdint>
class ShellSort
{
public:
    ShellSort(int *arr, int n);
    ~ShellSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void ShellSortRunningTimeCount(int *arr, int n);
    void ShellSortComparisonCount(int *arr, int n);
    double runningTime = 0;
    int64_t comparison = 0;
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
};

#endif