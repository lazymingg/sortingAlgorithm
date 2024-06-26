#ifndef selectionSort
#define selectionSort
#include <cstdint>
class SelectionSort
{
public:
    SelectionSort(int *arr, int n);
    ~SelectionSort();
    void selectionSortRunningTimeCount(int *arr, int n);
    void selectionSortComparionCount(int *arr, int n);
    int64_t getComparison();
    double getRunningTime();
    
    // get tempArr
    int *getTempArr();
    // get tempArr2
    int *getTempArr2();
    // get size
    int getSize();

private:
    double runningTime = 0;
    int64_t comparison = 0;

    int *tempArr = NULL;
    int *tempArr2 = NULL;
    int size = 0;
};

#endif