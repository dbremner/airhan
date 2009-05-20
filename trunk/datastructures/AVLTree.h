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

				}
				
				void Delete(T key)
				{

				}
				
				void Traverse()
				{

				}

			private:
				#define max(a,b) ((a) > (b) ? (a) : (b))
				
				// rotate root to left once with root's right child as the pivot
				Node<T>* LeftRotate(Node<T>* root)
				{
					Node<T>* pivot = root->right;
					root->right = pivot->left;
					root->height = max(root->left->height, root->right->height) + 1;
					pivot->left = root;
					pivot->height = max(pivot->left->height, pivot->right->height) + 1;

					return pivot;
				}
	
				// rotate root to right once with root's left child as the pivot
				Node<T>* RightRotate(Node<T>* root)
				{
					Node<T>* pivot = root->left;
					root->left = pivot->right;
					root->height = max(root->left->height, root->right->height) + 1;
					pivot->right = root;
					pivot->height = max(pivot->left->height, pivot->right->height) + 1;

					return pivot;
				}

				// rotate root's right child right, then rotate root left
				Node<T>* RightLeftRotate(Node<T>* root)
				{
					root->right = RightRotate(root->right);
					return LeftRotate(root);
				}

				// rotate root's left child left, then rotate root right
				Node<T>* LeftRightRotate(Node<T>* root)
				{
					root->left = LeftRotate(root->left);
					return RightRotate(root);
				}

			private:
				Node<T>* _root;
			};
		};
	};
};

#endif