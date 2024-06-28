#include "../include/ControllerUltility.h"
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
void coppyData(int *data, int *&dataResult, int size)
{
    if (dataResult == nullptr)
    {
        dataResult = new int[size];
    }

    else
    {
        delete[] dataResult;
        dataResult = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        dataResult[i] = data[i];
    }
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

        case SortingAlgorithm::BINARY_INSERTION_SORT:
            return "Binary Insertion Sort";

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

        case SortingAlgorithm::FLASH_SORT:
            return "Flash Sort";

        case SortingAlgorithm::SHAKER_SORT:
            return "Shaker Sort";

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

        default:
            return "Unknown Order";
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

        default:
            return "Unknown Parameter";
    }
}
void handleParameters(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, InputOrder &inputOrderParam, OutputParameter &outputParam, string &fileName, int &size, char* argv[])
{
    if (algorithmParam1 == SortingAlgorithm::NONE)
    {
        printPrototypes();
        exit(-1);
    }

    if (inputOrderParam == InputOrder::NONE && fileName == "" && size == 0)
    {
        printPrototypes();
        exit(-1);
    }
    if (fileName == "" && size == 0)
    {
        printPrototypes();
    }
    if (outputParam == OutputParameter::NONE)
    {
        printPrototypes();
        exit(-1);
    }
}
void handleParametersCommparisonMode(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, InputOrder &inputOrderParam, OutputParameter &outputParam, string &fileName, int &size, char* argv[])
{
    if (algorithmParam1 == SortingAlgorithm::NONE)
    {
        printPrototypes();
        exit(-1);
    }
    if (fileName == "" && size == 0)
    {
        printPrototypes();
    }
    if (inputOrderParam == InputOrder::NONE && fileName == "" && size == 0)
    {
        printPrototypes();
        exit(-1);
    }
}
void printPrototypes()
{
    cout << "your usage(parameters) is wrong\n";
    cout << "1. Run a sorting algorithm on user-provided data\n";
    cout << "   Prototype: [Execution file] -a [Algorithm] [Input filename] [Output parameter(s)]\n";
    cout << "   Example: a.exe -a radix-sort input.txt -both\n\n";

    cout << "2. Run a sorting algorithm on the data generated automatically with specified size and order\n";
    cout << "   Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n";
    cout << "   Example: a.exe -a selection-sort 50 -rand -time\n\n";

    cout << "3. Run a sorting algorithm on ALL data arrangements of a specified size\n";
    cout << "   Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n";
    cout << "   Example: a.exe -a quick-sort 70000 -comp\n\n";

    cout << "4. Run two sorting algorithms on user-provided data\n";
    cout << "   Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input filename]\n";
    cout << "   Example: a.exe -c heap-sort merge-sort input.txt\n\n";

    cout << "5. Run two sorting algorithms on the data generated automatically with specified size and order\n";
    cout << "   Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
    cout << "   Example: a.exe -c quick-sort merge-sort 100000 -nsorted\n\n";

    cout << "get Help by using -h\n";
    cout << "   Prototype: [Execution file] -h\n";
    cout << "   Example: a.exe -h\n\n";
}

void printParameterInfo()
{
    cout << "Parameters:\n";
    cout << "1. Mode:\n";
    cout << "   -a: Algorithm mode\n";
    cout << "   -c: Comparison mode\n\n";

    cout << "2. Algorithm name:\n";
    cout << "   Lowercase, words are connected by hyphens (e.g., selection-sort, binary-insertion-sort)\n\n";

    cout << "3. Input size:\n";
    cout << "   Integer (≤ 1,000,000) can try more if you confident with ur computer :D\n\n";

    cout << "4. Input order:\n";
    cout << "   -rand: Randomized data\n";
    cout << "   -nsorted: Nearly sorted data\n";
    cout << "   -sorted: Sorted data\n";
    cout << "   -rev: Reverse sorted data\n\n";

    cout << "5. Given input (file):\n";
    cout << "   Path to the input file. The file format is as follows:\n";
    cout << "   1st line: an integer n, indicating the number of elements in the input data\n";
    cout << "   2nd line: n integers, separated by a single space\n\n";

    cout << "6. Output parameters:\n";
    cout << "   -time: Algorithm’s running time\n";
    cout << "   -comp: Number of comparisons\n";
    cout << "   -both: Both running time and number of comparisons\n\n";
}

// ---------------------------------setter of controller---------------------------------//
void setAlgorithm(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, char *argv)
{
    if (strcmp(argv, "selection-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::SELECTION_SORT;
        else
            algorithmParam1 = SortingAlgorithm::SELECTION_SORT;
    }
    
    else if (strcmp(argv, "insertion-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::INSERTION_SORT;
        else
            algorithmParam1 = SortingAlgorithm::INSERTION_SORT;
    }

    else if (strcmp(argv, "binary-insertion-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::BINARY_INSERTION_SORT;
        else
            algorithmParam1 = SortingAlgorithm::BINARY_INSERTION_SORT;
    }

    else if (strcmp(argv, "shell-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::SHELL_SORT;
        else
            algorithmParam1 = SortingAlgorithm::SHELL_SORT;
    }

    else if (strcmp(argv, "bubble-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::BUBBLE_SORT;
        else
            algorithmParam1 = SortingAlgorithm::BUBBLE_SORT;
    }

    else if (strcmp(argv, "heap-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::HEAP_SORT;
        else
            algorithmParam1 = SortingAlgorithm::HEAP_SORT;
    }

    else if (strcmp(argv, "merge-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::MERGE_SORT;
        else
            algorithmParam1 = SortingAlgorithm::MERGE_SORT;
    }

    else if (strcmp(argv, "quick-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::QUICK_SORT;
        else
            algorithmParam1 = SortingAlgorithm::QUICK_SORT;
    }

    else if (strcmp(argv, "radix-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::RADIX_SORT;
        else
            algorithmParam1 = SortingAlgorithm::RADIX_SORT;
    }
    
    else if (strcmp(argv, "counting-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::COUNTING_SORT;
        else
            algorithmParam1 = SortingAlgorithm::COUNTING_SORT;
    }

    else if (strcmp(argv, "flash-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::FLASH_SORT;
        else
            algorithmParam1 = SortingAlgorithm::FLASH_SORT;
    }

    else if (strcmp(argv, "shaker-sort") == 0)
    {
        if (algorithmParam1 != SortingAlgorithm::NONE)
            algorithmParam2 = SortingAlgorithm::SHAKER_SORT;
        else
            algorithmParam1 = SortingAlgorithm::SHAKER_SORT;
    }
}

void setOutputParameter(OutputParameter &outputParam, char *argv)
{
    if (strcmp(argv, "-time") == 0)
    {
        outputParam = OutputParameter::TIME;
    }

    else if (strcmp(argv, "-comp") == 0)
    {
        outputParam = OutputParameter::COMP;
    }

    else if (strcmp(argv, "-both") == 0)
    {
        outputParam = OutputParameter::BOTH;
    }
}

void setInputOrder(InputOrder &inputOrderParam, char *argv)
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

int* readFile(const std::string &fileName, int &size)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "File not found" << std::endl;
        exit(-1);
    }

    std::vector<int> v;
    file >> size;
    for (int i = 0; i < size; i++) {
        int num;
        file >> num;
        v.push_back(num);
    }
    // int num;
    // while (file >> num)
    // {
    //     v.push_back(num);
    // }
    // size = v.size();
    int *arr = new int[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
        arr[i] = v[i];
    }
    return arr;
}

void setData(const std::string &fileName, InputOrder inputOrderParam, int size, int* &fileData, int* &randomData, int* &nsortedData, int* &sortedData, int* &revData)
{
    if (!fileName.empty())
    {
        fileData = readFile(fileName, size);
    }
    switch (inputOrderParam)
    {
        case InputOrder::RAND:
            randomData = GenerateRandomData(size);
            break;

        case InputOrder::NSORTED:
            nsortedData = GenerateNearlySortedData(size);
            break;

        case InputOrder::SORTED:
            sortedData = GenerateSortedData(size);
            break;

        case InputOrder::REV:
            revData = GenerateReverseData(size);
            break;

        case InputOrder::NONE:
            // do all
            randomData = GenerateRandomData(size);
            nsortedData = GenerateNearlySortedData(size);
            sortedData = GenerateSortedData(size);
            revData = GenerateReverseData(size);
            break;
    }
}
void writeFile(const std::string &fileName, int *data, int size)
{
    std::ofstream file(fileName);
    
    if (!file.is_open()) {
        std::cout << "Could not open file for writing" << std::endl;
        return;
    }
    
    file << size << std::endl;
    
    for (int i = 0; i < size; ++i) {
        file << data[i] << " ";
    }
    
    file << std::endl;
    file.close();
}