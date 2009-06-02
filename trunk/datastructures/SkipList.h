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

#ifndef AIRHAN_DATASTRUCTURE_SKIPLIST_H_
#define AIRHAN_DATASTRUCTURE_SKIPLIST_H_

#include <ctime>
#include <cmath>

#define AIRHAN_SKIPLIST_MAX_LEVEL 16
#define AIRHAN_SKIPLIST_PROB 0.5

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<class T> class SkipList
			{
			private:
				template<class T> struct Node
				{
					T data;
					Node<T>** forward;

					Node(int level, T data)
					{
						forward = new Node<T>*[level + 1];
						for (int i = 0; i < level + 1; i ++)
						{
							forward[i] = NULL;
						}

						this->data = data;
					}

					~Node()
					{
						delete[] forward;
					}
				};

			public:
				virtual ~SkipList()
				{
					delete _header;
				}

				SkipList()
				{
					_header = new Node<T>(AIRHAN_SKIPLIST_MAX_LEVEL, T());
					_level = 0;
				}

				// test func
				int RandomLevel()
				{
					return GenerateRandomLevel();		
				}

				void Insert(T data)
				{
					Node<T>* current = _header;
					Node<T>* update[AIRHAN_SKIPLIST_MAX_LEVEL + 1];

					for (int i = 0; i < AIRHAN_SKIPLIST_MAX_LEVEL + 1; i ++)
					{
						update[i] = NULL;
					}

					for (int i = _level; i >= 0; i --)
					{
						while (current->forward[i] != NULL && current->forward[i]->data < data)
						{
							current = current->forward[i];
						}

						update[i] = current;
					}

					current = current->forward[0];

					if (current == NULL || current->data != data)
					{
						int level = GenerateRandomLevel();

						if (level > _level)
						{
							for (int i = _level + 1; i <= level; i ++)
							{
								update[i] = _header;
							}

							_level = level;
						}

						current = new Node<T>(level, data);

						for (int i = 0; i <= level; i ++)
						{
							current->forward[i] = update[i]->forward[i];
							update[i]->forward[i] = current;
						}
					}
				}

				bool Exists(const T& data)
				{
					Node<T>* current = _header;

					for (int i = _level; i >=0; i --)
					{
						while (current->forward[i] != NULL && current->forward[i]->data < data)
						{
							current = current->forward[i];
						}
					}

					current = current->forward[0];

					return current != NULL && current->data == data;
				}

				void Delete(const T& data)
				{
					Node<T>* current = _header;
					Node<T>* update[AIRHAN_SKIPLIST_MAX_LEVEL + 1];

					for (int i = 0; i < AIRHAN_SKIPLIST_MAX_LEVEL + 1; i ++)
					{
						update[i] = NULL;
					}

					for (int i = _level; i >= 0; i --)
					{
						while (current->forward[i] != NULL && current->forward[i]->data < data)
						{
							current = current->forward[i];
						}

						update[i] = current;
					}
					current = current->forward[0];

					if (current->data == data)
					{
						for (int i = 0; i <= _level; i++) 
						{
							if (update[i]->forward[i] != current)
							{
								break;
							}

							update[i]->forward[i] = current->forward[i];
						}

						delete current;

						while (_level > 0 && _header->forward[_level] == NULL) 
						{
							_level --;
						}
					}
				}

			private:
				int GenerateRandomLevel()
				{
					static bool seeded = false;

					if (!seeded)
					{
						srand((unsigned)time(NULL));		
						seeded = true;
					}

					int level = 1;
					while (((rand() * 1.0/RAND_MAX)) < AIRHAN_SKIPLIST_PROB && level < AIRHAN_SKIPLIST_MAX_LEVEL)
					{
						level ++;
					}

					return level;
				}

			private:
				Node<T>* _header;
				int _level;

			private:
				SkipList(const SkipList&);
				SkipList& operator=(const SkipList&);
			};
		};
	};
};

#endif