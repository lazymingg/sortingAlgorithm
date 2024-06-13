#include "../../include/sortHeader/RadixSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

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

int RadixSort::getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void RadixSort::countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int RadixSort::sortWithComparisonCount()
{
    int m = getMax(tempArr, size);

    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(tempArr, size, exp);
        comparison++;
    }
    return comparison;
}

double RadixSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    int m = getMax(tempArr2, size);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(tempArr2, size, exp);

    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int RadixSort::getComparison()
{
    return comparison;
}

double RadixSort::getRunningTime()
{
    return runningTime;
}