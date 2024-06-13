#include "../include/AlgorithmMode.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

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
        default: return "Unknown Algorithm";
    }
}

string inputOrderToString(InputOrder order) {
    switch (order) {
        case InputOrder::ALL: return "All";
        case InputOrder::RAND: return "Random";
        case InputOrder::NSORTED: return "Nearly Sorted";
        case InputOrder::SORTED: return "Sorted";
        case InputOrder::REV: return "Reversed";
        default: return "Unknown Order";
    }
}

string outputParameterToString(OutputParameter param) {
    switch (param) {
        case OutputParameter::TIME: return "Time";
        case OutputParameter::COMP: return "Comparisons";
        case OutputParameter::BOTH: return "Both";
        default: return "Unknown Output Parameter";
    }
}
bool isDigit(char* str)
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

AlgorithmMode::AlgorithmMode(int argc, char* argv[])
{
    cout << "constructor" << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << " ";
    }
    // Define algorithm
    if (strcmp(argv[2], "selection-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::SELECTION_SORT;
    }
    else if (strcmp(argv[2], "insertion-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::INSERTION_SORT;
    }
    else if (strcmp(argv[2], "shell-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::SHELL_SORT;
    }
    else if (strcmp(argv[2], "bubble-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::BUBBLE_SORT;
    }
    else if (strcmp(argv[2], "heap-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::HEAP_SORT;
    }
    else if (strcmp(argv[2], "merge-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::MERGE_SORT;
    }
    else if (strcmp(argv[2], "quick-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::QUICK_SORT;
    }
    else if (strcmp(argv[2], "radix-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::RADIX_SORT;
    }
    else if (strcmp(argv[2], "counting-sort") == 0)
    {
        this->algorithmParam = SortingAlgorithm::COUNTING_SORT;
    }
    else
    {
        cout << "Algorithm not found" << endl;
        return;
    }

    // argv[3] is the input file or the size of the array
    if (isDigit(argv[3]))
    {
        this->size = atoi(argv[3]);
        cout << "Size: " << size << endl;
    }
    else
    {
        this->fileName = argv[3];
    }

    // Define input order
    cout << "argc: " << argc << endl;
    if (argc == 5)
    {
        this->inputOrderParam = InputOrder::ALL;
        // Define output parameter
        if (strcmp(argv[4], "-time") == 0)
        {
            this->outputParam = OutputParameter::TIME;
        }
        else if (strcmp(argv[4], "-comp") == 0)
        {
            this->outputParam = OutputParameter::COMP;
        }
        else if (strcmp(argv[4], "-both") == 0)
        {
            this->outputParam = OutputParameter::BOTH;
        }
    }
    else if (argc == 6)
    {
        if (strcmp(argv[4], "-rand") == 0)
        {
            this->inputOrderParam = InputOrder::RAND;
        }
        else if (strcmp(argv[4], "-nsorted") == 0)
        {
            this->inputOrderParam = InputOrder::NSORTED;
        }
        else if (strcmp(argv[4], "-sorted") == 0)
        {
            this->inputOrderParam = InputOrder::SORTED;
        }
        else if (strcmp(argv[4], "-rev") == 0)
        {
            this->inputOrderParam = InputOrder::REV;
        }
        else
        {
            cout << "Input order not found" << endl;
            return;
        }

        // Define output parameter
        if (strcmp(argv[5], "-time") == 0)
        {
            this->outputParam = OutputParameter::TIME;
        }
        else if (strcmp(argv[5], "-comp") == 0)
        {
            this->outputParam = OutputParameter::COMP;
        }
        else if (strcmp(argv[5], "-both") == 0)
        {
            this->outputParam = OutputParameter::BOTH;
        }
    }
    else 
    {
        cout << "Not enough arguments in argv" << endl;
        return;
    }
}

int* AlgorithmMode::readFile()
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

void AlgorithmMode::run()
{
    cout << "Size: " << size << endl;
    cout << "FileName: " << fileName << endl;
    cout << "Algorithm: " << sortingAlgorithmToString(this->algorithmParam) << endl;
    cout << "Input Order: " << inputOrderToString(this->inputOrderParam) << endl;
    cout << "Output Parameter: " << outputParameterToString(this->outputParam) << endl;
}
