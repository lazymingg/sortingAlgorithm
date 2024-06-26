#include "../include/ControllerComparisonMode.h"

/*----------------------Constructor and Destructor----------------------*/
ControllerComparisonMode::ControllerComparisonMode(int argc, char *argv[])
{
    if (argc < 5)
    {
        printPrototypes();
        exit(-1);
    }
    if (isDigit(argv[4]))
    {
        this->size = atoi(argv[4]);
    }
    else
    {
        this->fileName = argv[4];
    }
    for (int i = 2; i < argc; i++)
    {
        // Define algorithm
        // void setAlgorithm(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, char *argv);
        setAlgorithm(this->algorithmParam1, this->algorithmParam2, argv[i]);
        // Define output parameter
        // void setOutputParameter(OutputParameter &outputParam, char *argv);
        setOutputParameter(this->outputParam, argv[i]);
        // Define input order
        // void setInputOrder(InputOrder &inputOrderParam, char *argv);
        setInputOrder(this->inputOrderParam, argv[i]);
    }
    // set up data for sorting
    if (fileName != "")
    {
        fileData = readFile(fileName, size);
    }
    else
    {
        setData(fileName, inputOrderParam, size, fileData, randomData, nsortedData, sortedData, revData);
    }
    //check parameters
    handleParametersCommparisonMode(this->algorithmParam1, this->algorithmParam2, this->inputOrderParam, this->outputParam, this->fileName, this->size, argv);
}

ControllerComparisonMode::~ControllerComparisonMode()
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

/*----------------------Algorithm Running Time and Comparisons Function----------------------*/
double ControllerComparisonMode::getAlgorithmRunnningTime(SortingAlgorithm &algorithmParam, int *dataType, int size)
{
    switch (algorithmParam)
    {
    case SortingAlgorithm::SELECTION_SORT:
    {
        SelectionSort *sort = new SelectionSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::INSERTION_SORT:
    {
        InsertionSort *sort = new InsertionSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::SHELL_SORT:
    {
        ShellSort *sort = new ShellSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::BUBBLE_SORT:
    {
        BubbleSort *sort = new BubbleSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::HEAP_SORT:
    {
        HeapSort *sort = new HeapSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::MERGE_SORT:
    {
        MergeSort *sort = new MergeSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::QUICK_SORT:
    {
        QuickSort *sort = new QuickSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    case SortingAlgorithm::RADIX_SORT:
    {
        RadixSort *sort = new RadixSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    // case SortingAlgorithm::COUNTING_SORT:
    // {
    //     CountingSort *sort = new CountingSort(dataType, size);
    //     double time =  sort->getRunningTime();
    //     delete sort;
    //     return time;
    // }
    case SortingAlgorithm::FLASH_SORT:
    {
        FlashSort *sort = new FlashSort(dataType, size);
        double time =  sort->getRunningTime();
        delete sort;
        return time;
    }
    default:
        return 0;
    }
}
int64_t ControllerComparisonMode::getAlgorithmComparisons(SortingAlgorithm &algorithmParam, int *dataType, int size)
{
    switch (algorithmParam)
    {
    case SortingAlgorithm::SELECTION_SORT:
    {
        SelectionSort *sort = new SelectionSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::INSERTION_SORT:
    {
        InsertionSort *sort = new InsertionSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::SHELL_SORT:
    {
        ShellSort *sort = new ShellSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::BUBBLE_SORT:
    {
        BubbleSort *sort = new BubbleSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::HEAP_SORT:
    {
        HeapSort *sort = new HeapSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::MERGE_SORT:
    {
        MergeSort *sort = new MergeSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::QUICK_SORT:
    {
        QuickSort *sort = new QuickSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    case SortingAlgorithm::RADIX_SORT:
    {
        RadixSort *sort = new RadixSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    // case SortingAlgorithm::COUNTING_SORT:
    // {
    //     CountingSort *sort = new CountingSort(dataType, size);
    //     int64_t comparison = sort->getComparison();
    //     delete sort;
    //     return comparison;
    // }
    case SortingAlgorithm::FLASH_SORT:
    {
        FlashSort *sort = new FlashSort(dataType, size);
        int64_t comparison = sort->getComparison();
        delete sort;
        return comparison;
    }
    default:
        return 0;
    }
}

/*----------------------Run Sort Function----------------------*/
void ControllerComparisonMode::runSort(int *dataType, int size)
{
    if (outputParam == OutputParameter::TIME)
    {
        cout << "Running Time : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerComparisonMode::getAlgorithmRunnningTime(this->algorithmParam1, dataType, size);
        cout << " | "; 
        cout << sortingAlgorithmToString(this->algorithmParam2) << " ";
        cout << ControllerComparisonMode::getAlgorithmRunnningTime(this->algorithmParam2, dataType, size) << endl;
    }
    else if (outputParam == OutputParameter::COMP)
    {
        cout << "Comparisons : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerComparisonMode::getAlgorithmComparisons(this->algorithmParam1, dataType, size);
        cout << " | "; 
        cout << sortingAlgorithmToString(this->algorithmParam2) << " ";
        cout << ControllerComparisonMode::getAlgorithmComparisons(this->algorithmParam2, dataType, size) << endl;
    }
    else if (outputParam == OutputParameter::BOTH || outputParam == OutputParameter::NONE)
    {
        cout << "Running Time : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerComparisonMode::getAlgorithmRunnningTime(this->algorithmParam1, dataType, size);
        cout << " | "; 
        cout << sortingAlgorithmToString(this->algorithmParam2) << " ";
        cout << ControllerComparisonMode::getAlgorithmRunnningTime(this->algorithmParam2, dataType, size) << endl;
        cout << "Comparisons : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerComparisonMode::getAlgorithmComparisons(this->algorithmParam1, dataType, size);
        cout << " | "; 
        cout << sortingAlgorithmToString(this->algorithmParam2) << " ";
        cout << ControllerComparisonMode::getAlgorithmComparisons(this->algorithmParam2, dataType, size) << endl;
    }
}

/*----------------------Run Function----------------------*/
void ControllerComparisonMode::run()
{
    /////////====================================////////////////
    cout << "=============Parameters:=============" << endl;
    cout << "Algorithm 1: " << sortingAlgorithmToString(this->algorithmParam1) << endl;
    cout << "Algorithm 2: " << sortingAlgorithmToString(this->algorithmParam2) << endl;
    cout << "Input Order: " << inputOrderToString(this->inputOrderParam) << endl;
    cout << "Output Parameter: " << outputParameterToString(this->outputParam) << endl;
    cout << "Size: " << this->size << endl;
    cout << "=====================================" << endl;
    if (fileName != "")
    {
        cout << "Input File: " << fileName << endl;
        cout << "size: " << size << endl;
        cout << "------------------------------------" << endl;
        runSort(fileData, size);
        cout << endl;
    }
    if (randomData != nullptr)
    {
        cout << "Random Data: " << endl;
        runSort(randomData, size);
        cout << "------------------------------------" << endl;
    }
    if (nsortedData != nullptr)
    {
        cout << "Nearly Sorted Data: " << endl;
        runSort(nsortedData, size);
        cout << "------------------------------------" << endl;
    }
    if (sortedData != nullptr)
    {
        cout << "Sorted Data: " << endl;
        runSort(sortedData, size);
        cout << "------------------------------------" << endl;
    }
    if (revData != nullptr)
    {
        cout << "Reverse Data: " << endl;
        runSort(revData, size);
        cout << "------------------------------------" << endl;
    }
}