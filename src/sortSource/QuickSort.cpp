#include "../../include/sortHeader/QuickSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

QuickSort::QuickSort(int *arr, int n)
{
    this->size = n;
    this->tempArr = new int[n];
    this->tempArr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->tempArr[i] = arr[i];
        this->tempArr2[i] = arr[i];
    }
}

QuickSort::~QuickSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

int QuickSort::partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            comparison++;
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort::quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int QuickSort::sortWithComparisonCount()
{
    quickSort(tempArr, 0, size - 1);
    return comparison;
}

double QuickSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    quickSort(tempArr2, 0, size - 1);
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int QuickSort::getComparison()
{
    return comparison;
}

double QuickSort::getRunningTime()
{
    return runningTime;
}