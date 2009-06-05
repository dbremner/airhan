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

namespace lianghancn
{
    namespace air
    {
        namespace compression
        {
            struct HuffmanNode
            {
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
            };

            struct HuffmanCode
            {
                unsigned char* codeBits;
                int codeLength;
            };

            class HuffmanEncoder
            {
            public:
                HuffmanEncoder(){};
                virtual ~HuffmanEncoder(){};

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