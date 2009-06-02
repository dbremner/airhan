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

#include <vector>
#include "IHeap.h"

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<class T> class BinomialHeap : public IHeap<T>
			{
			public:
				virtual ~BinomialHeap()
				{
                    for (std::vector<Node<T>*>::iterator iterator = _nodes_list.begin(); iterator != _nodes_list.end(); ++ iterator)
                    {
                        delete *iterator;
                    }
				};

                BinomialHeap(tHeapType eHeapType)
					: _ptr_root (NULL)
                    , _tHeapType(eHeapType)
				{
				}

				bool Insert(T item)
				{
                    // construct a one node binomial heap
					Node<T>* node = new Node<T>();
					node->key = item;
					
                    // union current heap with new heap
					_ptr_root = HeapUnion(node, _ptr_root);
					
                    // store the ptr of new node in to the vector so it could be destroyed when heap is destructed else we'd traverse the heap to destroy everything...
                    _nodes_list.push_back(node);
                    return true;
				}

				T RemoveRoot()
				{
                    // the min/max node to be removed from binomial tree
                    Node<T>* remove = NULL;
                    T final = _ptr_root->key;

                    {  
                        // locate the node to be removed
                        Node<T>* current = _ptr_root;
                        
                        while(current != NULL)
                        {
                            if (HeapComparator(current->key, final))
                            {
                                final = current->key;
                            }

                            current = current->ptr_sibling;
                        }

                        current = _ptr_root;
                        Node<T>* previous = NULL;

                        while(current != NULL)
                        {
                            if (current->key == final)
                            {
                                break;
                            }

                            previous = current;
                            current = current->ptr_sibling;
                        }

                        // remove the node from linked root list 
                        if (previous == NULL)
                        {
                            remove = _ptr_root;
                            _ptr_root = _ptr_root->ptr_sibling;
                        }
                        else
                        {
                            remove = current;
                            previous->ptr_sibling = current->ptr_sibling;
                        }
                    }

					Node<T>* child = remove->ptr_child;
                    Node<T>* temp1 = child;
                    Node<T>* temp2 = NULL;
                    Node<T>* temp3 = NULL;

                    // reverse the linked list of the child and its siblings, of the node just get removed.
                    // so new linked list of nodes forms a new binomial heap
                    while ( temp1 )
                    {
                        child = temp1; //set the head to last node		
                        temp2= temp1->ptr_sibling; // save the next ptr in temp2
                        temp1->ptr_sibling = temp3; // change next to privous
                        temp3 = temp1;
                        temp1 = temp2;
                    }

                    // merge the child (and its siblings) with old roots to form new root list of the binomial heap
					_ptr_root = MergeRoots(_ptr_root, child);

					return final;
				}

                // TODO - implement this..
				T PeekRoot() const
				{
					return 0;
				}

                private:
                    // node structure of the binomial heap
                    template<class T> struct Node
                    {
                        Node* ptr_parent; // pointer to parent
                        T key; // key payload
                        int degree; // degree (number of children)
                        Node* ptr_child; // (ptr to child)
                        Node* ptr_sibling; // (ptr to sibling)

                        Node()
                            : ptr_child(NULL)
                            , ptr_sibling(NULL)
                            , ptr_parent(NULL)
                            , degree(0) {}
                    };

                // link a with b to make a the child of b
                template<class T> Node<T>* LinkNodes(Node<T>* a, Node<T>* b)
                {
                    a->ptr_parent = b;
					a->ptr_sibling = b->ptr_child;
                    b->ptr_child = a;
                    b->degree = b->degree + 1;

					return b;
                }

                template<class T> Node<T>* MergeRoots(Node<T>* a, Node<T>* b)
                {   
                    // this is actually the problem of two sorted linked list...
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
                template<class T> Node<T>* HeapUnion(Node<T>* a, Node<T>* b)
                {
					Node<T>* root = MergeRoots(a, b);
					if (root == NULL)
					{
						return NULL;
					}

					// this algorithm is described in CLRS..
					Node<T>* previous = NULL;
					Node<T>* current = root;
					Node<T>* next = root->ptr_sibling;

					while (next != NULL)
					{
						if (current->degree != next->degree || ((next->ptr_sibling != NULL) && ( next->degree == next->ptr_sibling->degree)))
						{
							previous = current;
							current = next;
						} 
						else if (HeapComparator(current->key, next->key))
						{
							current->ptr_sibling = next->ptr_sibling;
							LinkNodes(next, current);
						}
						else
						{
							if (previous == NULL)
							{
								root = next;
							}
							else
							{
								previous->ptr_sibling = next;
							}

							LinkNodes(current, next);
							current = next;
						}

						next = current->ptr_sibling;
					}

					return root;
                };
            
                private:
                    //
                    //\param a - parent
                    //\param b - child
                    //\return - true if for max heap, parent > child; for min heap parent < child. as a summary, the func return true whenever both elements
                    // are in correct place in the heap.
                    //
                    template<class T> bool HeapComparator(T a, T b)
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

                    // root (or roots.. reachable via siblings) of the heap
                    Node<T>* _ptr_root;

                    std::vector<Node<T>*> _nodes_list;

                    tHeapType _tHeapType;

			private:
				BinomialHeap(const BinomialHeap&);
				BinomialHeap& operator=(const BinomialHeap&);
			};
		};
	};
};

#endif