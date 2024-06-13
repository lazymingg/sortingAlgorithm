#include "../../include/sortHeader/HeapSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

HeapSort::HeapSort(int *arr, int n)
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

HeapSort::~HeapSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

void HeapSort::heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int HeapSort::sortWithComparisonCount()
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(tempArr, size, i);

    for (int i=size-1; i>=0; i--)
    {
        swap(tempArr[0], tempArr[i]);
        heapify(tempArr, i, 0);
        comparison++;
    }
    return comparison;
}

double HeapSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(tempArr2, size, i);

    for (int i=size-1; i>=0; i--)
    {
        swap(tempArr2[0], tempArr2[i]);
        heapify(tempArr2, i, 0);
    }
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int HeapSort::getComparison()
{
    return comparison;
}

double HeapSort::getRunningTime()
{
    return runningTime;
}