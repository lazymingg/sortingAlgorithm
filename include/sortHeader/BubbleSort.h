#ifndef BUBBLESORT_H
#define BUBBLESORT_H

class BubbleSort {
public:
    BubbleSort(int *arr, int n);
    ~BubbleSort();

    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    int *tempArr;
    int *tempArr2;
    int size;
    int comparison = 0;
    double runningTime = 0.0;
};

#endif // BUBBLESORT_H