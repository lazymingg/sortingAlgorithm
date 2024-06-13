#include "../include/Controller.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

bool isDigit(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

/*------------------- enum class to string ------------------*/
string sortingAlgorithmToString(SortingAlgorithm algo)
{
    switch (algo)
    {
    case SortingAlgorithm::SELECTION_SORT:
        return "Selection Sort";
    case SortingAlgorithm::INSERTION_SORT:
        return "Insertion Sort";
    case SortingAlgorithm::SHELL_SORT:
        return "Shell Sort";
    case SortingAlgorithm::BUBBLE_SORT:
        return "Bubble Sort";
    case SortingAlgorithm::HEAP_SORT:
        return "Heap Sort";
    case SortingAlgorithm::MERGE_SORT:
        return "Merge Sort";
    case SortingAlgorithm::QUICK_SORT:
        return "Quick Sort";
    case SortingAlgorithm::RADIX_SORT:
        return "Radix Sort";
    case SortingAlgorithm::COUNTING_SORT:
        return "Counting Sort";
    case SortingAlgorithm::NONE:
        return "None";
    default:
        return "Unknown Algorithm";
    }
}

string inputOrderToString(InputOrder order)
{
    switch (order)
    {
    case InputOrder::RAND:
        return "Random";
    case InputOrder::NSORTED:
        return "Nearly Sorted";
    case InputOrder::SORTED:
        return "Sorted";
    case InputOrder::REV:
        return "Reversed";
    case InputOrder::NONE:
        return "None";
    }
}

string outputParameterToString(OutputParameter param)
{
    switch (param)
    {
    case OutputParameter::TIME:
        return "Time";
    case OutputParameter::COMP:
        return "Comparisons";
    case OutputParameter::BOTH:
        return "Both";
    case OutputParameter::NONE:
        return "None";
    }
}

/*--------------------file Handling Funtion------------------*/
int *Controller::readFile()
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return nullptr;
    }
    vector<int> v;
    int num;
    while (file >> num)
    {
        v.push_back(num);
    }
    this->size = v.size();
    int *arr = new int[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
        arr[i] = v[i];
    }
    return arr;
}

/*----------------------Setter Funtion----------------------*/
void Controller::setAlgorithm(char *argv)
{
    if (strcmp(argv, "selection-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::SELECTION_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::SELECTION_SORT;
    }
    else if (strcmp(argv, "insertion-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::INSERTION_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::INSERTION_SORT;
    }
    else if (strcmp(argv, "shell-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::SHELL_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::SHELL_SORT;
    }
    else if (strcmp(argv, "bubble-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::BUBBLE_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::BUBBLE_SORT;
    }
    else if (strcmp(argv, "heap-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::HEAP_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::HEAP_SORT;
    }
    else if (strcmp(argv, "merge-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::MERGE_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::MERGE_SORT;
    }
    else if (strcmp(argv, "quick-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::QUICK_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::QUICK_SORT;
    }
    else if (strcmp(argv, "radix-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::RADIX_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::RADIX_SORT;
    }
    else if (strcmp(argv, "counting-sort") == 0)
    {
        if (this->algorithmParam1 != SortingAlgorithm::NONE)
            this->algorithmParam2 = SortingAlgorithm::COUNTING_SORT;
        else
            this->algorithmParam1 = SortingAlgorithm::COUNTING_SORT;
    }
}

void Controller::setOutputParameter(char *argv)
{
    if (strcmp(argv, "-time") == 0)
    {
        this->outputParam = OutputParameter::TIME;
    }
    else if (strcmp(argv, "-comp") == 0)
    {
        this->outputParam = OutputParameter::COMP;
    }
    else if (strcmp(argv, "-both") == 0)
    {
        this->outputParam = OutputParameter::BOTH;
    }
}

void Controller::setInputOrder(char *argv)
{
    if (strcmp(argv, "-rand") == 0)
    {
        inputOrderParam = InputOrder::RAND;
    }
    else if (strcmp(argv, "-nsorted") == 0)
    {
        inputOrderParam = InputOrder::NSORTED;
    }
    else if (strcmp(argv, "-sorted") == 0)
    {
        inputOrderParam = InputOrder::SORTED;
    }
    else if (strcmp(argv, "-rev") == 0)
    {
        inputOrderParam = InputOrder::REV;
    }
}

void Controller::setData()
{
    if (fileName != "")
    {
        fileData = readFile();
    }
    switch (this->inputOrderParam)
    {
    case InputOrder::RAND:
        this->randomData = GenerateRandomData(this->size);
        break;
    case InputOrder::NSORTED:
        this->nsortedData = GenerateNearlySortedData(this->size);
        break;
    case InputOrder::SORTED:
        this->sortedData = GenerateSortedData(this->size);
        break;
    case InputOrder::REV:
        this->revData = GenerateReverseData(this->size);
        break;

    case InputOrder::NONE:
        // do all
        this->randomData = GenerateRandomData(this->size);
        this->nsortedData = GenerateNearlySortedData(this->size);
        this->sortedData = GenerateSortedData(this->size);
        this->revData = GenerateReverseData(this->size);
        break;
    }
}

/*----------------------Constructor and Destructor----------------------*/
Controller::Controller(int argc, char *argv[])
{
    if (isDigit(argv[3]))
    {
        this->size = atoi(argv[3]);
    }
    else
    {
        this->fileName = argv[3];
    }
    for (int i = 2; i < argc; i++)
    {
        // Define algorithm
        setAlgorithm(argv[i]);
        // Define output parameter
        setOutputParameter(argv[i]);
        // Define input order
        setInputOrder(argv[i]);
    }
    if (fileName != "")
    {
        fileData = readFile();
    }
    else
    {
        setData();
    }
}

Controller::~Controller()
{
    // dealocate memory
    if (fileData != nullptr)
        delete[] fileData;
    if (randomData != nullptr)
        delete[] randomData;
    if (nsortedData != nullptr)
        delete[] nsortedData;
    if (sortedData != nullptr)
        delete[] sortedData;
    if (revData != nullptr)
        delete[] revData;
}

/*----------------------Run Sort Function----------------------*/
template <typename Sort>
void Controller::runSort(string sortName, int *dataType, int size)
{
    Sort *sort = new Sort(dataType, size);
    if (outputParam == OutputParameter::TIME)
    {
        cout << sortName << " Time: " << sort->sortWithRunningTimeCount() << " ms" << endl;
    }
    else if (outputParam == OutputParameter::COMP)
    {
        cout << sortName << " Comparisons: " << sort->sortWithComparisonCount() << endl;
    }
    else if (outputParam == OutputParameter::BOTH)
    {
        cout << sortName << " Time: " << sort->sortWithRunningTimeCount() << " ms" << endl;
        cout << sortName << " Comparisons: " << sort->sortWithComparisonCount() << endl;
    }
    delete sort;
}

template <typename Sort>
void Controller::printResult(string sortName)
{
    if (fileName != "")
    {
        cout << "File Name : " << fileName << endl;
        cout << "Input Size : " << this->size << endl;
        runSort<Sort>(sortName, this->fileData, this->size);
        return;
    }
    else
    {
        if (inputOrderParam == InputOrder::NONE)
        {
            cout << "===============Result===============" << endl;
            cout << "Input Size : " << this->size << endl;
            cout << "Input Order : Random" << endl;
            cout << "------------------------------------" << endl;
            runSort<Sort>(sortName, this->randomData, this->size);
            cout << endl;
            cout << "input Size : " << this->size << endl;
            cout << "Input Order : Nearly Sorted" << endl;
            cout << "------------------------------------" << endl;
            runSort<Sort>(sortName, this->nsortedData, this->size);
            cout << endl;
            cout << "input Size : " << this->size << endl;
            cout << "Input Order : Sorted" << endl;
            cout << "------------------------------------" << endl;
            runSort<Sort>(sortName, this->sortedData, this->size);
            cout << endl;
            cout << "input Size : " << this->size << endl;
            cout << "Input Order : Reversed" << endl;
            cout << "------------------------------------" << endl;
            runSort<Sort>(sortName, this->revData, this->size);
            cout << "====================================" << endl;
        }
        else
        {
            cout << "===============Result===============" << endl;
            cout << "Input Size : " << this->size << endl;
            cout << "Input Order : " << inputOrderToString(inputOrderParam) << endl;
            cout << "------------------------------------" << endl;
            switch (inputOrderParam)
            {
            case InputOrder::RAND:
                cout << "Random Data" << endl;
                runSort<Sort>(sortName, this->randomData, this->size);
                break;
            case InputOrder::NSORTED:
                cout << "Nearly Sorted Data" << endl;
                runSort<Sort>(sortName, this->nsortedData, this->size);
                break;
            case InputOrder::SORTED:
                cout << "Sorted Data" << endl;
                runSort<Sort>(sortName, this->sortedData, this->size);
                break;
            case InputOrder::REV:
                cout << "Reversed Data" << endl;
                runSort<Sort>(sortName, this->revData, this->size);
                break;
            }
            cout << "====================================" << endl;
        }
    }
}


/*----------------------Run Function----------------------*/
void Controller::run()
{
    /////////====================================////////////////
    cout << "============Parameters:=============" << endl;
    cout << "Algorithm 1: " << sortingAlgorithmToString(this->algorithmParam1) << endl;
    cout << "Algorithm 2: " << sortingAlgorithmToString(this->algorithmParam2) << endl;
    cout << "Input Order: " << inputOrderToString(this->inputOrderParam) << endl;
    cout << "Output Parameter: " << outputParameterToString(this->outputParam) << endl;
    cout << "Size: " << this->size << endl;
    cout << "====================================" << endl;
    switch (algorithmParam1)
    {
    case SortingAlgorithm::SELECTION_SORT:
    {
        printResult<SelectionSort>("Selection Sort");
        break;
    }
    case SortingAlgorithm::INSERTION_SORT:
    {
        printResult<InsertionSort>("Insertion Sort");
        break;
    }
    case SortingAlgorithm::SHELL_SORT:
    {
        printResult<ShellSort>("Shell Sort");
        break;
    }
    case SortingAlgorithm::BUBBLE_SORT:
    {
        printResult<BubbleSort>("Bubble Sort");
        break;
    }
    case SortingAlgorithm::HEAP_SORT:
    {
        printResult<HeapSort>("Heap Sort");
        break;
    }
    case SortingAlgorithm::MERGE_SORT:
    {
        printResult<MergeSort>("Merge Sort");
        break;
    }
    case SortingAlgorithm::QUICK_SORT:
    {
        printResult<QuickSort>("Quick Sort");
        break;
    }
    case SortingAlgorithm::RADIX_SORT:
    {
        printResult<RadixSort>("Radix Sort");
        break;
    }
    case SortingAlgorithm::COUNTING_SORT:
    {
        printResult<CountingSort>("Counting Sort");
        break;
    }
    default:
        break;
    }
}