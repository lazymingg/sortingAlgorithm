#ifndef selectionSort
#define selectionSort

class SelectionSort
{
public:
    SelectionSort(int *arr, int n);
    ~SelectionSort();
    int sortWithComparisonCount();
    double sortWithRunningTimeCount();
    int getComparison();
    double getRunningTime();

private:
    double runningTime = 0;
    int comparison = 0;
    int *tempArr;
    int *tempArr2;
    int size;
};

#endif