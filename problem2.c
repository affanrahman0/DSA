#include<stdio.h>
#include"link.h"
#include<stdlib.h>
void circular_traverse(node *);
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("%d\t",temp->data);
        temp=temp->next;

    }while(temp!=rear->next);
}
/*int main()
{
    node *rear=NULL;
    insertrear(&rear,12);
    insertrear(&rear,14);
    insertrear(&rear,16);
    insertrear(&rear,17);
    circular_traverse(rear);
    return 0;
        
} */
int main()
{
	FILE *fp;
    node *rear=NULL;
    int i;
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&i);
        if(!feof(fp))insertrear(&rear,i);
        
    }
    circular_traverse(rear);
    fclose(fp);
    return 0;
}  
