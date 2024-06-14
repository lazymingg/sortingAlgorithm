#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../include/ControllerUltility.h"

using namespace std;

class ControllerAlgorithmMode {
public:
    ControllerAlgorithmMode(int argc, char *argv[]);
    ~ControllerAlgorithmMode();
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

    int64_t getAlgorithmComparisons(SortingAlgorithm &algorithmParam, int *dataType, int size);
    double getAlgorithmRunnningTime(SortingAlgorithm &algorithmParam, int *dataType, int size);
    void runSort(int *dataType, int size);

    void setData();
    void setAlgorithm(char *argv);
    void setOutputParameter(char *argv);
    void setInputOrder(char *argv);

    int* readFile();
};

#endif //CONTROLLER_H
