#include "../../include/sortHeader/BubbleSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdint>
using namespace std;

BubbleSort::BubbleSort(int *arr, int n)
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

BubbleSort::~BubbleSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}
void BubbleSort::BubbleSortRunningTimeCount(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void BubbleSort::BubbleSortComparisonCount(int *arr, int n)
{
    for (int i = 0; ++this->comparison && i < n - 1; i++)
    {
        for (int j = 0; ++this->comparison && j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int64_t BubbleSort::getComparison()
{
    BubbleSortComparisonCount(this->tempArr, this->size);
    return this->comparison;
}

double BubbleSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    BubbleSortRunningTimeCount(this->tempArr2, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}