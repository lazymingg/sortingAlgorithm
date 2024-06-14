#include "../../include/sortHeader/InsertionSort.h"
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
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void InsertionSort::insertionSortComparisonCount(int *arr, int n)
{
    for (int i = 1; ++this->comparison && i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (++this->comparison && j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int64_t InsertionSort::getComparison()
{
    insertionSortComparisonCount(this->tempArr, this->size);
    return this->comparison;
}
double InsertionSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    insertionSortRunningTimeCount(this->tempArr2, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
