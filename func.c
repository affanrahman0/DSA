/*Menu driven program*/
#include<stdio.h>
float add(float op1,float op2)
{
	return op1+op2;
}
float subtract(float op1,float op2)
{
	return op1-op2;
}
float multiply(float op1,float op2)
{
	return op1*op2;
}
float divide(float op1,float op2)
{
	return op1/op2;
}
int main()
{
	int ch;
	float op1,op2,res;
	float (*ptr[4])(float,float);
	ptr[0]=add;
	ptr[1]=subtract;
	ptr[2]=multiply;
	ptr[3]=divide;
	do{
		printf("\npress 1 to add\npress 2 to subtract\npress 3 to multiply\npress 4 to divide\npress 0 to quit\nEnter your choice");
		scanf("%d",&ch);
		if(ch>=1&&ch<=4)
		{
			printf("Enter the operands");
			scanf("%f%f",&op1,&op2);
			res=(*ptr[ch-1])(op1,op2);
			printf("The result is %f",res);
		}
		/*if(ch==1)
			res=op1+op2;
		else if(ch==2)
			res=op1-op2;
		else if(ch==3)
			res=op1*op2;
		else if(ch==4)
			res=op1/op2;
		else 
			printf("Invalid choice");*/
		/*switch(ch)
		{
			//default:printf("Invalid choice");
			case 1:res=op1+op2;
					printf("The result is %f",res);
					break;
			case 2:res=op1-op2;
					printf("The result is %f",res);
					break;
			case 3:res=op1*op2;
					printf("The result is %f",res);
					break;
			case 4:res=op1/op2;
					printf("The result is %f",res);
					break;
			default:printf("Invalid choice");
		}*/
	}
	while(ch!=0);
	return 0;
}