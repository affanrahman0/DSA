#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char ch[512];
	fp1=fopen("source.png","rb");
	fp2=fopen("dest.png","wb");
	do{
		fread(ch,sizeof(char),512,fp1);
		if(!feof(fp1)) fwrite(ch,sizeof(char),512,fp2);
	}while(!feof(fp1));
	fclose(fp1);
	fclose(fp2);
	return 0;
}
