#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **ptp,r,c,i,j,*dummy;
	printf("\nEnter the row and column of the matrix\n");
	scanf("%d%d",&r,&c);
	ptp=(int**)malloc(r*sizeof(int*));
	/*1st approach*/
	/*for(i=0;i<r;i++)
		ptp[i]=(int*)malloc(c*sizeof(int));*/
	/*2nd approach*/
	/*dummy=(int*)malloc(r*c*sizeof(int));
	for(i=0;i<r;i++)
		ptp=dummy+c*i;*/
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&ptp[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",ptp[i][j]);
        }
        printf("\n");
    }
    return 0;
}