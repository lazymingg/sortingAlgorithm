#include "../../include/sortHeader/selectionSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
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

int SelectionSort::sortWithComparisonCount()
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparison++;
            if (tempArr[j] < tempArr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(tempArr[i], tempArr[minIndex]);
    }
    return comparison;
}
double SelectionSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tempArr2[j] < tempArr2[minIndex])
            {
                minIndex = j;
            }
        }
        swap(tempArr2[i], tempArr2[minIndex]);
    }

    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}
double SelectionSort::getRunningTime()
{
    return sortWithRunningTimeCount();
}
int SelectionSort::getComparison()
{
    return sortWithComparisonCount();
}