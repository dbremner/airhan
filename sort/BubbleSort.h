/***************************************************************

Copyright (c) 2008 Michael Liang Han

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

****************************************************************/
#ifndef AIRHAN_SORT_BUBBLESORT_H_
#define AIRHAN_SORT_BUBBLESORT_H_

namespace lianghancn
{
    namespace air
    {
        namespace sort
        {
            template<class T> void BubbleSort(T a[], int n)
            {
                //
                // two optimizations over naive bubble sort
                // 1. use bound to indicate upper bound for unsorted array
                // 2. use swapped to test if the array is sorted or not
                //
                int bound = n - 1;
                bool swapped = false;

                for (int i = 1; i <= n; i ++)
                {
                    int _bound = 0;
                    for (int j = 0; j < bound; j ++)
                    {
                        if (a[j] > a[j+1])
                        {
                            T temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;

                            _bound = j - 1;
                            swapped = true;
                        }
                    }

                    if (!swapped)
                    {
                        break;
                    }
                }
            }
        };
    };
};

#endif