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
#ifndef AIRHAN_DATASTRUCTURE_BINARYHEAP_H_
#define AIRHAN_DATASTRUCTURE_BINARYHEAP_H_

#include "IHeap.h"
#include <stdlib.h>

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<typename T> class BinaryHeap : public IHeap<T>
			{
			public:
				BinaryHeap(int capacity, tHeapType eHeapType)
					: _count(0)
					, _capacity(capacity)
					, _tHeapType(eHeapType)
				{
					_pNodes = (T*)malloc(sizeof(T)*_capacity);
				}
				
				virtual ~BinaryHeap()
				{
					free(_pNodes);
				}

				bool Insert(T item)
				{
					if (_capacity < _count + 1)
					{
						_capacity *= 2;
						_pNodes = (T*)realloc(_pNodes, _capacity * sizeof(T));
					}

                    // we put new comer at the end of the array in the first place then let it bubble up
					int index = _count ++;
					
                    // n is parent index
					for (int n = (index - 1) / 2; n >= 0; n --)
					{
						if (HeapComparator(_pNodes[n], item))
						{
							break;
						}
						else
						{
							_pNodes[index] = _pNodes[n];
							index = n;
						}
					}

					_pNodes[index] = item;
					return true;
				}

				T RemoveRoot()
				{
					T temp = _pNodes[0];
					_pNodes[0] = _pNodes[_count - 1];
					_count --;

					FixDown(_pNodes, 0, _count - 1); 
					
					return temp;
				}

				T PeekRoot() const
				{
					return _pNodes[0];
				}

			private:
				template<typename T> void FixDown(T a[], int root, int bottom)
				{
					bool done = false;
					int swap_child_index = 0;

					while ( 2 * root + 1 <= bottom && !done)
					{
						int l = 2 * root + 1;
						int r = l + 1;

						if (HeapComparator(a[l], a[r]))
						{
							swap_child_index = l;
						}
						else
						{
							swap_child_index = r;
						}

						if (HeapComparator(a[swap_child_index], a[root]))
						{
							T temp = a[root];
							a[root] = a[swap_child_index];
							a[swap_child_index] = temp;

							root = swap_child_index;
						}
						else
						{
							done = true;
						}
					}
				}

                //
                //\param a - parent
                //\param b - child
                //\return - true if for max heap, parent > child; for min heap parent < child. as a summary, the func return true whenever both elements
                // are in correct place in the heap.
                //
				template<typename T> bool HeapComparator(T a, T b)
				{
					if (_tHeapType == eMaxHeap)
					{
						return a > b ? true : false;
					}
					else if (_tHeapType == eMinHeap)
					{
						return a < b ? true : false;
					}

					return false;
				}

			private:

				T* _pNodes;
				int _count;
				int _capacity;
				tHeapType _tHeapType;

			private:
				BinaryHeap(const BinaryHeap&);
				BinaryHeap& operator=(const BinaryHeap&);
			};
		};
	};
};

#endif