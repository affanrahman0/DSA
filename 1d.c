#include<stdio.h>
void input(int[],int);
void output(int[],int);
int* add(int[],int[],int);
int main()
{
	int a[5],b[5],*c,i;
	input(a,5);
	input(b,5);
	c=add(a,b,5);
	output(c,5);
	return 0;
}
void input(int z[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&z[i]);
}
void output(int z[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",z[i]);
}
int* add(int x[],int y[],int n)
{
	static int c[5];
	int i;
	for(i=0;i<5;i++)
		c[i]=x[i]+y[i];
	return c;
}