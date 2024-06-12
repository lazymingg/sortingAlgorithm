#include "AlgorithmMode.h"
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

class AlgorithmMode {
private:
    SortingAlgorithm algorithm;
    InputOrder inputOrder;
    OutputParameter outputParameter;
    int size;
    int *arr;
    string fileName = "";
public:
    AlgorithmMode(int argc, char* argv[])
    {
        // define algorithm
        if (strcmp(argv[2], "selection-sort"))
        {
            algorithm = SortingAlgorithm::selectionSort;
        }
        else if (strcmp(argv[2], "insertion-sort"))
        {
            algorithm = SortingAlgorithm::insertionSort;
        }
        else if (strcmp(argv[2], "shell-sort"))
        {
            algorithm = SortingAlgorithm::shellSort;
        }
        else if (strcmp(argv[2], "bubble-sort"))
        {
            algorithm = SortingAlgorithm::bubbleSort;
        }
        else if (strcmp(argv[2], "heap-sort"))
        {
            algorithm = SortingAlgorithm::heapSort;
        }
        else if (strcmp(argv[2], "merge-sort"))
        {
            algorithm = SortingAlgorithm::mergeSort;
        }
        else if (strcmp(argv[2], "quick-sort"))
        {
            algorithm = SortingAlgorithm::quickSort;
        }
        else if (strcmp(argv[2], "radix-sort"))
        {
            algorithm = SortingAlgorithm::radixSort;
        }
        else if (strcmp(argv[2], "counting-sort"))
        {
            algorithm = SortingAlgorithm::countingSort;
        }
        // the argv3 is the input file or the size of the array
        //if the input is a number then it is the size of the array
        if (isDigit(argv[3]))
        {
            size = atoi(argv[3]);
        }
        else
        {
            fileName = argv[3];
        }
        // define input order
        // the argv4(input order) is optional and is the order of the array
        if (argc == 5)
        {
            // if the order is not specified then do all the orders
            inputOrder = InputOrder::all;
        }
        else if (argc == 6)
        {
            if (strcmp(argv[4], "-rand"))
            {
                inputOrder = InputOrder::rand;
            }
            else if (strcmp(argv[4], "-nsorted"))
            {
                inputOrder = InputOrder::nsorted;
            }
            else if (strcmp(argv[4], "-sorted"))
            {
                inputOrder = InputOrder::sorted;
            }
            else if (strcmp(argv[4], "-rev"))
            {
                inputOrder = InputOrder::rev;
            }
        }
        else 
        {
            cout << "not enough arguments in argv" << endl;
            return;
        } 
        //define output parameter
        if (strcmp(argv[5], "-time"))
        {
            outputParameter = OutputParameter::time;
        }
        else if (strcmp(argv[5], "-comp"))
        {
            outputParameter = OutputParameter::comp;
        }
        else if (strcmp(argv[5], "-both"))
        {
            outputParameter = OutputParameter::both;
        }

    }
    int* readFile()
    {
        // read the file
        ifstream file(fileName);
        if (!file.is_open())
        {
            cout << "file not found" << endl;
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
    }
    void run()
    {
        if (fileName != "")
        {
            readFile();
        }
        else
        {
            switch (inputOrder)
            {
                case InputOrder::rand:
                    int* arr = GenerateData(size, 0);
                    SelectionSort sort = new SelectionSort(arr, size);
                    break;
                case InputOrder::nsorted:
                    int* arr = GenerateData(size, 1);
                    break;
                case InputOrder::sorted:
                    int* arr = GenerateData(size, 2);
                    break;
                case InputOrder::rev:
                    int* arr = GenerateData(size, 3);
                    break;
            }
        }
    }
};
