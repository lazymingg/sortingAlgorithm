#include "../../include/sortHeader/heap-sort.h"
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

void HeapSort::heapify(int *arr, int current, int size)
{
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    //if left child is larger than root
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    //if right child is larger than root
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    //if largest is not root
    if (largest != current)
    {
        swap(arr[current], arr[largest]);
        heapify(arr, largest, size);
    }
}

void HeapSort::heapSort(int *arr, int size)
{
    //build heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, size);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
void HeapSort::heapifyWithComparisonCount(int *arr, int current, int size)
{
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    //if left child is larger than root
    if (++this->comparison && left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    //if right child is larger than root
    if (++this->comparison && right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    //if largest is not root
    if (++this->comparison && largest != current)
    {
        swap(arr[current], arr[largest]);
        heapifyWithComparisonCount(arr, largest, size);
    }
}
void HeapSort::heapSortWithComparisonCount(int *arr, int size)
{
    //build heap
    for (int i = size / 2 - 1; ++this->comparison && i >= 0; i--)
    {
        heapifyWithComparisonCount(arr, i, size);
    }
    for (int i = size - 1; ++this->comparison && i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifyWithComparisonCount(arr, 0, i);
    }
}

int64_t HeapSort::getComparison()
{
    heapSortWithComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}
double HeapSort::getRunningTime()
{
    // res in miliseconds
    auto start = chrono::high_resolution_clock::now();
    heapSort(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int* HeapSort::getTempArr()
{
    return this->tempArr;
}
int* HeapSort::getTempArr2()
{
    return this->tempArr2;
}
int HeapSort::getSize()
{
    return this->size;
}