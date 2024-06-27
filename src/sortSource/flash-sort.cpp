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
void insertionSortRunningTimeCount(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int tmp = a[i];
        while (j >= 0 && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}

int get_class_id(int val, int min_val, int max_val, int idx_m)
{
    if (val == max_val)
        return idx_m - 1;

    double y = (val - min_val) / (max_val - min_val + 0.0);
    return ((int)(idx_m * y));
}

void FlashSort::flashSortRunningTimeCount(int n, int *a)
{
     if (n <= 1) return;
    // tính số lớp cần dùng với công thức m = int(0, 45 * n)
    int min_val = a[0], max_val = a[0], m = int(0.45 * n);

    if (m > 1) {
        // là mảng chứa xem mỗi lớp có vi tri cuoi la ở đâu
        int *l = new int[m]();

        // tim min, max
        for (int i = 1; i < n; i++)
        {
            if (a[i] < min_val)
            {
                min_val = a[i];
            }
            if (a[i] > max_val)
            {
                max_val = a[i];
            }
        }

        // min = max -> chi co 1 gia tri trong mang => return
        if (max_val == min_val) {
            delete[] l;
            return;
        }

        // tìm xem mỗi lớp có bao nhiêu số
        int idx_m = m - 1;
        for (int i = 0; i < n; i++)
        {
            int idx = get_class_id(a[i], min_val, max_val, m);
            l[idx]++;
        }

        // gán lại để biết vitri cuối cua của lớp đó ở đâu trong mảng
        for (int i = 1; i < m; i++)
        {
            l[i] += l[i - 1];
        }

        int cnt = 0, i = 0, id = m - 1;
        while (cnt < n - 1)
        {
            // nếu class id đã được sắp xếp xog -> tăng i để tìm class mới để xét
            while (i >= l[id])
            {
                i++;
                id = get_class_id(a[i], min_val, max_val, m);
            }
            int tmp = a[i];
            // dịch chuyển các số lần lượt về đúng lớp theo thứ tự từ trái qua phải của từng lớp
            while (i < l[id])
            {
                id = get_class_id(tmp, min_val, max_val, m);
                l[id]--;
                swap(&tmp, &a[l[id]]);
                cnt++;
            }
        }
        insertionSortRunningTimeCount(a, n);
        delete[] l;
        return;
    }

    insertionSortRunningTimeCount(a, n);
}

void FlashSort::insertionSortComparisonCount(int *a, int n)
{
    for (int i = 1; ++this->comparison && i < n; i++)
    {
        int j = i - 1;
        int tmp = a[i];
        while (++this->comparison && j >= 0 && ++this->comparison && a[j] > tmp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
}
void FlashSort::flashSortComparisonCount(int n, int *a)
{
     if (++this->comparison && n <= 1) return;
    // tính số lớp cần dùng với công thức m = int(0, 45 * n)
    int min_val = a[0], max_val = a[0], m = int(0.45 * n);
    if (++this->comparison && m > 1) {
        // là mảng chứa xem mỗi lớp có vi tri cuoi la ở đâu
        int *l = new int[m]();

        // tim min, max
        for (int i = 1; ++this->comparison && i < n; i++)
        {
            if (++this->comparison && a[i] < min_val)
            {
                min_val = a[i];
            }
            if (++this->comparison && a[i] > max_val)
            {
                max_val = a[i];
            }
        }

        // min = max -> chi co 1 gia tri trong mang => return
        if (++this->comparison && max_val == min_val) {
            delete[] l;
            return;
        }

        // tìm xem mỗi lớp có bao nhiêu số
        int idx_m = m - 1;
        for (int i = 0; ++this->comparison && i < n; i++)
        {
            int idx = get_class_id(a[i], min_val, max_val, m);
            this->comparison++;
            l[idx]++;
        }

        // gán lại để biết vitri cuoi cua của lớp đó ở đâu trong mảng
        for (int i = 1; ++this->comparison && i < m; i++)
        {
            l[i] += l[i - 1];
        }

        int cnt = 0, i = 0, id = m - 1;
        while (++this->comparison && cnt < n - 1)
        {
            // nếu class id đã được sắp xếp xog -> tăng i để tìm class mới để xét
            while (++this->comparison && i >= l[id])
            {
                i++;
                id = get_class_id(a[i], min_val, max_val, m);
                ++this->comparison;
            }
            int tmp = a[i];
            // dịch chuyển các số lần lượt về đúng lớp theo thứ tự từ trái qua phải của từng lớp
            while (++this->comparison && i < l[id])
            {
                id = get_class_id(tmp, min_val, max_val, m);
                ++this->comparison;
                l[id]--;
                swap(&tmp, &a[l[id]]);
                cnt++;
            }
        }
        insertionSortComparisonCount(a, n);
        delete[] l;
        return;
    }
    
    insertionSortComparisonCount(a, n);

}

int64_t FlashSort::getComparison()
{
    flashSortComparisonCount(this->size, this->tempArr2);
    return this->comparison;
}
double FlashSort::getRunningTime()
{
    // time in mili seconds
    auto start = chrono::high_resolution_clock::now();
    flashSortRunningTimeCount(this->size, this->tempArr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    this->runningTime = duration.count();
    return this->runningTime;
}
int *FlashSort::getTempArr()
{
    return this->tempArr;
}
int *FlashSort::getTempArr2()
{
    return this->tempArr2;
}
int FlashSort::getSize()
{
    return this->size;
}