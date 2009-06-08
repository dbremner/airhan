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
#include "datastructures/Deque.h"
#include "datastructures/AVLTree.h"
#include "datastructures/RedBlackTree.h"
#include "datastructures/SplayTree.h"
#include "datastructures/Treap.h"
#include "datastructures/SkipList.h"

#include "compression/Huffman.h"

#if defined(_WIN32) || defined(_WIN64)
// VC CRT memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace lianghancn::air::sort;
using namespace lianghancn::air::datastructures;
using namespace lianghancn::air::compression;

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

    BinomialHeap<int> bio_heap(eMaxHeap);
	bio_heap.Insert(10);
	bio_heap.Insert(20);
	bio_heap.Insert(30);
	bio_heap.Insert(25);
	bio_heap.Insert(0);
	bio_heap.Insert(-10);
    bio_heap.Insert(999);
    
    for (int i = 50; i < 60; i ++)
    {
        bio_heap.Insert(i);
    }

	// now at least the heap is correct structure...
	
	for (int i = 0; i < 17; i ++)
	{
		std::cout<<bio_heap.RemoveRoot()<<",";
	}
	
    std::cout<<std::endl;

	for (int i = 0; i < 50; i ++)
	{
		bio_heap.Insert(rand());
	}

	for (int i = 0; i < 50; i ++)
	{
		std::cout<<bio_heap.RemoveRoot()<<";";
	}

	std::cout<<std::endl;
	std::cout<<"binomail heap test over"<<std::endl;
}



void deque_test()
{
	Deque<int> deque;
	// something looks like...
	// 
	// come on migrate to google ut soon!
	assert(deque.Empty());
	deque.EnqueHead(1);
	assert( 1 == deque.DequeTail());
	assert( deque.Empty());
	// 4,1,2,3
	deque.EnqueHead(1);
	deque.EnqueTail(2);
	deque.EnqueTail(3);
	deque.EnqueHead(4);
	assert(deque.DequeTail() == 3);
	assert(deque.DequeTail() == 2);
	assert(deque.DequeHead() == 4);
	assert(deque.Empty() == false);
	assert(deque.DequeTail() == 1);
}

void avl_tree()
{
    AVLTree<int> avl;
    
#define AVL_LOOP for (int i = 0; i <10; i ++)

	AVL_LOOP
    {
		avl.Insert(i);
    }

	AVL_LOOP
	{
		 avl.Delete(i);
	}

	AVL_LOOP
	{
		assert(!avl.Exists(i));
	}
}

void splay_tree()
{
    SplayTree<int> splayTree;
    
#define SPLAY_LOOP for (int i = 0; i < 20; i ++)

	SPLAY_LOOP
    {
        splayTree.Insert(i);
    }

	SPLAY_LOOP
    {
        assert(splayTree.Exists(i));
    }

	SPLAY_LOOP
    {
        splayTree.Delete(i);
    }

	SPLAY_LOOP
     {
         assert(!splayTree.Exists(i));
     }
}

void treap()
{
    Treap<int> treap;

#define TREAP_LOOP   for (int i = 0; i < 1000; i ++)

	TREAP_LOOP
	{
		treap.Insert(i);
		assert(treap.GetMin() == 0);
		assert(treap.GetMax() == i);
	}

	std::cout<<"Treap constructed"<<std::endl;
	// print keys in sorted order
	treap.InOrderTraversal();

	TREAP_LOOP
	{
		assert(treap.Exists(i));
	}

	TREAP_LOOP
	{
		treap.Delete(i);
	}

	TREAP_LOOP
	{
		assert(!treap.Exists(i));
	}
}

void skip_list()
{
	SkipList<int> skiplist;
	
#define SKIP_LIST_LOOOP for (int i = 0; i < 20; i ++)

	SKIP_LIST_LOOOP
	{
		std::cout<<skiplist.RandomLevel()<<std::endl;
	}

	SKIP_LIST_LOOOP
	{
		skiplist.Insert(i);
	}

	SKIP_LIST_LOOOP
	{
		assert(skiplist.Exists(i));
	}

	SKIP_LIST_LOOOP
	{
		skiplist.Delete(i);
		assert(!skiplist.Exists(i));
	}

	SKIP_LIST_LOOOP
	{
		assert(!skiplist.Exists(i));
	}
}

void algorithm_ds_suite()
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

    avl_tree();

    splay_tree();

    treap();

    skip_list();
}


void huffman_suite()
{
    HuffmanEncoder encoder;

//#define HUFFMAN_TEST_BITS_IO
#ifdef HUFFMAN_TEST_BITS_IO
    value_type buffer[2] = {0xAB, 0xCD};

    for (int i = 0; i < 16; i ++)
    {
        short temp = encoder.GetBit(buffer, i);
        std::cout<<temp;
    }

    std::cout<<std::endl;

    encoder.ReverseBits(buffer, 16);

    for (int i = 0; i < 16; i ++)
    {
        short temp = encoder.GetBit(buffer, i);
        std::cout<<temp;
    }

    std::cout<<std::endl;
#endif

    encoder.ScanFrequency("C:\\MIT.txt");
    encoder.BuildHuffmanTree();
}

int main()
{
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );

    //algorithm_ds_suite();

    huffman_suite();

    _CrtDumpMemoryLeaks(); 
}