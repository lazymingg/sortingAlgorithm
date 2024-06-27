#include "../../include/sortHeader/counting-sort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

CountingSort::CountingSort(int *arr, int n)
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
CountingSort::~CountingSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

int CountingSort::findMaxTimeCount(int*arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (max < arr[i]) max = arr[i];
    return max;
}

int CountingSort::findMaxComparisonCount(int*arr, int n)
{
    int max = arr[0];
    for (int i = 1; ++this->comparison && i < n; ++i)
        if (++this->comparison && max < arr[i]) max = arr[i];
    return max;
}

void CountingSort::countingSortRunningTimeCount(int n, int *arr)
{
     if (n <= 1) return;
    int max = CountingSort::findMaxTimeCount(arr, n);
    int* count = new int[max + 1]();

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    //make prefix sum
    for (int i = 1; i <= max; ++i)
    {
        count[i] += count[i - 1];
    }

    int* output = new int[n]();

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void CountingSort::countingSortComparisonCount(int n, int *arr)
{
    if (++this->comparison && n <= 1) return;
    int i, j, key;
    int max = CountingSort::findMaxTimeCount(arr, n);
    int* count = new int[max + 1]();

    for (int i = 0; ++this->comparison && i < n; ++i)
    {
        count[arr[i]]++;
    }

    //make prefix sum
    for (int i = 1; ++this->comparison && i <= max; ++i)
    {
        count[i] += count[i - 1];
    }

    int* output = new int[n];

    for (int i = n - 1; ++this->comparison && i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; ++this->comparison && i < n; ++i)
    {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

int64_t CountingSort::getComparison()
{
    countingSortComparisonCount(this->size, this->tempArr2);
    return this->comparison;
}
double CountingSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    countingSortRunningTimeCount(this->size, this->tempArr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int* CountingSort::getTempArr()
{
    return this->tempArr;
}
int* CountingSort::getTempArr2()
{
    return this->tempArr2;
}
int CountingSort::getSize()
{
    return this->size;
}