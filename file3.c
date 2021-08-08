#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char ch;
	fp1=fopen("student.txt","r");
	fp2=fopen("studentcopy.txt","w");
	do{
		ch=fgetc(fp1);
		//putchar(ch);
		if(ch!=EOF) fputc(ch,fp2);
	}while(ch!=EOF);
	fclose(fp1);
	fclose(fp2);
	return 0;
}