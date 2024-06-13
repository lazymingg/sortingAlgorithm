#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort {
public:
    MergeSort(int *arr, int n);
    ~MergeSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    void merge(int arr[], int l, int m, int r);
    void mergeSort(int arr[], int l, int r);
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // MERGESORT_H