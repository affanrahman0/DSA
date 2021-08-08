#include<stdio.h>
#include"sll.h"
void traverse(node *head);
int main()
{
	node *head=NULL,*pos;
	/*head=append(head,12);
	head=append(head,17);
	head=append(head,10);
	head=append(head,21);*/
	
	append(&head,12);
	append(&head,17);
	append(&head,10);
	append(&head,21);
	addbeg(&head,19);
	printf("\n");
	traverse(head);
	pos=searchbykey(head,17);
	if(pos!=NULL)
		addafter(pos,15);
	printf("\n");
	traverse(head);
	return 0;
}
void traverse(node *head)
{
	while(head!=NULL)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
}
	
	