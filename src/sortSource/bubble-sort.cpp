#include "../../include/sortHeader/bubble-sort.h"
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
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            // If no elements were swapped in the inner loop, the array is already sorted
            break;
        }
    }
}
void BubbleSort::BubbleSortComparisonCount(int *arr, int n)
{
    bool swapped;
    for (int i = 0; ++this->comparison && i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; ++this->comparison && j < n - i - 1; j++)
        {
            if (++this->comparison && arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (++this->comparison && !swapped)
        {
            // If no elements were swapped in the inner loop, the array is already sorted
            break;
        }
    }
}
int64_t BubbleSort::getComparison()
{
    BubbleSortComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}

double BubbleSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    BubbleSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

int* BubbleSort::getTempArr()
{
    return this->tempArr;
}
int* BubbleSort::getTempArr2()
{
    return this->tempArr2;
}
int BubbleSort::getSize()
{
    return this->size;
}