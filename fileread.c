#include<stdio.h>
#include<string.h>
void read(FILE *fptr)
{
	char tmp[100],*ptr;
	int i;
	while(fgets(tmp,sizeof(tmp),fptr)!=NULL)
	{
		//fgets(tmp,sizeof(tmp),fptr);
		//perror("fgets");
		//puts(tmp);
		ptr=strtok(tmp," ");
		while(ptr!=NULL){
			sscanf(ptr,"%d",&i);
			printf("a%d",i);
			ptr=strtok(NULL," ");
			sscanf(ptr,"%d",&i);
			ptr=strtok(NULL," ");
			printf("b%d",i);
			printf("\n");

		}
		printf("\n");
	}
}
int main()
{
	FILE *fptr=fopen("c:\\Users\\rahma\\ll.txt","r");
	//perror("open");
	read(fptr);
	fclose(fptr);
	return 0;
}