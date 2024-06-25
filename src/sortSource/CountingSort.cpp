#include "../../include/sortHeader/CountingSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>

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

void CountingSort::countingSort(int arr[], int n)
{
    int max = *max_element(arr, arr+n);
    int min = *min_element(arr, arr+n);
    int range = max - min + 1;

    vector<int> count(range), output(n);
    for(int i = 0; i < n; i++)
    {
        count[arr[i]-min]++;
    }

    for(int i = 1; i < count.size(); i++)
    {
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; i--)
    {
        output[ count[arr[i]-min] -1 ] = arr[i];
        count[arr[i]-min]--;
    }

    for(int i=0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int CountingSort::sortWithComparisonCount()
{
    countingSort(tempArr, size);
    return comparison;
}

double CountingSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    countingSort(tempArr2, size);
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int CountingSort::getComparison()
{
    return comparison;
}

double CountingSort::getRunningTime()
{
    return runningTime;
}