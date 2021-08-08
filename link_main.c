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
    node *head=NULL;
	append(12,&head);
	 append(17,&head);
	 append(10,&head);
	append(21,&head);
	begin(19,&head);
    printf("\n");
	//traverse(head);
    printf("\n");
    after(15,&head,17);
    //traverse(head);
	before(1,&head,19);
	before(2,&head,10);
	printf("\n");
	//traverse(head);
	delcurrent(&head,19);
	printf("\n");
	//traverse(head);
	delcurrent(&head,1);
	printf("\n");
	traverse(head);
	printf("\n");
	node *temp=serchbypos(head,3);
    printf("%d",temp->data);
	//traverse(head);
    return 0;
}