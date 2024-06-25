#include "../include/ControllerAlgorithmMode.h"

/*--------------------file Handling Funtion------------------*/
int *ControllerAlgorithmMode::readFile()
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
void ControllerAlgorithmMode::setAlgorithm(char *argv)
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

void ControllerAlgorithmMode::setOutputParameter(char *argv)
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

void ControllerAlgorithmMode::setInputOrder(char *argv)
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

void ControllerAlgorithmMode::setData()
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
ControllerAlgorithmMode::ControllerAlgorithmMode(int argc, char *argv[])
{
    if (argc < 4)
    {
        printPrototypes();
        exit(-1);
    }
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
    // set up data for sorting
    if (fileName != "")
    {
        fileData = readFile();
    }
    else
    {
        setData();
    }
    // check parameter
    handleParameters(this->algorithmParam1, this->algorithmParam2, this->inputOrderParam, this->outputParam, this->fileName, this->size, argv);
}

ControllerAlgorithmMode::~ControllerAlgorithmMode()
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
/*----------------------Algorithm Running Time and Comparisons Function----------------------*/
double ControllerAlgorithmMode::getAlgorithmRunnningTime(SortingAlgorithm &algorithmParam, int *dataType, int size)
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
    // case SortingAlgorithm::SHELL_SORT:
    // {
    //     ShellSort *sort = new ShellSort(dataType, size);
    //     double time =  sort->getRunningTime();
    //     delete sort;
    //     return time;
    // }
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
        double time = sort->getRunningTime();
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
    default:
        return 0;
    }
}

int64_t ControllerAlgorithmMode::getAlgorithmComparisons(SortingAlgorithm &algorithmParam, int *dataType, int size)
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
    // case SortingAlgorithm::SHELL_SORT:
    // {
    //     ShellSort *sort = new ShellSort(dataType, size);
    //     int64_t comparison = sort->getComparison();
    //     delete sort;
    //     return comparison;
    // }
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
    default:
        return 0;
    }
}

/*----------------------Run Sort Function----------------------*/
// algorithmParam1 is the algorithm that will be run
// algorithmParam2 will not exist in this case so we will not use it
void ControllerAlgorithmMode::runSort(int *dataType, int size)
{
    if (outputParam == OutputParameter::TIME)
    {
        cout << "Running Time : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerAlgorithmMode::getAlgorithmRunnningTime(this->algorithmParam1, dataType, size) << endl;
    }
    else if (outputParam == OutputParameter::COMP)
    {
        cout << "Comparisons : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerAlgorithmMode::getAlgorithmComparisons(this->algorithmParam1, dataType, size) << endl;
    }
    else if (outputParam == OutputParameter::BOTH)
    {
        cout << "Running Time : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerAlgorithmMode::getAlgorithmRunnningTime(this->algorithmParam1, dataType, size) << endl;
        cout << "Comparisons : ";
        cout << sortingAlgorithmToString(this->algorithmParam1) << " " ;
        cout << ControllerAlgorithmMode::getAlgorithmComparisons(this->algorithmParam1, dataType, size) << endl;
    }
}

/*----------------------Run Function----------------------*/
void ControllerAlgorithmMode::run()
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