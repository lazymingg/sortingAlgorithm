#include "../../include/sortHeader/shaker-sort.h"
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdint>
using namespace std;

ShakerSort::ShakerSort(int *arr, int n)
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

ShakerSort::~ShakerSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}


void ShakerSort::ShakerSortRunningTimeCount(int *a, int n)
{
    bool swapped = 1;
    int start = 0, end = n - 1;
    int i;

    while (swapped) {
        swapped = 0;

        for (i = start; i < end; i++)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        end--;

        if (!swapped) break;

        swapped = 0;
        for (i; i > start; i--)
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                swapped = 1;
            }
        start++;
    }
}


void ShakerSort::ShakerSortComparisonCount(int *a, int n)
{
    bool swapped = 1;
    int start = 0, end = n - 1;
    int i;

    while (++this->comparison && swapped) {
        swapped = 0;

        for (i = start; ++this->comparison && i < end; i++)
            if (++this->comparison &&  a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        end--;

        if (!swapped) break;

        swapped = 0;
        for (i; ++this->comparison &&  i > start; i--)
            if (++this->comparison &&  a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                swapped = 1;
            }
        start++;
    }
}

int64_t ShakerSort::getComparison()
{
    ShakerSortComparisonCount(this->tempArr2, this->size);
    return this->comparison;
}

double ShakerSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    ShakerSortRunningTimeCount(this->tempArr, this->size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

int* ShakerSort::getTempArr()
{
    return this->tempArr;
}
int* ShakerSort::getTempArr2()
{
    return this->tempArr2;
}
int ShakerSort::getSize()
{
    return this->size;
}