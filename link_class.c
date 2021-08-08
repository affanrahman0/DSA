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
    //char arr[50];
    node *head=NULL,*head2=NULL,*pos1,*pos2;
    int i,j,n=0,m=0,k,l;
	fp=fopen("c:\\Users\\rahma\\ll.txt","r+");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&i);
        append(i,&head);
        //begin(i,&head2);
        n++;
    }
    fp1=fopen("c:\\Users\\rahma\\ll2.txt","r+");
    while(!feof(fp1))
    {
        fscanf(fp1,"%d",&j);
        append(j,&head2);
        m++;
        //begin(i,&head2);
    }
    traverse(head);
    printf("\n");
    traverse(head2);
    printf("\n");
    // while(head2!=NULL)
    // {
    //     while(head!=NULL)
    //     {
    //         if(head->data==head2->data)
    //         {
    //             pos1=searchbypred(head->data,head);
    //             pos2=searchbypred(head2->data,head2);
    //             if(pos1!=NULL) delafter(pos1);
	//             else
    //             {
	// 	             delbeg(&head);
    //             }
    //             if(pos2!=NULL) delafter(pos2);
	//             else
    //             {
	// 	            delbeg(&head2);
    //             }
    //         }
    //         head=head->next;
    //     }
    //     head2=head2->next;
    // }
    traverse(head);
    printf("\n");
    traverse(head2);
    
    fclose(fp);
    fclose(fp1);
    return 0;
}    