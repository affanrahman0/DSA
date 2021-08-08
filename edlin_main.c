#include"edlin.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
    node *rear=NULL,*curr;
    item i;
    i.no=1;
    char str[100];
	fp=fopen("c:\\Users\\rahma\\import.txt","r+");
    while(fgets(str,sizeof(str),fp)!=NULL)
    {
        str[strlen(str)-1]='\0';
        strcpy(i.name,str);
       // push(&undo,str);
        insertrear_circular(&rear,i);
        i.no+=1;
    }
    edlin(&rear,i.no);
    fclose(fp);
    return 0;
}    