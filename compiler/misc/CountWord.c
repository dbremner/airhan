#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    int isWordChar(const char c)
	{
		if (c == '\t' ||
			c == '\n' ||
			c == ' ')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	};

	int wordCount(const char* file)
	{
		static int transTable[2][2] = {0, 1, 2, 1};
		int state = 0; // start state
		char c;
		int wordCount = 0;

		FILE* fstream = fopen(file, "rb");
		if (fstream == NULL)
		{
			printf("can't open file %s \n", file);
		}
	
		while ((c = (char)fgetc(fstream)) != EOF)
		{
			state = transTable[state][isWordChar(c)];

			if (state == 2) 
			{
				wordCount++;
				state = 0;
			}
		}

		if (state == 1) wordCount ++;

		return wordCount;
	}

#ifdef __cplusplus
}
#endif
