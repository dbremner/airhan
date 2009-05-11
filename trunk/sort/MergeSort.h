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
#include <assert.h>

namespace lianghancn
{
    namespace air
    {
        namespace sort
        {
            template<typename T> void Merge(T a[], T b[], T c[], int m, int n)
            {
               int i = 0, j = 0, k = 0;
               
               while (i < m && j < n)
               {
                   if (a[i] < b[j])
                   {
                       c[k++] = a[i++];
                   }
                   else
                   {
                       c[k++] = b[j++];
                   }
               }
               
               while (i < m)
               {
                   c[k++] = a[i++];     
               }

               while (j < n)
               {
                   c[k++] = b[j++];
               }

               assert( i == m && j == n);
            };

            //
            //              MergeSort - sort two arrays in nondecreasing order
            //              Two implementations : iterative bottom up merge (recursive = false) ; recursive merge (recursive = true)
            //
            template<typename T> void MergeSort(T a[], int n, bool recursive)
            {
                if (recursive)
                {
                    if (n==1)
                    {
                        return;
                    }

                    // recursive merge sort
                    int l = n/2;
                    MergeSort<T>(a, l, true);
                    MergeSort<T>(a + l, n - l, true);

                    // merge
                    T* t = new T[n];
                    Merge<T>(a, a+l, t, l, n - l);

                    // restore sorted
                    for (int i = 0; i < n;  i++)
                    {
                        a[i] = t[i];
                    }
                    delete[] t;
                }
                else
                {
                    // iterative bottom up merge - it only works if array length is power of 2
                    int m = 1;
                    for (; m < n; m *= 2);
                    if ( m != n)
                    {
                        MergeSort<T>(a, n, true);
                    }
                    else
                    {
                        T* pT = new T[n];
                        for(int s = 1; s < n; s *= 2 ) // s is the stride
                        {
                            for(int j = 0; j < (n - s); j += 2 * s ) // j is start index of a stride
                            {
                                Merge(a + j, a + j + s, pT + j, s, s); // merge adj strides together
                            }

                            for (int j = 0; j < n; j++) a[j] = pT[j];
                        }

                        delete[] pT;
                    }
                }
            }
        };
    };
};