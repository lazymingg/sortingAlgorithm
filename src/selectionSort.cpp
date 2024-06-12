#include "selectionSort.h"

class SelectionSort {
private:
    int runningTime = 0;
    int comparison = 0;
    int* tempArr;
    int* tempArr2;
    int size;

public:
    SelectionSort(int* arr, int n)
    {
        this->size = n;
        this->tempArr = new int[n];
        this->tempArr2 = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->tempArr[i] = arr[i];
            this->tempArr2[i] = arr[i];
        }

        comparison = sortWithComparisonCount();
        runningTime = sortWithRunningTimeCount();
    }
    ~SelectionSort()
    {
        delete[] tempArr;
        delete[] tempArr2;
    }

    int sortWithComparisonCount()
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
    int sortWithRunningTimeCount()
    {
        auto start = std::chrono::high_resolution_clock::now();
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
        auto end = std::chrono::high_resolution_clock::now();
        runningTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        return runningTime;
    }
    int getRunningTime()
    {
        return runningTime;
    }
    int getComparison()
    {
        return comparison;
    }
};