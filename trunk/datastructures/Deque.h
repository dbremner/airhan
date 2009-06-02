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

#ifndef AIRHAN_DATASTRUCTURE_DEQUE_H_
#define AIRHAN_DATASTRUCTURE_DEQUE_H_

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<class T> class Deque
			{
			public:
				virtual ~Deque()
				{
					while (! Empty())
					{
						DequeHead();
					}
				};

			private:
				template<class T> struct Entry
				{
					T payload;
					Entry* previous;
					Entry* next;

					Entry(T item)
						: previous(NULL)
						, next(NULL)
						, payload(item)
					{

					}
				};

			public:
				Deque()
					: _head(NULL)
					, _tail(NULL)
				{
					
				}

				void EnqueHead(T item)
				{
					Entry<T>* entry = new Entry<T>(item);
					entry->next = _head;
					entry->previous = NULL;
					
					if (_head == NULL)
					{
						_tail = entry;
					}
					else
					{
						_head->previous = entry;
					}

					_head = entry;
				}

				void EnqueTail(T item)
				{
					Entry<T>* entry = new Entry<T>(item);
					entry->previous = _tail;
					_tail = entry;

					if (entry->previous == NULL)
					{
						_head = _tail;
					}
				}

				T DequeHead()
				{
					if (_head == NULL)
					{
						return 0;
					}

					T payload = _head->payload;
					Entry<T>* entry = _head;

					_head = _head->next;

					if (_head == NULL)
					{
						_tail = NULL;
					}
					else
					{
						_head->previous = NULL;
					}

					delete entry;
					return payload;
				}

				T DequeTail()
				{
					if (_tail == NULL)
					{
						return 0;
					}

					T payload = _tail->payload;
					Entry<T>* entry = _tail;

					_tail = _tail->previous;

					if (_tail == NULL)
					{
						_head = NULL;
					}
					else
					{
						_tail->next = NULL;
					}

					delete entry;
					return payload;
				}

				T PeekHead()
				{
					if (_head == NULL)
					{
						return 0; // TODO?
					}

					return _head->payload;
				}

				T PeekTail()
				{
					if (_tail == NULL)
					{
						return 0;
					}

					return _tail->payload;
				}

				bool Empty()
				{
					return _head == NULL ? true : false;
				}

			private:
				Entry<T>* _head;
				Entry<T>* _tail;

			private:
				Deque(const Deque&);
				Deque& operator=(const Deque&);
			};
		};
	};
};

#endif