#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"p_doc.h"
int main()
{
	FILE *fp;
    char str[100],*ptr;
    item i,j,k,l;
    queue que;
    init(&que,10);
	fp=fopen("c:\\Users\\rahma\\import.txt","r+");
    while(fgets(str,sizeof(str),fp)!=NULL)
    {
        str[strlen(str)-1]='\0';
        ptr=strtok(str," ");
		while(ptr!=NULL){
			sscanf(ptr,"%s",i.name);
			ptr=strtok(NULL," ");
			sscanf(ptr,"%s",i.sur);
			ptr=strtok(NULL," ");
            sscanf(ptr,"%d",&i.no);
			ptr=strtok(NULL," ");
            enqueue(&que,i);
		}
    }
    hospital(&que);
    fclose(fp);
    return 0;
}    