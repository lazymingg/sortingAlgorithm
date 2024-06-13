#include "../../include/sortHeader/BubbleSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
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

int BubbleSort::sortWithComparisonCount()
{
    for (int i = 0; i < size-1; i++)      
        for (int j = 0; j < size-i-1; j++) 
            if (tempArr[j] > tempArr[j+1])
            {
                comparison++;
                swap(tempArr[j], tempArr[j+1]);
            }
    return comparison;
}

double BubbleSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < size-1; i++)      
        for (int j = 0; j < size-i-1; j++) 
            if (tempArr2[j] > tempArr2[j+1])
                swap(tempArr2[j], tempArr2[j+1]);
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int BubbleSort::getComparison()
{
    return comparison;
}

double BubbleSort::getRunningTime()
{
    return runningTime;
}