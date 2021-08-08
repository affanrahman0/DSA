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
    traverse(head);
    printf("\n");
    traverse(head2);
    printf("\n");
    
    node *curr=head,*curr2=head2;
    while(curr2!=NULL)
    {
        while(curr!=NULL)
        {
            if(curr->data==curr2->data)
            {
                 delcurrent(&head,curr->data);
                delcurrent(&head2,curr2->data);
                //c++;
                //printf("%d",c);
                break;

            }
            curr=curr->next;
           // printf("%d",c);
        }
        curr=head;
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