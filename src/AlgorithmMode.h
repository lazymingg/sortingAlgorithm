#ifndef ALGORITHM_MODE_H
#define ALGORITHM_MODE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include "DataGenerator.h"
#include "selectionSort.h"
using namespace std;
enum class SortingAlgorithm {
    selectionSort,
    insertionSort,
    shellSort,
    bubbleSort,
    heapSort,
    mergeSort,
    quickSort,
    radixSort,
    countingSort
};
enum class InputOrder {
    rand,
    nsorted,
    sorted,
    rev,
    all
};
enum class OutputParameter {
    time,
    comp,
    both,
};
class AlgorithmMode {
public:
    AlgorithmMode(int argc, char* argv[]);

    ~AlgorithmMode();

private:
    SortingAlgorithm algorithm;
    InputOrder inputOrder;
    OutputParameter outputParameter;
};
#endif