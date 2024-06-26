#include "../../include/sortHeader/insertion-sort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

InsertionSort::InsertionSort(int *arr, int n)
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
InsertionSort::~InsertionSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}
void InsertionSort::insertionSortRunningTimeCount(int *arr, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        for (j = i; j > 0 && key < arr[j - 1]; j--)
            arr[j] = arr[j - 1];

        arr[j] = key;
    }
}
void InsertionSort::insertionSortComparisonCount(int *arr, int n)
{
    int i, j, key;
    for (i = 1; ++this->comparison && i < n; i++)
    {
        key = arr[i];
        for (j = i; ++this->comparison && j > 0 && ++this->comparison && key < arr[j - 1]; j--)
            arr[j] = arr[j - 1];

        arr[j] = key;
    }
}
int64_t InsertionSort::getComparison()
{
    insertionSortComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}
double InsertionSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    insertionSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int* InsertionSort::getTempArr()
{
    return this->tempArr;
}
int* InsertionSort::getTempArr2()
{
    return this->tempArr2;
}
int InsertionSort::getSize()
{
    return this->size;
}