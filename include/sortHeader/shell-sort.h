#ifndef SHELLSORT_H
#define SHELLSORT_H

class ShellSort {
public:
    ShellSort(int *arr, int n);
    ~ShellSort();

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

#endif // SHELLSORT_H