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

#include <string.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

#include "Huffman.h"

using namespace lianghancn::air::compression;

HuffmanEncoder::HuffmanEncoder()
: _symbols(256)
, _nodes(NULL)
, _codes(NULL)
{

}

HuffmanEncoder::HuffmanEncoder(int symbols)
: _symbols(symbols)
, _nodes(NULL)
, _codes(NULL)
{

}

HuffmanEncoder::~HuffmanEncoder()
{
	delete[] _codes;
	delete[] _nodes;
}

void HuffmanEncoder::Initialize(lianghancn::air::compression::HuffmanNode**& rNodes)
{
	_nodes = rNodes;

	assert(sizeof(_nodes) == _symbols);

	_codes = new HuffmanCode*[_symbols];
}

void HuffmanEncoder::ReverseBits(value_type* codeBits, int bitsNumber)
{
    int bytesNumber = bitsNumber / 8 + ((bitsNumber % 8 == 0) ? 0 : 1) ;
    
    value_type* temp = NULL;
    size_t codeblockSize = bytesNumber * sizeof(*temp);
    temp = (value_type*)malloc(codeblockSize);
    memset(temp, 0, codeblockSize);    
    
    int currentByte = 0;

    for (int i = 0; i < bitsNumber; i ++)
    {
        if (i > 0 && i % 8 == 0)
        {
            currentByte ++;
        }

        temp[currentByte] |= (GetBit(codeBits, bitsNumber - i - 1) << (i % 8));
    }

    memcpy(codeBits, temp, codeblockSize);
    free(temp);
}

void HuffmanEncoder::BuildCodes(lianghancn::air::compression::HuffmanNode *&rNode)
{
	if (rNode == NULL)
	{
		return;
	}

	if (rNode->leaf)
	{ 
        HuffmanNode* current = rNode;
        int bitsNumber = 0;
        value_type* bits = NULL;

        while (current && current->parent)
        {
            int byteIndex = bitsNumber / 8;

            // reach byte boundary
            if (bitsNumber % 8 == 0)
            {
                // TODO - bad effeciency to grow one byte at a time!
                // code block should be preallocated - need another helper class here.
                bits = (value_type*)realloc(bits, byteIndex + 1);
                assert(bits);
                
                bits[byteIndex] = 0;
            }

            if (current == current->parent->right)
            {
                bits[byteIndex] |= 1 << (bitsNumber % 8);
            }

            bitsNumber ++;
            current = current->parent;
        }
       
        if (bits != NULL)
        {
            ReverseBits(bits, bitsNumber);
        }

        HuffmanCode* code = new HuffmanCode();
        code->codeLength = bitsNumber;
        code->codeBits = bits;

        _codes[rNode->symbol] = code;

	}
	else
	{
		BuildCodes(rNode->left);
		BuildCodes(rNode->right);
	}
}

bool HuffmanEncoder::BuildHuffmanTree()
{
    if (_nodes == NULL)
    {
        return false;
    }

    // TODO - use a better type
    std::vector<HuffmanNode*> nodeList;

    for (int i = 0; i < _symbols; i ++)
    {
        if (_nodes[i]->count != 0)
        {
            nodeList.push_back(_nodes[i]);
        }
    }

    std::make_heap(nodeList.begin(), nodeList.end(), LessThanFrequency());

    return true;
}

void HuffmanEncoder::ScanFrequency(const char *pName)
{
    FILE* file = fopen(pName, "rb");
    if (!file)
    {
        return;
    }

    HuffmanNode** nodes = new HuffmanNode*[_symbols];
    for (int i = 0; i < _symbols; i ++)
    {
        nodes[i] = NULL;
    }

    char c = 0;

    while ((c = (char)fgetc(file)) != EOF)
    {
        if (nodes[c] == NULL)
        {
            nodes[c] = new HuffmanNode(c, 1);
        }

        nodes[c]->count ++;
    }

    _nodes = nodes;
    fclose(file);
}

