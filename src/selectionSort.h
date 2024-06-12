#ifndef selectionSort
#define selectionSort

#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;



class SelectionSort {
public:
    SelectionSort(int* arr, int n);
    ~SelectionSort();
    int sortWithComparisonCount();
    int sortWithRunningTimeCount();
    int getComparison();
    int getRunningTime();
private:
    int runningTime = 0;
    int comparison = 0;
    int* tempArr;
    int* tempArr2;
    int size;
};

#endif