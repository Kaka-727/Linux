#include<stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp1 = fopen(argv[1], "r");  //以只读方式打开文件1
    FILE *fp2 = fopen(argv[2], "r");  //以只读方式打开文件2
    FILE *fp3 = fopen(argv[3], "w");  //以只写方式打开文件3，文件不存在则自动建立
    int read_ret;
    if(argc < 4) //需输入两个需要合并的文件名和一个合并后的文件名
    {
        printf("please input 3 file!\n");
    }
    if(fp1 == NULL)  //文件1打开不成功
    {
        printf("open source %s failed!\n", argv[1]);
        return -1;
    }
    while(1)  //成功打开1
    {
        read_ret = fgetc(fp1);  //单个字符读写
        if(feof(fp1))  //fp1已经指向文件末尾，结束循环
        {
            break;
        }
        fputc(read_ret,fp3);  //把单个字符输出到文件3
    }
    fopen(argv[3], "a");  //以附加方式打开文件3
    if(fp2 == NULL)  //文件2打开不成功
    {
        printf("open source %s failed!\n", argv[2]);
        return -1;
    }
    while(1)  //成功打开2
    {
        read_ret = fgetc(fp2);  //单个字符读写
        if(feof(fp2))  
        {
            break;
        }
        fputc(read_ret,fp3);  //把单个字符输出到文件3
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);  //关闭文件
    return 0;
}

