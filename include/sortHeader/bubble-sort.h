#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <cstdint>
class BubbleSort
{
public:
    BubbleSort(int *arr, int n);
    ~BubbleSort();
    int64_t getComparison();
    double getRunningTime();
    int* getTempArr();
    int* getTempArr2();
    int getSize();
private:
    void BubbleSortRunningTimeCount(int *arr, int n);
    void BubbleSortComparisonCount(int *arr, int n);
    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size;
    int64_t comparison = 0;
    double runningTime = 0.0;
};

#endif // BUBBLESORT_H