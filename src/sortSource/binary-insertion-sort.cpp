#include "../../include/sortHeader/binary-insertion-sort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

BinaryInsertionSort::BinaryInsertionSort(int *arr, int n)
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

BinaryInsertionSort::~BinaryInsertionSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

int BinaryInsertionSort::BinarySearchRunningTimeCount(int* a, int item, int left, int right)
{
    while (right > left) {
        int mid = (right + left) / 2;
        if (item == a[mid]) return mid + 1;
        if (item > a[mid]) left = mid + 1;
        else right = mid - 1;
    }
    
    return (item > a[left]) ? (left + 1) : left;
}

void BinaryInsertionSort::BinaryInsertionSortRunningTimeCount(int *arr, int n)
{
    int i, j, index, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        index = BinarySearchRunningTimeCount(arr, arr[i], 0, i - 1);

        for (j = i; j > index; j--)
            arr[j] = arr[j - 1];

        arr[index] = key;
    }
}

int BinaryInsertionSort::BinarySearchWithComparisons(int* a, int item, int left, int right)
{
    while (++this->comparison && right > left) {
        int mid = (right + left) / 2;
        if (++this->comparison && item == a[mid]) return mid + 1;
        if (++this->comparison && item > a[mid]) left = mid + 1;
        else right = mid - 1;
    }
    
    return (++this->comparison && item > a[left]) ? (left + 1) : left;
}

void BinaryInsertionSort::BinaryInsertionSortComparisonCount(int *arr, int n)
{
    int i, j, index, key;

    for (i = 1; ++this->comparison &&  i < n; i++)
    {
        key = arr[i];
        index = BinarySearchWithComparisons(arr, arr[i], 0, i - 1);

        for (j = i; ++this->comparison && j > index; j--)
            arr[j] = arr[j - 1];

        arr[index] = key;
    }
}

int64_t BinaryInsertionSort::getComparison()
{
    BinaryInsertionSortComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}

double BinaryInsertionSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    BinaryInsertionSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}

int* BinaryInsertionSort::getTempArr()
{
    return this->tempArr;
}

int* BinaryInsertionSort::getTempArr2()
{
    return this->tempArr2;
}

int BinaryInsertionSort::getSize()
{
    return this->size;
}