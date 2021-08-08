#include<stdio.h>
int main()
{
	FILE *fp;
	char name[30];
	int i;
	float f;
	printf("Enter the file name");
	fgets(name,sizeof(name),stdin);
	fp=fopen(name,"r");
	fgets(name,sizeof(name),fp);
	puts(name);
	
	fgets(name,sizeof(name),fp);
	//puts(name);
	sscanf(name,"%d",&i);
	printf("%d",i);
	
	fgets(name,sizeof(name),fp);
	puts(name);
	
	fgets(name,sizeof(name),fp);
	sscanf(name,"%d",&i);
	printf("%d",i);

	//fgets(name,sizeof(name),fp);
	//puts(name);


	fclose(fp);
	return 0;
}
	
	