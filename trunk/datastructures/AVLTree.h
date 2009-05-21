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
                    // TODO - traverse the tree and free all stuff ?
				}

				AVLTree()
					: _root(NULL)
				{

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
				};

			public:
				void Insert(T key)
				{
					InternalInsert(_root, key);
				}
				
				void Delete(T key)
				{

				}
				
				void Traverse()
				{

				}

			private:            

                 void UpdateNodeHeight(Node<T>* node)
                {
                    if (node->left != NULL && node->right != NULL)             
                    { 
                        if(node->left->height > node->right->height) 
                        { 
                            node->height = node->left->height + 1; 
                        } 
                        else 
                        { 
                            node->height = node->right->height + 1; 
                        } 
                    } 
                    else if (node->left == NULL) 
                    { 
                        if (node->right != NULL) 
                        { 
                            node->height = node->right->height + 1; 
                        } 
                    }
                    else if (node->right == NULL)
                    {
                        if (node->left != NULL)
                        {
                            node->height = node->left->height + 1;
                        }
                    }
                }


                //
				// rotate root to left once with root's right child as the pivot
                // return new root after rotate
                //
                //        A                                             B
                //          \                                           / \
                //           B                    ------>            A   C
                //             \
                //              C
                //
                //    old root A -- > new root B
                //
				Node<T>* LeftRotate(Node<T>* root)
				{
					Node<T>* pivot = root->right;
					root->right = pivot->left;
					UpdateNodeHeight(root);
                    root->height --; // note root has been rotated down
					pivot->left = root;
					UpdateNodeHeight(pivot);
					return pivot;
				}
	
                //
				// rotate root to right once with root's left child as the pivot
                // return new root after rotate
                //
                //         A                                                 B
                //        /                                                  / \
                //       B                         ----------->           A   C
                //      /
                //     C
                // 
                //      old root A ---> new root B
                //
				Node<T>* RightRotate(Node<T>* root)
				{
					Node<T>* pivot = root->left;
					root->left = pivot->right;
					UpdateNodeHeight(root);
                    root->height --; // root has been rotated down
					pivot->right = root;
					UpdateNodeHeight(pivot);

					return pivot;
				}

                //
				// rotate root's right child right, then rotate root left
                // return new root after rotate
                //
                //             A                                       A                                                  C
                //               \                                        \                                                / \
                //                B                -------------->       C              -------------------->          A  B
                //               /                                           \ 
                //              C                                            B
                //
                // old root B ---> new root C
                //
				Node<T>* RightLeftRotate(Node<T>* root)
				{
					root->right = RightRotate(root->right);
					return LeftRotate(root);
				}

                //
				// rotate root's left child left, then rotate root right
                // return new root after rotate
                //
                //              A                                             A                                   C
                //             /                                              /                                    / \
                //            B                   ------------------>      C     ----------------------->      B  A
                //              \                                           /
                //               C                                        B
                //
                //       old root B ----> new root C
				Node<T>* LeftRightRotate(Node<T>* root)
				{
					root->left = LeftRotate(root->left);
					return RightRotate(root);
				}

				void InternalInsert(Node<T>*& node, T item)
				{
					if (node == NULL)
					{
						node = new Node<T>(item);
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

					UpdateNodeHeight(node);
					
                    // this terrible hand coded if else table covers all the cases but .... any better approaches??
					if (node->right != NULL)
					{
                        if (node->left != NULL)
                        {
                            if (node->right->right != NULL)
                            {
                                if (node->left->height + 1 == node->right->right->height)
                                {
                                    node = LeftRotate(node);
                                }
                            }
                            else if (node->right->left != NULL)
                            {
                                if (node->left->height + 1 == node->right->left->height)
                                {
                                    node = RightLeftRotate(node);
                                }
                            }
                            else
                            {
                                if (node->left->left != NULL)
                                {
                                    if (node->right->height + 1 == node->left->left->height)
                                    {
                                        node = RightRotate(node);
                                    }
                                }
                                else if (node->left->right != NULL)
                                {
                                    if (node->right->height + 1 == node->left->right->height)
                                    {
                                        node = LeftRightRotate(node);
                                    }
                                }
                                // else both right and left balance..
                            }
                        }
                        else
                        {
                            if (node->right->height > 0)
                            {
                                node = LeftRotate(node);
                            }
                        }
					}

					if (node->left != NULL)
					{
                        if (node->right != NULL)
                        {
                            if (node->left->left != NULL)
                            {
                                if (node->right->height + 1 == node->left->left->height)
                                {
                                    node = RightRotate(node);
                                }
                            }
                            else if (node->left->right != NULL)
                            {
                               node = LeftRightRotate(node);
                            }
                            else
                            {
                                if (node->right->right != NULL)
                                {
                                    if (node->left->height + 1 == node->right->right->height)
                                    {
                                        node = LeftRotate(node);
                                    }
                                }
                                else if (node->right->left != NULL)
                                {
                                    if (node->left->height + 1 == node->right->left->height)
                                    {
                                        node = RightLeftRotate(node);
                                    }
                                }
                                // else both right and left are balanced
                            }
                        }
                        else
                        {
                            if (node->left->height > 0)
                            {
                                node = RightRotate(node);
                            }
                        }
					}
				}

			private:
				Node<T>* _root;
			};
		};
	};
};

#endif