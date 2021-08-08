#include<stdio.h>
void bubble(int[],int,int (*)(int,int));
int compareincr(int,int);
int comparedecr(int,int);
void swap(int*,int*);
int main()
{
	int a[100],n,i;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble(a,n,compareincr);
	printf("\nThe sorted array in increasing order is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	bubble(a,n,comparedecr);
	printf("\nThe sorted array in decreasing order is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
void swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
int compareincr(int a,int b)
{
	return a>b;
}
int comparedecr(int a,int b)
{
	return a<b;
}
void bubble(int a[],int n,int (*ptf)(int,int))
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if((*ptf)(a[j],a[j+1]))
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
