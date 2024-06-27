#ifndef CONTROLLER_ULTILITY_H
#define CONTROLLER_ULTILITY_H

#include "../include/sortHeader/AllSort.h"
#include "../include/DataGenerator.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <string>
#include <cstring>


using namespace std;

enum class SortingAlgorithm {
    SELECTION_SORT,
    INSERTION_SORT,
    BINARY_INSERTION_SORT,
    SHELL_SORT,
    BUBBLE_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT,
    RADIX_SORT,
    COUNTING_SORT,
    FLASH_SORT,
    SHAKER_SORT,
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
//-----------------------------------------------------setter two algorithm mode-----------------------------------------------------//
void setAlgorithm(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, char *argv);
void setOutputParameter(OutputParameter &outputParam, char *argv);
void setInputOrder(InputOrder &inputOrderParam, char *argv);
void setData(const std::string &fileName, InputOrder inputOrderParam, int size, int* &fileData, int* &randomData, int* &nsortedData, int* &sortedData, int* &revData);
int* readFile(const std::string &fileName, int &size);
void writeFile(const std::string &fileName, int *data, int size);
void handleParameters(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, InputOrder &inputOrderParam, OutputParameter &outputParam, string &fileName, int &size, char *argv[]);
void printParameterInfo();
void printPrototypes();
void coppyData(int *data, int *&dataResult, int size);
void handleParametersCommparisonMode(SortingAlgorithm &algorithmParam1, SortingAlgorithm &algorithmParam2, InputOrder &inputOrderParam, OutputParameter &outputParam, string &fileName, int &size, char* argv[]);
#endif //CONTROLLER_COMPARISON_MODE_H