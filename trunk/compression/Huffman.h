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

#ifndef AIRHAN_COMPRESSION_HUFFMAN_H
#define AIRHAN_COMPRESSION_HUFFMAN_H

// TODO - clean up this
#include "assert.h"
#include <stdlib.h>

namespace lianghancn
{
    namespace air
    {
        namespace compression
        {
            struct HuffmanNode
            {
                // here use count as frequency
                // the more the count, the more the frequence and vice versa
                int count;
                HuffmanNode* parent;
                bool leaf;

                union
                {
                    struct
                    {
                        HuffmanNode* left;
                        HuffmanNode* right;
                    };

                    char symbol;
                };

                // construct a leaf huffman node
                HuffmanNode(char symbol, int count=0)
                {
                    this->count = count;
                    this->symbol = symbol;
                    leaf = true;
                    parent = NULL;
                }

                // construct a non leaf huffman node whose left / right children are left and right respectively.
                HuffmanNode(HuffmanNode* left, HuffmanNode* right)
                {
                    assert(left != NULL && right != NULL);
                    this->left = left;
                    this->right = right;
                    left->parent = this;
                    right->parent = this;

                    count = left->count + right->count;
                    leaf = false;
                    parent = NULL;
                }
            };

            struct HuffmanCode
            {
                unsigned char* codeBits;
                int codeLength;

				HuffmanCode()
					: codeLength(0)
					, codeBits(NULL)
				{
				}

				~HuffmanCode()
				{
					delete codeBits;
				}
            };

			struct LessThanFrequency
			{
				inline bool operator()(int lhs, const HuffmanNode &rhs) {return lhs < rhs.count;}
				inline bool operator()(const HuffmanNode &lhs, const HuffmanNode &rhs) const {return lhs.count < rhs.count;}
			};

            class HuffmanEncoder
            {
            public:
                HuffmanEncoder();
				HuffmanEncoder(int symbols);
                virtual ~HuffmanEncoder();

				void Initialize(HuffmanNode**& rNodes);

			private:
				void BuildCodes(HuffmanNode*& rNode);

			private:
				HuffmanCode** _codes;
				HuffmanNode** _nodes; 
				int _symbols;

            private:
                HuffmanEncoder(const HuffmanEncoder&);
                HuffmanEncoder& operator=(const HuffmanEncoder&);
            };

            class HuffmanDecoder
            {
            public:
                HuffmanDecoder(){};
                virtual ~HuffmanDecoder(){};

            private:
                HuffmanDecoder(const HuffmanDecoder&);
                HuffmanDecoder& operator=(const HuffmanDecoder&);
            };
        };
    };
};

#endif