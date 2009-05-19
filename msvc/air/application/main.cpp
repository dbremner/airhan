// TODO - swtich to use Google Test Framework

#include <iostream>

#include "sort/MergeSort.h"
#include "sort/BubbleSort.h"
#include "sort/InsertionSort.h"
#include "sort/SelectionSort.h"
#include "sort/HeapSort.h"
#include "sort/QuickSort.h"
#include "sort/CountSort.h"

#include "datastructures/BinaryHeap.h"
#include "datastructures/BinomialHeap.h"

using namespace lianghancn::air::sort;
using namespace lianghancn::air::datastructures;

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

    std::cout<<"Heap Sort"<<std::endl;

	HeapSort(a, 16);

	LH_PRINT_SORT_RESULT;
}

void quick_sort()
{
    LH_SORT_RAT;

    QuickSort(a, 16);

    LH_PRINT_SORT_RESULT;
}

void count_sort()
{
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    CountSort(a, 10, 256);

    for (int i = 0; i < 10; i ++)
	{
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
}

void binary_heap()
{
    BinaryHeap<int> heap(10, eMinHeap);
	heap.Insert(2);
	heap.Insert(4);
	heap.Insert(1);
	heap.Insert(8);
	heap.Insert(7);
	heap.Insert(9);
	heap.Insert(3);
	heap.Insert(14);
	heap.Insert(10);
	heap.Insert(16);

	for (int i = 0; i < 10; i ++)
	{
		std::cout<<heap.RemoveRoot()<<",";
	}

    std::cout<<std::endl;

    for (int i = 0; i < 30; i ++)
    {
        assert(heap.Insert(i));
    }
    for (int i = 0; i < 30; i ++)
    {
        std::cout<<heap.RemoveRoot()<<",";
    }
    std::cout<<std::endl;

    std::cout<<"randomized test"<<std::endl;
    int a[16] = {-1, 2, 10, 9, 8, 7, 0, 0, 3, 11, 20, 15, -90, 200, 100, -1};
    for (int i = 0; i < 16; i ++)
    {
        heap.Insert(a[i]);
    }
    for (int i = 0 ; i < 16; i ++)
    {
        std::cout<<heap.RemoveRoot()<<",";
    }
    std::cout<<std::endl;

    BinaryHeap<int> heap_max(10, eMaxHeap);
	heap_max.Insert(2);
	heap_max.Insert(4);
	heap_max.Insert(1);
	heap_max.Insert(8);
	heap_max.Insert(7);
	heap_max.Insert(9);
	heap_max.Insert(3);
	heap_max.Insert(14);
	heap_max.Insert(10);
	heap_max.Insert(16);

	for (int i = 0; i < 10; i ++)
	{
		std::cout<<heap_max.RemoveRoot()<<",";
	}

	std::cout<<std::endl;
}


void binomial_heap()
{
    std::cout<<"Binomial Heap Merge Root test"<<std::endl;

    BinomialHeap<int> bheap;

    BinomialHeap<int>::Node<int> node00;
    BinomialHeap<int>::Node<int> node01;
    BinomialHeap<int>::Node<int> node02;
    BinomialHeap<int>::Node<int> node03;
    BinomialHeap<int>::Node<int> node04;
    BinomialHeap<int>::Node<int> node05;

    node00.degree = 1; node00.ptr_sibling = &node01;
    node01.degree = 10; node01.ptr_sibling = &node02;
    node02.degree = 11; node02.ptr_sibling = &node03;
    node03.degree = 22; node03.ptr_sibling = &node04;
    node04.degree = 999; node04.ptr_sibling = &node05;
    node05.degree = 1055; node05.ptr_sibling = NULL;

    BinomialHeap<int>::Node<int> node10;
    BinomialHeap<int>::Node<int> node11;
    BinomialHeap<int>::Node<int> node12;

    node10.degree = 3; node10.ptr_sibling = &node11;
    node11.degree = 50; node11.ptr_sibling = &node12;
    node12.degree = 9999; node12.ptr_sibling = NULL;

    BinomialHeap<int>::Node<int>* ptr_node = bheap.MergeRoots(&node00, & node10);

    while (ptr_node != NULL)
    {
        std::cout<<ptr_node->degree<<std::endl;
        ptr_node = ptr_node->ptr_sibling;
    }

	BinomialHeap<int> bio_heap;
	bio_heap.Insert(10);
	bio_heap.Insert(20);
	bio_heap.Insert(30);
	bio_heap.Insert(25);
	bio_heap.Insert(0);
	bio_heap.Insert(-10);

	// now at least the heap is correct structure...
	
	for (int i = 0; i < 6; i ++)
	{
		std::cout<<bio_heap.RemoveRoot()<<",";
	}
	
}


int main()
{
   merge_sort();

   bubble_sort();

   insertion_sort();

   selection_sort();

   heap_sort();

   quick_sort();

   count_sort();

   binary_heap();

   binomial_heap();
}