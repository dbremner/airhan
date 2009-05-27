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

#ifndef AIRHAN_DATASTRUCTURE_TREAP_H_
#define AIRHAN_DATASTRUCTURE_TREAP_H_

namespace lianghancn
{
    namespace air
    {
        namespace datastructures
        {
            template<typename T> class Treap
            {
            public:
                virtual ~Treap()
                {
                    // TODO - reclaim nodes
                }

                explicit Treap()
                {
                    _null = new Node<T>();
                    _root = new Node<T>(_null, _null, NULL, INT_MAX);
                }

            private:
                template<typename T> struct Node
                {
                    Node* left;
                    Node* right;
                    int rank; //heap property
                    T key; //bst property

                    Node()
                        : left(NULL)
                        , right(NULL)
                        , rank(INT_MAX) // here use min heap - root should always has lowest rank
                    {

                    }

                    Node(Node* l, Node* r, T key, int rank)
                        : left(l)
                        , right(r)
                        , key(key)
                        , rank(rank)
                    {

                    }
                };
            
            public:
                void Insert(T item)
                {
                    InternalInsert(_root, item);
                }
                
            private:
                void RotateLeft(Node<T>*& node)
                {
                    Node<T>* pivot = node->right;
                    node->right = pivot->left;
                    pivot->left = node;
                    node = pivot;
                }

                void RotateRight(Node<T>*& node)
                {
                    Node<T>* pivot = node->left;
                    node->left = pivot->right;
                    pivot->right = node;
                    node = pivot;
                }

                void InternalInsert(Node<T>*& node, T key)
                {
                    if (node == _null)
                    {
                        node = new Node<T>(_null, _null, key, rand()); // TODO - check for rand generator...

                        return;
                    }

                    if (key < node->key)
                    {
                        InternalInsert(node->left, key);

                        // fix heap property
                        if (node->left->rank < node->rank)
                        {
                            RotateRight(node);
                        }
                    }
                    else
                    {
                        InternalInsert(node->right, key);

                        // fix heap property
                        if (node->right->rank < node->rank)
                        {
                            RotateLeft(node);
                        }
                    }
                }

            private:
                Node<T>* _root;
                Node<T>* _null;

            private:
                Treap(const Treap&);
                Treap& operator=(const Treap&);
            };
        };
    };
};

#endif
