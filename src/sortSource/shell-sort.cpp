#include "../../include/sortHeader/shell-sort.h"
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
void ShellSort::ShellSortRunningTimeCount(int *arr, int n)
{
    int i, j, gap, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}
void ShellSort::ShellSortComparisonCount(int *arr, int n)
{
    int i, j, gap, temp;

    for (gap = n / 2; ++this->comparison && gap > 0; gap /= 2)
    {
        for (i = gap; ++this->comparison && i < n; i++) 
        {
            temp = arr[i];

            for (j = i; ++this->comparison && j >= gap && ++this->comparison && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}
int64_t ShellSort::getComparison()
{
    ShellSortComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}
double ShellSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    ShellSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int* ShellSort::getTempArr()
{
    return this->tempArr;
}
int* ShellSort::getTempArr2()
{
    return this->tempArr2;
}
int ShellSort::getSize()
{
    return this->size;
}