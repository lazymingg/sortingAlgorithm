#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

class InsertionSort
{
public:
    InsertionSort(int *arr, int n);
    ~InsertionSort();
    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    double runningTime = 0;
    int comparison = 0;
    int *tempArr;
    int *tempArr2;
    int size;
};

#endif