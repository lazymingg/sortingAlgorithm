#include "../include/HidingFeature.h"

/*----------------------Constructor and Destructor----------------------*/
HidingMode::HidingMode(int argc, char *argv[])
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
        if (argv[3][0] != '-')
            this->fileName = argv[3];
        else
        {
            printPrototypes();
            exit(-1);
        }
    }

    for (int i = 2; i < argc; i++)
    {
        // Define algorithm
        // void setAlgorithm(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, char *argv);
        setAlgorithm(this->algorithmParam1, this->algorithmParam2, argv[i]);
        // Define output parameter
        setOutputParameter(this->outputParam, argv[i]);
        // Define input order
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
    // check parameter
}

HidingMode::~HidingMode()
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
    if (result != nullptr)
        delete[] result;
}

/*----------------------Algorithm Running Time and Comparisons Function----------------------*/
double HidingMode::getAlgorithmRunnningTime(SortingAlgorithm algorithmParam, int *dataType, int size)
{
    switch (algorithmParam)
    {
        case SortingAlgorithm::SELECTION_SORT:
        {
            SelectionSort *sort = new SelectionSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::INSERTION_SORT:
        {
            InsertionSort *sort = new InsertionSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::SHELL_SORT:
        {
            ShellSort *sort = new ShellSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::BUBBLE_SORT:
        {
            BubbleSort *sort = new BubbleSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::HEAP_SORT:
        {
            HeapSort *sort = new HeapSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::MERGE_SORT:
        {
            MergeSort *sort = new MergeSort(dataType, size);
            double time = sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::QUICK_SORT:
        {
            QuickSort *sort = new QuickSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::RADIX_SORT:
        {
            RadixSort *sort = new RadixSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::BINARY_INSERTION_SORT:
        {
            BinaryInsertionSort *sort = new BinaryInsertionSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::COUNTING_SORT:
        {
            CountingSort *sort = new CountingSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            
            delete sort;
            return time;
        }

        case SortingAlgorithm::FLASH_SORT:
        {
            FlashSort *sort = new FlashSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        case SortingAlgorithm::SHAKER_SORT:
        {
            ShakerSort *sort = new ShakerSort(dataType, size);
            double time =  sort->getRunningTime();
            coppyData(sort->getTempArr(), this->result, size);
            delete sort;
            return time;
        }

        default:
            return 0;
    }
}

int64_t HidingMode::getAlgorithmComparisons(SortingAlgorithm algorithmParam, int *dataType, int size)
{
    switch (algorithmParam)
    {
        case SortingAlgorithm::SELECTION_SORT:
        {
            SelectionSort *sort = new SelectionSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::INSERTION_SORT:
        {
            InsertionSort *sort = new InsertionSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::SHELL_SORT:
        {
            ShellSort *sort = new ShellSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::BUBBLE_SORT:
        {
            BubbleSort *sort = new BubbleSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::HEAP_SORT:
        {
            HeapSort *sort = new HeapSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::MERGE_SORT:
        {
            MergeSort *sort = new MergeSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::QUICK_SORT:
        {
            QuickSort *sort = new QuickSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::RADIX_SORT:
        {
            RadixSort *sort = new RadixSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::BINARY_INSERTION_SORT:
        {
            BinaryInsertionSort *sort = new BinaryInsertionSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::COUNTING_SORT:
        {
            CountingSort *sort = new CountingSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::FLASH_SORT:
        {
            FlashSort *sort = new FlashSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        case SortingAlgorithm::SHAKER_SORT:
        {
            ShakerSort *sort = new ShakerSort(dataType, size);
            int64_t comparison = sort->getComparison();
            coppyData(sort->getTempArr2(), this->result, size);
            delete sort;
            return comparison;
        }

        default:
            return 0;
    }
}

/*----------------------Run Sort Function----------------------*/
// algorithmParam1 is the algorithm that will be run
// algorithmParam2 will not exist in this case so we will not use it
void HidingMode::runSort(int *dataType, int size)
{
    //do all case in enum type class SortingAlgorithm
    
    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::BINARY_INSERTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::BINARY_INSERTION_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::BINARY_INSERTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::BINARY_INSERTION_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SELECTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::SELECTION_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SELECTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::SELECTION_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::INSERTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::INSERTION_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::INSERTION_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::INSERTION_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SHELL_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::SHELL_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SHELL_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::SHELL_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::BUBBLE_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::BUBBLE_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::BUBBLE_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::BUBBLE_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;
    
    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::HEAP_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::HEAP_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::HEAP_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::HEAP_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::MERGE_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::MERGE_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::MERGE_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::MERGE_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::QUICK_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::QUICK_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::QUICK_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::QUICK_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::RADIX_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::RADIX_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::RADIX_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::RADIX_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::FLASH_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::FLASH_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::FLASH_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::FLASH_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::COUNTING_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::COUNTING_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::COUNTING_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::COUNTING_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;

    cout << "Running Time : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SHAKER_SORT) << " " ;
    cout << HidingMode::getAlgorithmRunnningTime(SortingAlgorithm::SHAKER_SORT, dataType, size) << endl;
    cout << "Comparisons : ";
    cout << sortingAlgorithmToString(SortingAlgorithm::SHAKER_SORT) << " " ;
    cout << HidingMode::getAlgorithmComparisons(SortingAlgorithm::SHAKER_SORT, dataType, size) << endl;
    cout << "------------------------------------" << endl;
}

/*----------------------Run Function----------------------*/
void HidingMode::run()
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

    writingFile();
}

void HidingMode::writingFile()
{
    //command 1 and command 2 run sort and write down the sorted array to the "output.txt" file
    //command 2 and command 5 run sort and write down the generated input to the "input.txt" file
    //command 3 write down all four generated input:
    // – "input_1.txt": random order data
    // – "input_2.txt": nearly sorted data
    // – "input_3.txt": sorted data
    // – "input_4.txt": reversed data
    // The file format (for both input and output files) is as follows:
    // • 1
    // st line: an integer n, indicating the number of elements in the input data
    // • 2
    // nd line: n integers, separated by a single space

    // case command 1 and 2
    if (InputOrder::NONE != this->inputOrderParam)
    {
        writeFile("output.txt", result, size);
    }

    // input of command  2 and 3
    if (fileName == "")
    {
        switch (inputOrderParam)
        {
            case InputOrder::RAND:
                writeFile("input.txt", randomData, size);
                break;

            case InputOrder::NSORTED:
                writeFile("input.txt", nsortedData, size);
                break;

            case InputOrder::SORTED:
                writeFile("input.txt", sortedData, size);
                break;

            case InputOrder::REV:
                writeFile("input.txt", revData, size);
                break;
                
            default:
                writeFile("input_1.txt", randomData, size);
                writeFile("input_2.txt", nsortedData, size);
                writeFile("input_3.txt", sortedData, size);
                writeFile("input_4.txt", revData, size);
                break;
        }
    }
}
