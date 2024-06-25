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

int QuickSort::partition(int *arr, int left, int right)
{
    //middleof three
    int mid = left + (right - left) / 2;
    if (arr[mid] < arr[left])
    {
        swap(arr[mid], arr[left]);
    }
    if (arr[right] < arr[left])
    {
        swap(arr[right], arr[left]);
    }
    if (arr[mid] < arr[right])
    {
        swap(arr[mid], arr[right]);
    }
    
    int pivot = arr[right];
    int inx = left;
    
    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[inx]);
            inx++;
        }
    }
    swap(arr[inx], arr[right]);
    return inx;
}
void insertionSort(int *arr, int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void QuickSort::quickSort(int *arr, int left, int right)
{
    if (right - left <= 10)
    {
        insertionSort(arr, right - left + 1);
        return;
    }
    else
    {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}
int QuickSort::partitionWithComparisonCount(int *arr, int left, int right)
{
    //middleof three
    int mid = left + (right - left) / 2;
    if (++this->comparison && arr[mid] < arr[left])
    {
        swap(arr[mid], arr[left]);
    }
    if (++this->comparison && arr[right] < arr[left])
    {
        swap(arr[right], arr[left]);
    }
    if (++this->comparison && arr[mid] < arr[right])
    {
        swap(arr[mid], arr[right]);
    }
    int pivot = arr[right];
    int inx = left;
    
    for (int i = left; ++this->comparison && i < right; i++)
    {
        if (++this->comparison && arr[i] < pivot)
        {
            swap(arr[i], arr[inx]);
            inx++;
        }
    }
    swap(arr[inx], arr[right]);
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

int64_t QuickSort::getComparison()
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
