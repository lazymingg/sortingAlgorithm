#include "../include/DataGenerator.h"

template <class T>
void Swap(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------
// This function generates a random array
int *GenerateRandomData(int n)
{
	srand((unsigned int)time(NULL));

	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}

	return a;
}

// This function generates a sorted array (ascending order)
int *GenerateSortedData(int n)
{
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	return a;
}

// This function generates a reverse-sorted array (descending order)
int *GenerateReverseData(int n)
{
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}

	return a;
}

// This function generates a nearly-sorted array
int *GenerateNearlySortedData(int n)
{
	int *a = new int[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		Swap(a[r1], a[r2]);
	}

	return a;
}

int *GenerateData(int n, int dataType)
{
	int *resArr;
	switch (dataType)
	{
		case 0:
			resArr = GenerateRandomData(n);
			break;
			
		case 1:
			resArr = GenerateSortedData(n);
			break;

		case 2:
			resArr = GenerateReverseData(n);
			break;

		case 3:
			resArr = GenerateNearlySortedData(n);
			break;
	}

	return resArr;
}