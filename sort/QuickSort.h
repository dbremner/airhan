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

namespace lianghancn
{
    namespace air
    {
        namespace sort
        {
            template<typename T> void QuickSort(T a[], int n)
            {
                if (n <= 1)
                {
                    return;
                }

                // TODO - random select a pivot
                int pivot = 0;
                T v = a[pivot];
                int i = 0, j = n;

                for (;;)
                {
                    while (a[++ i] < v && i < n);
                    while (a[--j] > v);
                    
                    if (j <= i)
                    {
                        break;
                    }

                    T temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }

                T temp = a[i-1];
                a[i - 1] = a[pivot];
                a[pivot] = temp;

                QuickSort(a, i - 1);
                QuickSort(a + i, n - i);
            }
        };
    };
};