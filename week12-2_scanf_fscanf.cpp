#include<stdio.h>
int main()
{
    FILE*fin = fopen("file.txt", "r");

    char line[100];
    fscanf(fin, "%s",line);
    printf("file.txtŪ��F:%s\n",line);

    fscanf(fin, "%s",line);
    printf("file.txtŪ��F:%s\n",line);
}
