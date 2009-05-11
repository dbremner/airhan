#include <iostream>

#include "sort/MergeSort.h"
#include "sort/BubbleSort.h"
using namespace lianghancn::air::sort;

// temp test file - need to use gtest asap..

void merge_sort()
{
    int a[16] = {-1, 2, 10, 9, 8, 7, 0, 0, 3, 11, 15, 20, -90, 100, 200, -1};
    MergeSort(a, 16, false);

    for (int i = 0; i < 16; i ++)
    {
        std::cout<<a[i]<<",";
    }

    std::cout<<std::endl;
}

void bubble_sort()
{
    int a[16] = {-1, 2, 10, 9, 8, 7, 0, 0, 3, 11, 15, 20, -90, 100, 200, -1};
    BubbleSort(a, 16);

    for (int i = 0; i < 16; i ++)
    {
        std::cout<<a[i]<<",";
    }

    std::cout<<std::endl;
}

int main()
{
   merge_sort();

   bubble_sort();
}