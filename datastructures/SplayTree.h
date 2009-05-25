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

#ifndef AIRHAN_DATASTRUCTURE_SPLAYTREE_H_
#define AIRHAN_DATASTRUCTURE_SPLAYTREE_H_

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<typename T> class SplayTree
			{
			public:
				virtual ~SplayTree()
				{
					// TODO - reclaim nodes
				}

                SplayTree()
                    : _root(NULL)
                    , _size(0)
                {
                   
                }

            public:
                void Insert(T item)
                {
                    Node<T>* node = new Node<T>(item, NULL, NULL);
                    
                    if (_root == NULL)
                    {
                        node->left = NULL;
                        node->right = NULL;
                        _size = 1;
                        
                        _root = node;
                        return;
                    }

                    Splay(item, _root);

                    if (item < _root->key) 
                    {
                        node->left = _root->left;
                        node->right = _root;
                        _root->left = NULL;
                       
                        _size ++;
                        _root = node;
                    } 
                    else if (item > _root->key) 
                    {
                        node->right = _root->right;
                        node->left = _root;
                        _root->right = NULL;

                        _size ++;
                        _root = node;
                    } 
                    else 
                    { 
                        // TODO smart ptr?
                        delete node;
                    }
                }


                void Delete(T item)
                {
                    Node<T>* temp = NULL;

                    if (_root ==NULL)
                    {
                        return;
                    }

                    Splay(item, _root);

                    if (item == _root->key) 
                    {             
                        if (_root->left == NULL)
                        {
                            temp = _root->right;
                        } 
                        else 
                        {
                            Splay(item, _root->left);
                            temp->right = _root->right;
                        }

                        _size --;
                        
                        delete _root;
                        _root = temp;
                    }
                }

                bool Exists(T item)
                {
                    Node<T>* node = _root;

                    while (node != NULL)
                    {
                        if (node->key == item)
                        {
                            // before return splay it!
                            Splay(item, _root);
                            return true;
                        }
                        else if (node->key > item)
                        {
                            node = node->left;
                        }
                        else
                        {
                            node = node->right;
                        }
                    }

                    return false;
                }

			private:
				template<typename T> struct Node
				{
					Node* left;
					Node* right;
					T key;

					Node()
						: left(NULL)
						, right(NULL)
					{

					}

                    Node(T item, Node* l, Node* r)
                        : key(item)
                        , left(l)
                        , right(r)
                    {

                    }
				};

			private:
				void Splay(T key, Node<T>*& root)
				{
					//
					// top down splay
					// algorithm described in the orignial splay tree paper by Sleator and Tarjan / Self-Adjusting Binary Trees
					// this algorithm searches two nodes at a time, partition the tree into three parts : left tree, middle tree, right tree.
					// 
					// left tree - consisting all known nodes with key smaller than target key
					// right tree - consisting all know nodes with key bigger than target key
					// middle tree - all nodes doesn't belong to either left tree or right tree
					//
					// the search starts at the middle tree (the default tree root) and gets moving down. As the search encounters a node,
					// it will check the key field of the node and based on what described above, cut the node out of middle tree and put it
					// into either left tree or right tree; repeat this process until find the key or reach null nodes.
					// Then assemble left tree with middle tree and right tree to finish the transform (splaying) process.
					//
					
					// left - ptr to left tree
					// right - ptr to right tree
					// temp - temp root
					Node<T> node, *left, *right, *temp;
					
					if (root == NULL)
					{
						return;
					}

					left = right = &node;

					for (;;) 
					{
						if (key < root->key) 
						{
							if (root->left == NULL) 
							{
								break;
							}

							if (key < root->left->key) 
							{
								temp = root->left;                           /* rotate right */
								root->left = temp->right;
								temp->right = root;
								root = temp;
								
								if (root->left == NULL) 
								{
									break;
								}
							}

							right->left = root;                               /* link right */
							right = root;
							root = root->left;
						} 
						else if (key >root->key) 
						{
							if (root->right == NULL) 
							{
								break;
							}

							if (key > root->right->key) 
							{
								temp = root->right;                          /* rotate left */
								root->right = temp->left;
								temp->left = root;
								root = temp;

								if (root->right == NULL) 
								{
									break;
								}
							}

							left->right = root;                              /* link left */
							left = root;
							root = root->right;
						} 
						else 
						{
							break;
						}
					}

					left->right = root->left;                                /* assemble */
					right->left = root->right;
					root->left = node.right;
					root->right = node.left;
				}
				
			private:
				Node<T>* _root;
                int _size;

			private:
				SplayTree(const SplayTree&);
				SplayTree& operator=(const SplayTree&);
			};
		};
	};
};

#endif