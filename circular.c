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
int joseph(node **head,int n)
{
    node *temp=*head;
    while(temp->next!=temp)
    {
        node *local=serchbypos(temp,n-1);
        delafter(local);
        temp=local->next;
    }
    *head=temp;
    return (temp->data);
    
}

int main()
{
	FILE *fp;
    node *rear=NULL;
    int i,c=0,n;
    printf("Enter the no. to be deleted\n");
    scanf("%d",&n);
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&i);
        if(!feof(fp))insertrear(&rear,i);
        
        
    }
    //circular_traverse(rear);
   node *head=rear->next;
   printf("%d",joseph(&head,n));
   // circular_traverse(rear);
    fclose(fp);
    return 0;
}  
