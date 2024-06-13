#include "../include/InsertionSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

InsertionSort::InsertionSort(int *arr, int n)
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
InsertionSort::~InsertionSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}
int InsertionSort::sortWithComparisonCount()
{
    for (int i = 1; i < size; i++)
    {
        int key = tempArr[i];
        int j = i - 1;
        while (j >= 0 && tempArr[j] > key)
        {
            comparison++;
            tempArr[j + 1] = tempArr[j];
            j = j - 1;
        }
        tempArr[j + 1] = key;
    }
    return comparison;
}
double InsertionSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    for (int i = 1; i < size; i++)
    {
        int key = tempArr2[i];
        int j = i - 1;
        while (j >= 0 && tempArr2[j] > key)
        {
            tempArr2[j + 1] = tempArr2[j];
            j = j - 1;
        }
        tempArr2[j + 1] = key;
    }
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}
int InsertionSort::getComparison()
{
    return comparison;
}
double InsertionSort::getRunningTime()
{
    return runningTime;
}
