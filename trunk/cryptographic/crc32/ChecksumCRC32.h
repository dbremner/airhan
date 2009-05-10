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

//
// A CRC32 Calculator implementation based on slicing by 4 and slicing by eight algorithm described by Intel http://www.intel.com/technology/comms/perfnet/download/CRC_generators.pdf
// CRC table generation fun is modified from zlib reference impl by Mr. Mark. Adler
//

#ifndef __AIR_HAN_CHECKSUMCRC32_H__
#define __AIR_HAN_CHECKSUMCRC32_H__

#include <stdio.h> // for crc table print

namespace lianghancn
{
    namespace air
    {
        namespace crypto
        {
            namespace crc32
            {
                class ChecksumCRC32
                {
                public:

					explicit ChecksumCRC32();

					virtual ~ChecksumCRC32();

                    unsigned long getChecksum() const;

                    void reset();

                    void update(unsigned char byteVal);

                    void update(unsigned char* pBuffer, unsigned int nOffset, unsigned int nLength );

                    void printTable(char* pFileName);

                private:

                    void crcGenerateTable();

                    void write_table(FILE* out, const unsigned long* table);

                private:

                    unsigned int _nCRC32;

                private:
                    ChecksumCRC32(const ChecksumCRC32&);
                    ChecksumCRC32& operator=(const ChecksumCRC32&);
                };
            };
        };
    };
};

#endif
