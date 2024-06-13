#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include "../include/DataGenerator.h"
#include "../include/selectionSort.h"
#include "../include/InsertionSort.h"
using namespace std;

enum class SortingAlgorithm
{
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

enum class InputOrder
{
    RAND,
    NSORTED,
    SORTED,
    REV,
    NONE
};

enum class OutputParameter
{
    TIME,
    COMP,
    BOTH,
    NONE
};

class Controller
{
private:
    SortingAlgorithm algorithmParam1 = SortingAlgorithm::NONE;
    SortingAlgorithm algorithmParam2 = SortingAlgorithm::NONE;
    InputOrder inputOrderParam = InputOrder::NONE;
    OutputParameter outputParam = OutputParameter::NONE;
    int size = 0;
    int *fileData = NULL;
    int *randomData = NULL;
    int *nsortedData = NULL;
    int *sortedData = NULL;
    int *revData = NULL;
    string fileName = "";

public:
    Controller(int argc, char *argv[]);
    ~Controller();
    int *readFile();
    void run();
};

#endif // CONTROLLER_H