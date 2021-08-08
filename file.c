#include<stdio.h>
int main()
{
	FILE *fp;
	unsigned long int p=98305124;
	fp=fopen("D:\\C\\file_write.txt","w");
	fputs("Affan Rahman",fp);
	fprintf(fp,"%lu",p);
	fclose(fp);
	return 0;
}
	
	