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
				explicit BinaryHeap(int capacity)
					: _count(0)
					, _capacity(capacity)
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
						_pNodes = (T*)realloc(_pNodes, _capacity);
						if (_pNodes == NULL)
						{
							return false;
						}
					}

					int index = _count ++;
					
					for (int n = _count/2 - 1; n >= 0; n --)
					{
						if (_pNodes[n] > item)
						{
							break;
						}
						else
						{
							_pNodes[index] = _pNodes[n];
						//	_pNodes[n] = item;
							index = n;
						}
					}

					_pNodes[index] = item;
					return true;
				}

				T RemoveRoot()
				{
					return _pNodes[0];
				}

				T PeekRoot() const
				{
					return _pNodes[0];
				}

			private:
				T* _pNodes;
				int _count;
				int _capacity;

			private:
				BinaryHeap(const BinaryHeap&);
				BinaryHeap& operator=(const BinaryHeap&);
			};
		};
	};
};