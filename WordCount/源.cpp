#include "stdio.h"
#include "string.h"
char s[50];
int main(int argc, char* argv[])
{
	int a = 1;
	FILE* fp=NULL;
	errno_t err = fopen_s(&fp, argv[2], "r+");
	a = fgetc(fp);
	rewind(fp);
	for (int i = 0; i < 50; i++)
	{
		fscanf_s(fp, "%c", &s[i]);
	}
	fclose(fp);
	if (strcmp(argv[1], "-c") == 0)
	{
		int bytenum = strlen(s) - 1;
		printf("×Ö·ûÊý:%d\n", bytenum);
	}
	else if (strcmp(argv[1], "-w") == 0)
	{
		int wordnum = 0;
		int i = 0;
		for (i=1;i<50;i++)
		{
			if ((s[i] == ' ' || s[i] == ',') && (s[i-1] != ' ' || s[i-1] != ',')) 
			{
				wordnum++;
			}
		}
		printf("µ¥´ÊÊý:%d\n", wordnum);
	}
	getchar();
	return 0;
}