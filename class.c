#include<stdio.h>
#define MS 5
int main()
{
	int arr[MS],*ptr;
	int i;
	//ptr=&i;
	ptr=&arr[0];
	printf("\n sizeof array %d",sizeof(arr));
	printf("\n sizeof pointer %d",sizeof(ptr));
	for(i=0;i<MS;i++)
		scanf("%d",ptr+i);
	//*(arr+0)=2;
	//*(ptr+0)=2;
	for(i=0;i<MS;i++)
		printf("\n%d",*(ptr+i));
	
	return 0;
}