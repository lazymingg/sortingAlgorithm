#ifndef CONTROLLER_COMPARISON_MODE_H
#define CONTROLLER_COMPARISON_MODE_H
#include "../include/ControllerUltility.h"
using namespace std;

class ControllerComparisonMode {
public:
    ControllerComparisonMode(int argc, char *argv[]);
    ~ControllerComparisonMode();

    void run();

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

    int* fileDataResult = NULL;
    int* randomDataResult = NULL;
    int* nsortedDataResult = NULL;
    int* sortedDataResult = NULL;
    int* revDataResult = NULL;
    int *result = NULL;
    
    double getAlgorithmRunnningTime(SortingAlgorithm &algorithmParam, int* dataType, int size);
    int64_t getAlgorithmComparisons(SortingAlgorithm &algorithmParam, int* dataType, int size);

    void runSort(int* dataType, int size);
    void writingFile();
};

#endif //CONTROLLER_COMPARISON_MODE_H
