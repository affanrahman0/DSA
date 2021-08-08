#include<stdio.h>
int main()
{
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int b[2]={10,20},i=100,j=200,k=300;
	/*pointer to an array*/
	int (*q)[4];/*q is a pointer to an 1D integer array of size 4*/
	int *p[4];/*array of integer pointers*/
	q=&a[0];/* or q=a;*/
	//p=a[0];
	p[0]=&i;
	p[1]=&j;
	p[2]=&k;
	p[3]=b;
	printf("\n%d",*p[3]);
	/*printf("\n%d",**q);*/
	p[3]++;
	q++;
	printf("\n%d",*p[3]);
	/*printf("\n%d",**q);*/
	return 0;
}