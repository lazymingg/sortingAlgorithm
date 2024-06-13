#ifndef HEAPSORT_H
#define HEAPSORT_H

class HeapSort {
public:
    HeapSort(int *arr, int n);
    ~HeapSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    void heapify(int arr[], int n, int i);
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // HEAPSORT_H