#include "../../include/sortHeader/quick-sort.h"
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

int QuickSort::partition(int *arr, int left, int right)
{
    //median of three
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) {
        swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if ( arr[mid] > arr[right]) {
        swap(arr[mid], arr[right]);
    }
    swap(arr[mid], arr[left]);
    
    int pivot = arr[left];
    int inx = left;
    int i = left + 1;
    
    for (i; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[++inx]);
        }
    }
    swap(arr[inx], arr[left]);
    return inx;
}

void QuickSort::quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
int QuickSort::partitionWithComparisonCount(int *arr, int left, int right)
{
    //median of three
    int mid = left + (right - left) / 2;
    if (++this->comparison && arr[left] > arr[mid]) {
        swap(arr[left], arr[mid]);
    }
    if (++this->comparison && arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (++this->comparison && arr[mid] > arr[right]) {
        swap(arr[mid], arr[right]);
    }
    swap(arr[mid], arr[left]);

    int pivot = arr[left];
    int inx = left;
    int i = left + 1;
    for (i; ++this->comparison && i <= right; i++)
    {
        if (++this->comparison && arr[i] < pivot)
        {
            swap(arr[i], arr[++inx]);
        }
    }
    swap(arr[inx], arr[left]);
    return inx;
}

void QuickSort::quickSortWithComparisonCount(int *arr, int left, int right)
{
    if (++this->comparison && left < right)
    {
        int pi = partitionWithComparisonCount(arr, left, right);

        quickSortWithComparisonCount(arr, left, pi - 1);
        quickSortWithComparisonCount(arr, pi + 1, right);
    }
}

uint64_t QuickSort::getComparison()
{
    quickSortWithComparisonCount(this->tempArr, 0, this->size - 1);
    return this->comparison;
}
double QuickSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    quickSort(this->tempArr2, 0, this->size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
