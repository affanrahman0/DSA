#include<stdio.h>
int main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (*q)[4];/*q is a pointer to an 1D integer array of size 4*/
	q=a;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",*(*(q+i)+j));
        }
        printf("\n");
    }
    return 0;
}