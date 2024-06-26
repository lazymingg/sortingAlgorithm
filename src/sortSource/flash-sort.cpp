#include "../../include/sortHeader/flash-sort.h"

using namespace std;

FlashSort::FlashSort(int *arr, int n)
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

FlashSort::~FlashSort()
{
    delete[] tempArr;
    delete[] tempArr2;
}
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void FlashSort::flashSortRunningTimeCount(int n, int *a)
{
    int min_val = a[0], max = 0, m = int(0.45 * n);
    int *l = new int[m];
    memset(l, 0, m);

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_val)
        {
            min_val = a[i];
            continue;
        }
        if (a[i] > a[max])
        {
            max = i;
        }
    }

    if (a[max] == min_val)
        return;

    double gap = (m - 1.0) / (a[max] - min_val);

    int k;
    for (int i = 0; i < n; i++)
    {
        k = int(gap * (a[i] - min_val));
        l[k]++;
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    swap(&a[max], &a[0]);
    int move = 0, j = 0, t = 0, flash;
    k = m - 1;
    while (move < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(gap * (a[j] - min_val));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != l[k])
        {
            k = int(gap * (flash - min_val));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++move;
        }
    }

    delete[] l;
}
void FlashSort::flashSortComparisonCount(int n, int *a)
{
    int min_val = a[0], max = 0, m = int(0.45 * n);
    int *l = new int[m];
    memset(l, 0, m);

    for (int i = 1; ++this->comparison && i < n; i++)
    {
        if (++this->comparison && a[i] < min_val)
        {
            min_val = a[i];
            continue;
        }
        if (++this->comparison && a[i] > a[max])
        {
            max = i;
        }
    }

    if (++this->comparison && a[max] == min_val)
        return;

    double gap = (m - 1.0) / (a[max] - min_val);

    int k;
    for (int i = 0; ++this->comparison && i < n; i++)
    {
        k = int(gap * (a[i] - min_val));
        l[k]++;
    }
    for (int i = 1; ++this->comparison && i < m; i++)
        l[i] += l[i - 1];

    swap(&a[max], &a[0]);
    int move = 0, j = 0, t = 0, flash;
    k = m - 1;
    while (++this->comparison && move < n - 1)
    {
        while (++this->comparison && j > l[k] - 1)
        {
            j++;
            k = int(gap * (a[j] - min_val));
        }
        flash = a[j];
        if (++this->comparison && k < 0)
            break;
        while (++this->comparison && j != l[k])
        {
            k = int(gap * (flash - min_val));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++move;
        }
    }

    delete[] l;
}
int64_t FlashSort::getComparison()
{
    flashSortComparisonCount(this->size, this->tempArr);
    return this->comparison;
}
double FlashSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    flashSortRunningTimeCount(this->size, this->tempArr2);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int* FlashSort::getTempArr()
{
    return this->tempArr;
}
int* FlashSort::getTempArr2()
{
    return this->tempArr2;
}
int FlashSort::getSize()
{
    return this->size;
}