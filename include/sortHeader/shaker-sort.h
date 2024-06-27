#ifndef SHAKERSORT_H
#define SHAKERSORT_H
#include <cstdint>
class ShakerSort
{
public:
    ShakerSort(int *arr, int n);
    ~ShakerSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void ShakerSortRunningTimeCount(int *a, int n);
    void ShakerSortComparisonCount(int *a, int n);
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
    int64_t comparison = 0;
    double runningTime = 0.0;
};

#endif // SHAKERSORT_H