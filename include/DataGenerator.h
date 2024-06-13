#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <ctime>
#include <ctime>
#include <cstdlib>
// Function declarations
template <class T>
void Swap(T &a, T &b);

int *GenerateRandomData(int n);
int *GenerateSortedData(int n);
int *GenerateReverseData(int n);
int *GenerateNearlySortedData(int n);
int *GenerateData(int n, int dataType);
#endif // DATAGENERATOR_H