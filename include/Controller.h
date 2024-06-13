#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "../include/sortHeader/SelectionSort.h"
#include "../include/sortHeader/InsertionSort.h"
#include "../include/sortHeader/ShellSort.h"
#include "../include/sortHeader/BubbleSort.h"
#include "../include/sortHeader/HeapSort.h"
#include "../include/sortHeader/MergeSort.h"
#include "../include/sortHeader/QuickSort.h"
#include "../include/sortHeader/RadixSort.h"
#include "../include/sortHeader/CountingSort.h"
#include "../include/DataGenerator.h"
#include <vector>

using namespace std;

enum class SortingAlgorithm {
    SELECTION_SORT,
    INSERTION_SORT,
    SHELL_SORT,
    BUBBLE_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT,
    RADIX_SORT,
    COUNTING_SORT,
    NONE
};

enum class InputOrder {
    RAND,
    NSORTED,
    SORTED,
    REV,
    NONE
};

enum class OutputParameter {
    TIME,
    COMP,
    BOTH,
    NONE
};

class Controller {
public:
    Controller(int argc, char *argv[]);
    ~Controller();

    void run();
    template <typename Sort>
    void printResult(string sortName);
    template <typename Sort>
    void runSort(string sortName, int* dataType, int size);

private:
    SortingAlgorithm algorithmParam1 = SortingAlgorithm::NONE;
    SortingAlgorithm algorithmParam2 = SortingAlgorithm::NONE;
    InputOrder inputOrderParam = InputOrder::NONE;
    OutputParameter outputParam = OutputParameter::NONE;
    string fileName = "";
    int size = 0;
    int* fileData = NULL;
    int* randomData = NULL;
    int* nsortedData = NULL;
    int* sortedData = NULL;
    int* revData = NULL;

    void setData();
    void setAlgorithm(char *argv);
    void setOutputParameter(char *argv);
    void setInputOrder(char *argv);
    int* readFile();
};

#endif //CONTROLLER_H
