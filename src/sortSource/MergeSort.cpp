#include "../../include/sortHeader/MergeSort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
using namespace std;

MergeSort::MergeSort(int *arr, int n)
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

MergeSort::~MergeSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}

void MergeSort::merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparison++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int MergeSort::sortWithComparisonCount()
{
    mergeSort(tempArr, 0, size - 1);
    return comparison;
}

double MergeSort::sortWithRunningTimeCount()
{
    auto start = std::chrono::system_clock::now();
    mergeSort(tempArr2, 0, size - 1);
    auto end = std::chrono::system_clock::now();
    runningTime = chrono::duration<double, milli>(end - start).count();
    return runningTime;
}

int MergeSort::getComparison()
{
    return comparison;
}

double MergeSort::getRunningTime()
{
    return runningTime;
}