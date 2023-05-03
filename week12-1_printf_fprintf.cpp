
#include<stdio.h>
int main()

{
    FILE*fout = fopen("file.txt", "w");
    printf("Hello World\n");
    fprintf(fout, "Hello World¦bÀÉ®×¸Ì");
}
