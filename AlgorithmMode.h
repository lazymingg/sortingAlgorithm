#ifndef ALGORITHMMODE_H
#define ALGORITHMMODE_H
#include <string>
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
    COUNTING_SORT
};

enum class InputOrder {
    ALL,
    RAND,
    NSORTED,
    SORTED,
    REV
};

enum class OutputParameter {
    TIME,
    COMP,
    BOTH,
    NONE
};

class AlgorithmMode {
private:
    SortingAlgorithm algorithmParam;
    InputOrder inputOrderParam;
    OutputParameter outputParam;
    int size = 0;
    int *arr = nullptr;
    string fileName = "";

public:
    AlgorithmMode(int argc, char* argv[]);
    int* readFile();
    void run();
};

#endif // ALGORITHMMODE_H