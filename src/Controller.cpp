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
string sortingAlgorithmToString(SortingAlgorithm algo) {
    switch (algo) {
        case SortingAlgorithm::SELECTION_SORT: return "Selection Sort";
        case SortingAlgorithm::INSERTION_SORT: return "Insertion Sort";
        case SortingAlgorithm::SHELL_SORT: return "Shell Sort";
        case SortingAlgorithm::BUBBLE_SORT: return "Bubble Sort";
        case SortingAlgorithm::HEAP_SORT: return "Heap Sort";
        case SortingAlgorithm::MERGE_SORT: return "Merge Sort";
        case SortingAlgorithm::QUICK_SORT: return "Quick Sort";
        case SortingAlgorithm::RADIX_SORT: return "Radix Sort";
        case SortingAlgorithm::COUNTING_SORT: return "Counting Sort";
        case SortingAlgorithm::NONE: return "None";
        default: return "Unknown Algorithm";
    }
}

string inputOrderToString(InputOrder order) {
    switch (order) {
        case InputOrder::RAND: return "Random";
        case InputOrder::NSORTED: return "Nearly Sorted";
        case InputOrder::SORTED: return "Sorted";
        case InputOrder::REV: return "Reversed";
        case InputOrder::NONE: return "None";
    }
}

string outputParameterToString(OutputParameter param) {
    switch (param)
    {
        case OutputParameter::TIME: return "Time";
        case OutputParameter::COMP: return "Comparisons";
        case OutputParameter::BOTH: return "Both";
        case OutputParameter::NONE: return "None";
    }
}
int* Controller::readFile()
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
    int* arr = new int[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
        arr[i] = v[i];
    }
    return arr;
}

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
        if (strcmp(argv[i], "selection-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::SELECTION_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::SELECTION_SORT;
        }

        else if (strcmp(argv[i], "insertion-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::INSERTION_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::INSERTION_SORT;
        }
        else if (strcmp(argv[i], "shell-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::SHELL_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::SHELL_SORT;
        }
        else if (strcmp(argv[i], "bubble-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::BUBBLE_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::BUBBLE_SORT;
        }
        else if (strcmp(argv[i], "heap-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::HEAP_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::HEAP_SORT;
        }
        else if (strcmp(argv[i], "merge-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::MERGE_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::MERGE_SORT;
        }
        else if (strcmp(argv[i], "quick-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::QUICK_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::QUICK_SORT;
        }
        else if (strcmp(argv[i], "radix-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::RADIX_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::RADIX_SORT;
        }
        else if (strcmp(argv[i], "counting-sort") == 0)
        {
            if (this->algorithmParam1 != SortingAlgorithm::NONE)
                this->algorithmParam2 = SortingAlgorithm::COUNTING_SORT;
            else
                this->algorithmParam1 = SortingAlgorithm::COUNTING_SORT;
        }
        // Define output parameter
        if (strcmp(argv[i], "-time") == 0)
        {
            this->outputParam = OutputParameter::TIME;
        }
        else if (strcmp(argv[i], "-comp") == 0)
        {
            this->outputParam = OutputParameter::COMP;
        }
        else if (strcmp(argv[i], "-both") == 0)
        {
            this->outputParam = OutputParameter::BOTH;
        }
        else 
        {
            this->inputOrderParam = InputOrder::NONE;
        }
        if (strcmp(argv[i], "-rand") == 0)
        {
            this->inputOrderParam = InputOrder::RAND;
        }
        else if (strcmp(argv[i], "-nsorted") == 0)
        {
            this->inputOrderParam = InputOrder::NSORTED;
        }
        else if (strcmp(argv[i], "-sorted") == 0)
        {
            this->inputOrderParam = InputOrder::SORTED;
        }
        else if (strcmp(argv[i], "-rev") == 0)
        {
            this->inputOrderParam = InputOrder::REV;
        }
        // Define output parameter
        if (strcmp(argv[i], "-time") == 0)
        {
            this->outputParam = OutputParameter::TIME;
        }
        else if (strcmp(argv[i], "-comp") == 0)
        {
            this->outputParam = OutputParameter::COMP;
        }
        else if (strcmp(argv[i], "-both") == 0)
        {
            this->outputParam = OutputParameter::BOTH;
        }
    }
}
void Controller::run()
{
//     cout << "Size: " << size << endl;
//     cout << "FileName: " << fileName << endl;
//     cout << "Algorithm1: " << sortingAlgorithmToString(this->algorithmParam1) << endl;
//     cout << "Algorithm2: " << sortingAlgorithmToString(this->algorithmParam2) << endl;
//     cout << "Input Order: " << inputOrderToString(this->inputOrderParam) << endl;
//     cout << "Output Parameter: " << outputParameterToString(this->outputParam) << endl;
    switch (this->inputOrderParam)
    {
        case InputOrder::RAND:
            this->randomData = GenerateRandomData(this->size);
            break;
        case InputOrder::NSORTED:
            this->nsortedData = GenerateNearlySortedData(this->size);
            break;
        case InputOrder::SORTED:
            this->nsortedData = GenerateSortedData(this->size);
            break;
        case InputOrder::REV:
            this->nsortedData = GenerateReverseData(this->size);
            break;
        
        default:
            // do all
            this->randomData = GenerateRandomData(this->size);
            this->nsortedData = GenerateNearlySortedData(this->size);
            this->nsortedData = GenerateSortedData(this->size);
            this->nsortedData = GenerateReverseData(this->size);
            break;
    }

    switch (algorithmParam1)
    {
        case SortingAlgorithm::SELECTION_SORT:
        {
            SelectionSort *sort = new SelectionSort(this->randomData, this->size);
            switch (outputParam)
            {
                case OutputParameter::TIME:
                {
                    cout << "Selection Sort Time: " << sort->sortWithRunningTimeCount() << endl;
                    break;
                }
                case OutputParameter::COMP:
                {
                    cout << "Selection Sort Comparison: " << sort->sortWithComparisonCount() << endl;
                    break;
                }
                case OutputParameter::BOTH:
                {
                    cout << "Selection Sort Time: " << sort->sortWithRunningTimeCount() << endl;
                    cout << "Selection Sort Comparison: " << sort->sortWithComparisonCount() << endl;
                    break;
                }
            }
        }
    }   
}