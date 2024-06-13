#ifndef QUICKSORT_H
#define QUICKSORT_H

class QuickSort {
public:
    QuickSort(int *arr, int n);
    ~QuickSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    void quickSort(int arr[], int low, int high);
    int partition(int arr[], int low, int high);
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // QUICKSORT_H