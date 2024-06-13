#include "../../include/sortHeader/ShellSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

ShellSort::ShellSort(int *arr, int n)
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

ShellSort::~ShellSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

int ShellSort::sortWithComparisonCount()
{
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = tempArr[i];
            int j;           
            for (j = i; j >= gap && tempArr[j - gap] > temp; j -= gap)
            {
                comparison++;
                tempArr[j] = tempArr[j - gap];
            }
            tempArr[j] = temp;
        }
    }
    return comparison;
}

double ShellSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = tempArr2[i];
            int j;           
            for (j = i; j >= gap && tempArr2[j - gap] > temp; j -= gap)
            {
                tempArr2[j] = tempArr2[j - gap];
            }
            tempArr2[j] = temp;
        }
    }
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int ShellSort::getComparison()
{
    return comparison;
}

double ShellSort::getRunningTime()
{
    return runningTime;
}