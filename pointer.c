#include<stdio.h>
int main()
{
	int a[2]={10,20},i;
	int *p;//bothe are variabl; *p=20 & p++ both will work
	const int *q;//value is constant, pointer is not; *q=20 won't work but q++ wil work
	int * const r=&a[0];//pointer is constant, value is not; *r=20 will work but r++ won't work(ARRAY)
	const int * const w=&a[0];//both are constant, *w=20 & w++ both won't work
	p=&a[0];
	p++;
	*p=30;
	for(i=0;i<2;i++)
		printf("\n%d",a[i]);
	q=&a[0];
	q++;
	//*q=40;
	for(i=0;i<2;i++)
		printf("\n%d",a[i]);
	//r=&a[0];
	//r++;
	*r=50;
	for(i=0;i<2;i++)
		printf("\n%d",a[i]);
	//w++;
	//*w=80;
	for(i=0;i<2;i++)
		printf("\n%d",a[i]);
	return 0;
}
	