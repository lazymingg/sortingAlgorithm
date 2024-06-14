#ifndef CONTROLLER_ULTILITY_H
#define CONTROLLER_ULTILITY_H

#include "../include/sortHeader/AllSort.h"
#include "../include/DataGenerator.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <cstdint>
#include <string>
#include <cctype>
#include <cstring>


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

bool isDigit(char *str);
string sortingAlgorithmToString(SortingAlgorithm algo);
string inputOrderToString(InputOrder order);
string outputParameterToString(OutputParameter param);
void handleParameters(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, InputOrder &inputOrderParam, OutputParameter &outputParam, string &fileName, int &size, char *argv[]);
void printParameterInfo();
void printPrototypes();
#endif //CONTROLLER_COMPARISON_MODE_H