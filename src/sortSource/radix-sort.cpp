#include "../../include/sortHeader/radix-sort.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
// ratdix sort reference: https://www.geeksforgeeks.org/radix-sort/
RadixSort::RadixSort(int *arr, int n)
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

RadixSort::~RadixSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

int RadixSort::getMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void RadixSort::countSort(int *arr, int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
}

void RadixSort::radixSort(int *arr, int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int RadixSort::getMaxWithComparisonCount(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; ++this->comparison && i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void RadixSort::countSortWithComparisonCount(int *arr, int size, int digit)
{
    int *resArr = new int[size];
    int count[10] = {0};

    for (int i = 0; ++this->comparison && i < size; i++)
    {
        count[(arr[i] / digit) % 10]++;
    }

    for (int i = 1; ++this->comparison && i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; ++this->comparison && i >= 0; i--)
    {
        resArr[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for (int i = 0; ++this->comparison && i < size; i++)
    {
        arr[i] = resArr[i];
    }

    delete[] resArr;
}

void RadixSort::radixSortWithComparisonCount(int *arr, int size)
{
    int max = getMaxWithComparisonCount(arr, size);
    for (int digit = 1; ++this->comparison && max / digit > 0; digit *= 10)
    {
        countSortWithComparisonCount(arr, size, digit);
    }
}

int64_t RadixSort::getComparison()
{
    this->comparison = 0;
    radixSortWithComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}

double RadixSort::getRunningTime()
{
    auto start = chrono::high_resolution_clock::now();
    radixSort(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int *RadixSort::getTempArr()
{
    return this->tempArr;
}
int *RadixSort::getTempArr2()
{
    return this->tempArr2;
}
int RadixSort::getSize()
{
    return this->size;
}