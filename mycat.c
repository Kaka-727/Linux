#include <stdio.h>
void file_copy(FILE * file1,FILE * file2)
{
	int c;
	while((c = getc(file1)) != EOF)
	{
		putc(c,file2);
	}
}
int main(int argc,char *argv[])
{
	FILE * fp;      //声明一个文件指针
	if(argc == 1)
		file_copy(stdin,stdout);
	else
		while(-- argc > 0)
		{
			if((fp = fopen(*++argv,"r")) == NULL)
			{
				printf("no such file %s",*argv);
				return 1;
			}
			else
			{
				file_copy(fp,stdout);
				fclose(fp);    //关闭文件
			}
		}
	return 0;
}

