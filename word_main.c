#include"word.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("%s %d\t",temp->data.arr,temp->data.freq);
        temp=temp->next;

    }while(temp!=rear->next);
}
int main()
{
	FILE *fp;
    node *rear=NULL;
    item i;
	fp=fopen("c:\\Users\\rahma\\word.txt","r+");
    while(!feof(fp))
    {
        fscanf(fp,"%s",i.arr);
        insert_lexico(&rear,i);
    }
    circular_traverse(rear);
    fclose(fp);
    return 0;
}    