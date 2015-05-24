/* fwrite example : write buffer */
#include <stdio.h>

typedef struct _node {
    char name[7];
    int num;
}node;

int main()
{
    node self;
    strcpy(self.name, "zongzhi");
    self.num = 10;
    FILE * pFile;
    char buffer[] = { 'x' , 'y' , 'z' };
    pFile = fopen ("myfile.bin" , "wb");
    printf("buffer size %d\n", sizeof(buffer));
    fwrite(buffer, 2, sizeof(buffer), pFile);
    fwrite(&self, 1, sizeof(self), pFile);
    fclose(pFile);
    return 0;
}
