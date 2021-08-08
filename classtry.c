#include<stdio.h>
#include"link.h"
#include<stdlib.h>
void traverse(node *head)
{
    while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}

}
int main()
{
	FILE *fp,*fp1;
    node *head=NULL,*head2=NULL;
    int i,j,c=0;
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&i);
        append(i,&head);
        
    }
    fp1=fopen("c:\\Users\\rahma\\ll2.txt","r+");
     while(!feof(fp1))
    {
        fscanf(fp1,"%d",&j);
        append(j,&head2);
    }
    // traverse(head);
    // printf("\n");
    // traverse(head2);
    // printf("\n");
    
    node *curr=head,*curr2=head2,*prev2=NULL;
    while(curr2!=NULL)
    {
        node *prev=searchbypred(curr2->data,head);
        if(prev!=NULL)
        {
            delafter(prev);
            if(prev2!=NULL) delafter(prev2);
            else delbeg(&head2);
        } 
        else
        {
            if(head->data==curr2->data) 
            {
                delbeg(&head);
                if(prev2!=NULL) delafter(prev2);
                else delbeg(&head2); 
            }
        }
        prev2=curr2;
        curr2=curr2->next;
    }
    traverse(head);
     printf("\n");
     traverse(head2);
    // printf("\n");
    // printf("%d",c);
    fclose(fp);
    fclose(fp1);
    return 0;
}    