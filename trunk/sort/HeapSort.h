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
#ifndef AIRHAN_SORT_HEAPSORT_H_
#define AIRHAN_SORT_HEAPSORT_H_

namespace lianghancn
{
    namespace air
    {
        namespace sort
        {
            template<class T> void HeapSort(T a[], int n)
            {
                //
                // build heap
                //
                for (int i = n/2 - 1; i >= 0; i --)
                {
                    FixDown(a, i, n -1);
                }

                //
                // swap and heapify
                //
                for (int i = n -1; i >= 1; i --)
                {
                    T max = a[0];
                    a[0] = a[i];
                    a[i] = max; 

                    FixDown(a, 0, i -1);
                }
            }

            template<class T> void FixDown(T a[], int root, int bottom)
            {
                bool done = false;
                int max_child_index = 0;

                while ( 2 * root + 1 <= bottom && !done)
                {
                    int l = 2 * root + 1;
                    int r = l + 1;
                
                    if ( l == bottom)
                    {
                        max_child_index = l;
                    }
                    else if (a[l] > a[r])
                    {
                        max_child_index = l;
                    }
                    else
                    {
                        max_child_index = r;
                    }

                    if (a[root] < a[max_child_index])
                    {
                        T temp = a[root];
                        a[root] = a[max_child_index];
                        a[max_child_index] = temp;

                        root = max_child_index;
                    }
                    else
                    {
                        done = true;
                    }
                }
            }
        };
    };
};

#endif