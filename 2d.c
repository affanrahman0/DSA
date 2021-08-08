#include<stdio.h>
#define Row 50
#define Col 50
void input(int[][Col],int,int);
void output(int[][Col],int,int);
int (*add(int[][Col],int[][Col],int,int))[Col];
int main()
{
	int mat1[Row][Col],mat2[Row][Col],(*mat3)[Col],m1,n1,m2,n2;
	printf("\nEnter the number of Rows and Columns of first matrix\n");
	scanf("%d%d",&m1,&n1);
	printf("\nEnter the number of Rows and Columns of second matrix\n");
	scanf("%d%d",&m2,&n2);
	if(m1==m2 && n1==n2)
	{
		printf("\nEnter the elemnets of first matrix\n");
		input(mat1,m1,n1);
		printf("\nEnter the elemnets of second matrix\n");
		input(mat2,m2,n2);
		printf("\nEnter the elemnets of first matrix\n");
		mat3=add(mat1,mat2,m1,n1);
		printf("\nThe result is\n");
		output(mat3,m1,n1);
	}
	else printf("Addition is not possible");
	return 0;
}
int (*add(int mat1[][Col],int mat2[][Col],int r,int c))[Col]
{
	int i,j;
	static int mat3[Row][Col];
	//static int* mat3[Row];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			mat3[i][j]=mat1[i][j]+mat2[i][j];
	}
	return mat3;
}
void input(int m[][Col],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&m[i][j]);
	}
}
void output(int m[][Col],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}
}
	
	