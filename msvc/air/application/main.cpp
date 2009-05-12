// TODO - swtich to use Google Test Framework

#include <iostream>

#include "sort/MergeSort.h"
#include "sort/BubbleSort.h"
#include "sort/InsertionSort.h"
#include "sort/SelectionSort.h"
#include "sort/HeapSort.h"
#include "sort/QuickSort.h"

using namespace lianghancn::air::sort;

#define LH_SORT_RAT int a[16] = {-1, 2, 10, 9, 8, 7, 0, 0, 3, 11, 20, 15, -90, 200, 100, -1}

#define LH_PRINT_SORT_RESULT \
   for (int i = 0; i < 16; i ++) \
    { \
        std::cout<<a[i]<<" "; \
    }\
	std::cout<<std::endl 


void merge_sort()
{
	LH_SORT_RAT;
    
    MergeSort(a, 16, false);

	LH_PRINT_SORT_RESULT;
}

void bubble_sort()
{
	LH_SORT_RAT;

    BubbleSort(a, 16);

	LH_PRINT_SORT_RESULT;
}

void insertion_sort()
{
	LH_SORT_RAT;

	BubbleSort(a, 16);

	LH_PRINT_SORT_RESULT;
}

void selection_sort()
{
	LH_SORT_RAT;

	SelectionSort(a, 16);

	LH_PRINT_SORT_RESULT;
}

void heap_sort()
{
	LH_SORT_RAT;

	HeapSort(a, 16);

	LH_PRINT_SORT_RESULT;
}

void quick_sort()
{
    LH_SORT_RAT;

    QuickSort(a, 16);

    LH_PRINT_SORT_RESULT;
}

int main()
{
   merge_sort();

   bubble_sort();

   insertion_sort();

   selection_sort();

   heap_sort();

   quick_sort();
}