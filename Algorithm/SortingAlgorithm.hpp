//SortingAlgorithm.hpp
#pragma once
#ifndef SORTINGALGORITHM_H_INCLUDE
#define SORTINGALGORITHM_H_INCLUDE

namespace sort {
#include <stdio.h>
#include <Windows.h>
#include <math.h>

#define EXIT_SUCCESS 0

	//Function Declaration
	int SortingAlgorithm(int argc, char* argv);
	int insertion_sort(int *arr, unsigned int n);
	int selection_sort(int *arr, unsigned int n);
	int binary_sort(int *arr, int n);
	int Merge(int *sourceArr, int *tempArr, int startIndex, int midIndex, int endIndex);
	int merge_sort(int *arr, int startIndex, int endIndex);
	int HeapAdjust(int *arr, int i, int nLength);
	int heap_sort(int *arr, int n);
	int quick_sort(int *arr, int left, int right);
	int shell_sort(int *arr, int start, int end);
	BOOL comb_sort(int *array, int size);
}

#endif // !SORTINGALGORITHM_H_INCLUDE

