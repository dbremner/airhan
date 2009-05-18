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

                BinomialHeap(){};

				bool Insert(T item)
				{
					(item);
					return true;
				}

				T RemoveRoot()
				{
					return 0;
				}

				T PeekRoot() const
				{
					return 0;
				}

                // fwd declare TODO remove this
                template<typename T> struct Node;

                // link a with b such that a is the child of b
                template<typename T> Node<T>* LinkNodes(Node<T>* a, Node<T>* b)
                {
                    a->ptr_parent = b;
                    b->ptr_child = a;
                    a->ptr_sibling = b->ptr_child;
                    b->degree = b->degree + 1;
                }

                // TODO - privaterize these
                template<typename T> Node<T>* MergeRoots(Node<T>* a, Node<T>* b)
                {   
                    Node<T>* final = NULL;
                    Node<T>* current = NULL;

                    if (a == NULL)
                    {
                        return b;
                    }

                    if (b == NULL)
                    {
                        return a;
                    }

                    if (a->degree < b->degree)
                    {
                        final = a;
                        a = a->ptr_sibling;    
                    }
                    else
                    {
                        final = b;
                        b = b->ptr_sibling;
                    }

                    current = final;
                    current->ptr_sibling = NULL;

                    while ( (a != NULL) && (b != NULL))
                    {
                        if (a->degree < b->degree)
                        {
                            current->ptr_sibling = a;
                            a = a->ptr_sibling;
                        }
                        else
                        {
                            current->ptr_sibling = b;
                            b = b->ptr_sibling;
                        }

                        current = current->ptr_sibling;
                        current->ptr_sibling = NULL;
                    }

                    if (a != NULL)
                    {
                        current->ptr_sibling = a;
                    }
                    else
                    {
                        current->ptr_sibling = b;
                    }

                    return final;
                }

                // union heap a and b together return new root 
                template<typename T> Node<T>* HeapUnion(Node<T>* a, Node<T>* b)
                {

                }

                template<typename T> struct Node
                {
                    Node* ptr_parent;
                    T key;
                    int degree;
                    Node* ptr_child;
                    Node* ptr_sibling;

                    Node()
                        : ptr_child(NULL)
                        , ptr_sibling(NULL)
                        , ptr_parent(NULL)
                        , degree(0) {}
                };

                // root (or roots.. reachable via siblings) of the heap
                Node<T>* _ptr_root;

			private:
				BinomialHeap(const BinomialHeap&);
				BinomialHeap& operator=(const BinomialHeap&);
			};
		};
	};
};

#endif