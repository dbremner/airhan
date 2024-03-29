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
#ifndef AIRHAN_SORT_INSERTIONSORT_H_
#define AIRHAN_SORT_INSERTIONSORT_H_

namespace lianghancn
{
	namespace air
	{
		namespace sort
		{
			template<class T> void InsertionSort(T a[], int n)
			{
                std::cout<<"insertion sort"<<std::endl;

				for (int i = 1; i < n; i ++)
				{
					T temp = a[i];

                    int j = 0;
					for (j = i - 1; j >= 0; j --)
					{
						if (a[j] > temp)
						{
							a[j + 1] = a[j];
						}
                        else
                        {
                            break;
                        }
					}

					a[j + 1] = temp;
				}
			}
		};
	};
};

#endif