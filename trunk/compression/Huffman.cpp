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

#include <iostream>

#include "Huffman.h"

using namespace lianghancn::air::compression;

HuffmanEncoder::HuffmanEncoder()
: _symbols(256)
, _nodes(NULL)
, _codes(NULL)
, _root(NULL)
{

}

HuffmanEncoder::HuffmanEncoder(int symbols)
: _symbols(symbols)
, _nodes(NULL)
, _codes(NULL)
, _root(NULL)
{

}

HuffmanEncoder::~HuffmanEncoder()
{
	FreeHuffmanTree(_root);

    for (int i = 0; i < _symbols; i ++)
    {
        if (_codes)
        {
            HuffmanCode* code = _codes[i];
            if (code)
            {
                delete code;
            }
        }
    }

    delete[] _codes;
    delete[] _nodes;
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

	if (_codes == NULL)
	{
		_codes = new HuffmanCode*[_symbols];

		for (int i = 0; i < _symbols; i ++)
		{
			_codes[i] = NULL;
		}
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
    int count = 0;

    for (int i = 0; i < _symbols; i ++)
    {
        if (_nodes[i] != NULL && _nodes[i]->count != 0)
        {
            nodeList.push_back(_nodes[i]);
            count ++;
        }
    }

	if (count == 0)
	{
		return false;
	}

    HuffmanNode* a = NULL;
    HuffmanNode* b = NULL;
    HuffmanNode* c = NULL;

	std::make_heap(nodeList.begin(), nodeList.end(), GreaterThanFrequency());

	while (nodeList.size() > 1)
    {   
	    std::pop_heap(nodeList.begin(), nodeList.end(), GreaterThanFrequency());
		a = nodeList.back();
		nodeList.pop_back();

        std::pop_heap(nodeList.begin(), nodeList.end(), GreaterThanFrequency());
		b = nodeList.back();
		nodeList.pop_back();

		
        c = new HuffmanNode(a, b);
        a->parent = c;
        b->parent = c;

		nodeList.push_back(c);
		std::push_heap(nodeList.begin(), nodeList.end(), GreaterThanFrequency());
		
    }

	_root = nodeList.front();
	
	BuildCodes(_root);

    return true;
}

void HuffmanEncoder::FreeHuffmanTree(HuffmanNode*& rNode)
{
	if (rNode == NULL)
	{
		return;
	}

	if (!rNode->leaf)
	{
		FreeHuffmanTree(rNode->left);
		FreeHuffmanTree(rNode->right);
	}
	
	delete rNode;
	rNode = NULL;
}

void HuffmanEncoder::ScanFrequency(const char *pName)
{
    FILE* file = fopen(pName, "rb");
    if (!file)
    {
        std::cout<<"can't open input file"<<std::endl;
        return;
    }

    HuffmanNode** nodes = new HuffmanNode*[_symbols];
    for (int i = 0; i < _symbols; i ++)
    {
        nodes[i] = NULL;
    }

    int c = 0;

    while ((c = fgetc(file)) != EOF)
    {
		value_type index = (value_type)c;

        if (nodes[index] == NULL)
        {
            nodes[index] = new HuffmanNode(index, 1);
        }

        nodes[index]->count ++;
    }

    _nodes = nodes;
    fclose(file);

#if 0
    for (int i = 0; i < _symbols; i ++)
    {
        if (_nodes[i])
        {
            std::cout<<_nodes[i]->count<<std::endl;
        }
    }
#endif
}

void HuffmanEncoder::EncodeFile(const char *pSource, const char *pDest)
{
    assert(pSource && pDest);
    FILE* input = fopen(pSource, "rb");
    if (input == NULL)
    {
        std::cout<<"can't open input file"<<std::endl;
        return;
    }

    FILE* output = fopen(pDest, "wb+");
    if (output == NULL)
    {
        std::cout<<"can't open output file"<<std::endl;
        return;
    }

    // get statistics and build huffman codes
    ScanFrequency(pSource);
    BuildHuffmanTree();

    value_type codeIndex = 0;
    value_type byte = 0;
    int bitCount = 0;
    int c;

    // encode and output
    while((c = fgetc(input)) != EOF)
    {
        codeIndex = (value_type)c;
        value_type* codeBits = _codes[codeIndex]->codeBits;
        int codeLength = _codes[codeIndex]->codeLength;

        for (int i = 0; i <codeLength; i ++)
        {
            byte |= GetBit(codeBits, i) << bitCount;
             
            if (++ bitCount == 8)
            {
                fputc(byte, output);
                byte = 0;
                bitCount = 0;
            }
        }
    }

#if 1
    for (int i = 0; i < _symbols; i ++)
    {
        if (_codes[i] != NULL)
        {
            std::cout<<_codes[i]->codeLength<<std::endl;
        }
    }
#endif

    if (bitCount > 0)
    {
        fputc(byte, output);
    }

    fclose(input);
    fclose(output);
}

void HuffmanEncoder::DecodeFile(const char* pSource, const char* pDest)
{
	assert(pSource && pDest);
	FILE* input = fopen(pSource, "rb");
	if (input == NULL)
	{
		std::cout<<"can't open input file"<<std::endl;
		return;
	}

	FILE* output = fopen(pDest, "wb+");
	if (output == NULL)
	{
		std::cout<<"can't open output file"<<std::endl;
		return;
	}

	// for now I don't serialize the code table so this table is generated previously by encoding process.. stupid but enough.
	// this encoder should not be used in deflate impl.. not canonical huffman tree (which, code length itself is suffice to represent a huffman tree)
	if (_codes == NULL || _root == NULL)
	{
		return;
	}

	HuffmanNode* current = _root;
	int c;
	
	while ((c = fgetc(input)) != EOF)
	{
		value_type byte = (value_type)c;
		value_type mask = 1;

		while (mask)
		{
			current = byte & mask ? current->right : current->left;
			mask <<= 1;

			if (current->leaf)
			{
				fputc(current->symbol, output);
				current = _root;
			}
		}
	}

	fclose(input);
	fclose(output);
}