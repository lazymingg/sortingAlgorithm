#include "../../include/sortHeader/selection-sort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdint>
using namespace std;

SelectionSort::SelectionSort(int *arr, int n)
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
SelectionSort::~SelectionSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

void SelectionSort::selectionSortRunningTimeCount(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void SelectionSort::selectionSortComparionCount(int *arr, int n)
{
    for (int i = 0; ++this->comparison && i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; ++this->comparison && j < n; j++)
        {
            if (++this->comparison && arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
double SelectionSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    selectionSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int64_t SelectionSort::getComparison()
{
    selectionSortComparionCount(this->tempArr2, this->size);
    return this->comparison;
}
int *SelectionSort::getTempArr()
{
    return this->tempArr;
}
int *SelectionSort::getTempArr2()
{
    return this->tempArr2;
}
int SelectionSort::getSize()
{
    return this->size;
}
