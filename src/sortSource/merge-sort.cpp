#include "../../include/sortHeader/merge-sort.h"
#include <iostream>
#include <chrono>

#include <algorithm>
using namespace std;

MergeSort::MergeSort(int *arr, int n)
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

MergeSort::~MergeSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

void MergeSort::merge(int *arr, int left, int mid, int right)
{
    int const leftSubArraySize = mid - left + 1;
    int const rightSubArraySize = right - mid;
    // divide the array into two subarray
    int *leftArr = new int[leftSubArraySize];
    int *rightArr = new int[rightSubArraySize];

    //copy elements frome mother array to chilldern arr
    for (int i = 0; i < leftSubArraySize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSubArraySize; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    //merge the two subarray
    int leftIndex = 0;
    int rightIndex = 0;
    int arrIndex = left;

    while(leftIndex < leftSubArraySize && rightIndex < rightSubArraySize)
    {
        if(leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }
    //copy the remaining elements

    while(leftIndex < leftSubArraySize)
    {
        arr[arrIndex] = leftArr[leftIndex];
        leftIndex++;
        arrIndex++;
    }
    while(rightIndex < rightSubArraySize)
    {
        arr[arrIndex] = rightArr[rightIndex];
        rightIndex++;
        arrIndex++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
void MergeSort::mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void MergeSort::mergeWithComparisonCount(int *arr, int left, int mid, int right)
{
    int const leftSubArraySize = mid - left + 1;
    int const rightSubArraySize = right - mid;
    // divide the array into two subarray
    int *leftArr = new int[leftSubArraySize];
    int *rightArr = new int[rightSubArraySize];

    // copy elements frome mother array to chilldern arr
    for (int i = 0; ++this->comparison && i < leftSubArraySize; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; ++this->comparison && i < rightSubArraySize; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    // merge the two subarray
    int leftIndex = 0;
    int rightIndex = 0;
    int arrIndex = left;

    while (++this->comparison && leftIndex < leftSubArraySize && rightIndex < rightSubArraySize)
    {
        if (++this->comparison && leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[arrIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[arrIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        arrIndex++;
    }
    // copy the remaining elements

    while (++this->comparison && leftIndex < leftSubArraySize)
    {
        arr[arrIndex] = leftArr[leftIndex];
        leftIndex++;
        arrIndex++;
    }
    while (++this->comparison && rightIndex < rightSubArraySize)
    {
        arr[arrIndex] = rightArr[rightIndex];
        rightIndex++;
        arrIndex++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
void MergeSort::mergeSortWithComparisonCount(int *arr, int l, int r)
{
    if (++this->comparison && l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSortWithComparisonCount(arr, l, mid);
        mergeSortWithComparisonCount(arr, mid + 1, r);
        mergeWithComparisonCount(arr, l, mid, r);
    }
}



int64_t MergeSort::getComparison()
{
    mergeSortWithComparisonCount(this->tempArr2, 0, this->size - 1);
    return this->comparison;
}
double MergeSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    mergeSort(this->tempArr, 0, this->size - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int *MergeSort::getTempArr()
{
    return this->tempArr;
}
int *MergeSort::getTempArr2()
{
    return this->tempArr2;
}
int MergeSort::getSize()
{
    return this->size;
}