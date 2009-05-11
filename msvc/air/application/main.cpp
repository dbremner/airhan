#include <iostream>

#include "sort/MergeSort.h"
using namespace lianghancn::air::sort;

// temp test file - need to use gtest asap..

int main()
{
    int a[8] = {-1, 2, 10, 9, 8, 7, 0, 0};
    MergeSort(a, 8, false);

    for (int i = 0; i < 8; i ++)
    {
        std::cout<<a[i]<<",";
    }

    std::cout<<std::endl;
}