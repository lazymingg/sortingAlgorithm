#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

class CountingSort {
public:
    CountingSort(int *arr, int n);
    ~CountingSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    void countingSort(int arr[], int n);
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // COUNTINGSORT_H