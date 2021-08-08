#include"double_link.h"
#include<stdlib.h>
#include<stdio.h>
#define item int
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
    node *head=NULL, *rear=NULL;
    addrear(&head,&rear,12);
    addrear(&head,&rear,13);
    addrear(&head,&rear,14);
    addrear(&head,&rear,15);
    traverse(head);
    printf("\n");
    addfront(&head,&rear,6);
    traverse(head);
    delfront(&rear,&head);
    printf("\n");
    traverse(head);
    delrear(&rear,&head);
    printf("\n");
    traverse(head);
    return 0;
}