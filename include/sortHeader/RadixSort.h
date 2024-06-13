#ifndef RADIXSORT_H
#define RADIXSORT_H

class RadixSort {
public:
    RadixSort(int *arr, int n);
    ~RadixSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    int getMax(int arr[], int n);
    void countSort(int arr[], int n, int exp);
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // RADIXSORT_H