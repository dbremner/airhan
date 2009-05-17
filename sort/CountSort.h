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
#ifndef AIRHAN_SORT_COUNTSORT_H_
#define AIRHAN_SORT_COUNTSORT_H_

#include <iostream>
#include <assert.h>

namespace lianghancn
{
	namespace air
	{
		namespace sort
		{
            // it only works for positive integer array
			template<typename T> void CountSort(T a[], int n, int k)
			{
				T* pCount = new T[k];
				T* pOld = new T[n];
					
				// initialize count array
				for (int i = 0; i < k; i ++)
				{
					pCount[i] = 0;
				}
				
				// copy original array and 1st pass over count array
				for (int i = 0; i < n; i ++)
				{					
					pOld[i] = a[i];
					pCount[a[i]] ++;
				}

				// 2nd pass over count array to make it accumulative
				for (int i = 1; i < k; i ++)
				{
                    pCount[i] = pCount[i - 1] + pCount[i];
				}

				// final pass over both array to directly put element to its deserved position
				for (int i = n - 1; i >= 0; i --)
				{
					a[pCount[pOld[i]] - 1] = pOld[i];

                    pCount[pOld[i]] -- ;
				}

				delete[] pCount;
				delete[] pOld;
			}
		};
	};
};

#endif