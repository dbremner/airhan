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

#ifndef AIRHAN_DATASTRUCTURE_AVLTREE_H_
#define AIRHAN_DATASTRUCTURE_AVLTREE_H_

namespace lianghancn
{
	namespace air
	{
		namespace datastructures
		{
			template<typename T> class AVLTree
			{
			public:
				virtual ~AVLTree()
				{
                    delete _null;

					// TODO = traverse the tree to free the nodes.
					// Better, all nodes should be allocated from a memory pool..
				}

				AVLTree()
				{
					_null = new Node<T>(0, 0, NULL, NULL);
					// use the null node to prevent checking the nullability of l/r child..
					_root = _null;
				}

			private:
				template<typename T> struct Node
				{
					T key;
					int height;
					Node* left;
					Node* right;
					// Node* parent; use this to iterate bottom up to root to rewind the stack.
					// else use recursion and let compiler maintain the stack..

					Node(T item)
						: key(item)
						, height(0)
						, left(NULL)
						, right(NULL)
					{}

					Node(T item, int height, Node* left, Node* right)
						: key(item)
						, height(height)
						, left(left)
						, right(right)
					{}
				};

			public:
				void Insert(T key)
				{
					InternalInsert(_root, key);
				}
				
				void Delete(T key)
				{
					InternalDelete(_root, key);
				}
				
				void Traverse()
				{

				}

				bool Exists(T item)
				{
					Node<T>* node = _root;

					while (node != _null)
					{
						if (node->key > item)
						{
							node = node->left;
						}
						else if(node->key < item)
						{
							node = node->right;
						}
						else
						{
							// find
							break;
						}
					}

					if (node == _null)
					{
						return false;
					}
					else
					{
						return true;
					}
				}

			private:            

           #define AIRHAN_AVL_NODE_UPDATE_HEIGHT(node) \
				if (node->left->height > node->right->height) \
				{ \
					node->height = node->left->height + 1; \
				} \
				else \
				{ \
					node->height = node->right->height + 1; \
				} \

                //
				// rotate root to left once with root's right child as the pivot. the pivot becomes new root while old root becomes left child of new root.
                //
                //        A                                             B
                //          \                                           / \
                //           B                    ------>         A   C
                //             \
                //              C
                //
                //    old root A -- > new root B
                //
				void LeftRotate(Node<T>*& root)
				{
					Node<T>* pivot = root->right;
					root->right = pivot->left;
					
					AIRHAN_AVL_NODE_UPDATE_HEIGHT(root);

					pivot->left = root;
					root = pivot;

					AIRHAN_AVL_NODE_UPDATE_HEIGHT(root);
				}
	
                //
				// rotate root to right once with root's left child as the pivot
                // return new root after rotate
                //
                //         A                                                 B
                //        /                                                  / \
                //       B                         ----------->      C   A
                //      /
                //     C
                // 
                //      old root A ---> new root B
                //
				void RightRotate(Node<T>*& root)
				{
					Node<T>* pivot = root->left;
					root->left = pivot->right;
                    
					AIRHAN_AVL_NODE_UPDATE_HEIGHT(root);

					pivot->right = root;
					root = pivot;

					AIRHAN_AVL_NODE_UPDATE_HEIGHT(root);
				}

                //
				// rotate root's right child right, then rotate root left
                //
                //             A                                       A                                                  C
                //               \                                        \                                                / \
                //                B                -------------->  C              --------------------> A  B
                //               /                                           \ 
                //              C                                            B
                //
                // old root B ---> new root C
                //
				void RightLeftRotate(Node<T>*& root)
				{
					RightRotate(root->right);
					LeftRotate(root);
				}

                //
				// rotate root's left child left, then rotate root right
                //
                //              A                                             A                                   C
                //             /                                              /                                    / \
                //            B           ------------------>      C     ------------------>   B  A
                //              \                                           /
                //               C                                        B
                //
                //       old root B ----> new root C
				void LeftRightRotate(Node<T>*& root)
				{
					LeftRotate(root->left);
					RightRotate(root);
				}

				void InternalInsert(Node<T>*& node, T item)
				{
					if (node == _null)
					{
						node = new Node<T>(item, 0, _null, _null);
						return;
					}

					// recursion
					if (item < node->key)
					{
						InternalInsert(node->left, item);
					}
					else
					{
						InternalInsert(node->right, item);
					}

					AIRHAN_AVL_NODE_UPDATE_HEIGHT(node);

					if(node->right != _null )
					{
						if( node->left->height+ 1== node->right->right->height )
						{
							LeftRotate(node);
						}
						else if( node->left->height+ 1== node->right->left->height )
						{
							RightLeftRotate(node);
						}
					}

					if( node->left != _null )
					{
						if( node->right->height+ 1== node->left->left->height )
						{
							RightRotate(node);
						}
						else if(node->right->height+ 1== node->left->right->height )
						{
							LeftRightRotate(node);
						}
					}
				}

				void InternalDelete(Node<T>*& node, T item)
				{
					while (node != _null)
					{
						if (node->key == item)
						{
							break;
						}
						else if (item < node->key)
						{
							node = node->left;
						}
						else
						{
							node = node->right;
						}
					}

					if (node == _null)
					{
						return;
					}

					if (node->right == _null)
					{
						Node<T>* delete_node = node;
						node = node->left;

						delete delete_node;
					}
					else 
					{
						// use the smallest node in right child as the replacement
						Node<T>* temp = node->right;
						while(temp->left!= _null ) 
						{
							temp= temp->left;
						}

						node->key= temp->key;
					}

					// fix heights
					AIRHAN_AVL_NODE_UPDATE_HEIGHT(node);
					if (node->left != _null)
					{
						AIRHAN_AVL_NODE_UPDATE_HEIGHT(node->left);
					}

					if (node->right != _null)
					{
						AIRHAN_AVL_NODE_UPDATE_HEIGHT(node->right);
					}

				}

				void InternalDeleteRotateHelper(Node<T>*& node)
				{
					if( node->right->height - node->left->height == 2  )
					{
						if(node->right->left->height<= node->right->right->height )
						{
							LeftRotate(node);
						}
						else
						{
							RightLeftRotate(node);
						}
					}
					else if(node->left->height- node->right->height == 2  )
					{
						if(node->left->right->height <= node->left->left->height )
						{
							RightRotate(node);
						}
						else
						{
							LeftRightRotate(node);							 
						}
					}
				}

			private:
				Node<T>* _root;
				Node<T>* _null;
			};
		};
	};
};

#endif