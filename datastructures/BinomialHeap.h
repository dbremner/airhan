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
#ifndef AIRHAN_DATASTRUCTURE_BINOMIALHEAP_H_
#define AIRHAN_DATASTRUCTURE_BINOMIALHEAP_H_

#include "IHeap.h"

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<typename T> class BinomialHeap : public IHeap<T>
			{
			public:
				virtual ~BinomialHeap(){};

				bool Insert(T item)
				{
					(item);
					return true;
				}

				T RemoveRoot()
				{
					T a;
					return a;
				}

				T PeekRoot() const
				{
					return 0;
				}

			private:
				BinomialHeap(const BinomialHeap&);
				BinomialHeap& operator=(const BinomialHeap&);
			};
		};
	};
};

#endif