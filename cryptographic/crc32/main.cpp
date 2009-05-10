#include <stdio.h>

#include "ChecksumCRC32.h"
using namespace lianghancn::air::crypto::crc32;

int main()
{	
	ChecksumCRC32 oCRC;
	(oCRC);

	FILE* pFile = fopen("CRC.pdf", "rb");
	if (pFile)
	{
		unsigned char buffer[4096];

		size_t bytes = 0;
		while (bytes = fread(buffer, 1, 4096, pFile))
		{
			oCRC.update(buffer, 0, bytes);
		}
	}

	// should be 4fc9b0a2
	printf("%0x",oCRC.getChecksum());
}