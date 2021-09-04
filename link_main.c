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
// node* last(node *head)
// {
//     node * temp;
//     while(head->next)
//     {
//         temp= head;
//         head = head -> next;
//     }
//     temp->next= NULL;
//     return head;
// }
void reorderList(node* head) {
    node *l1,*l2,*slow,*fast,*n;
	slow = head;
	fast = head -> next;
    while(fast!=NULL)
    {
		
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    l1=head;
    l2=slow->next;
    slow->next=NULL;
	printf("\n");
	traverse(l1);
	printf("\n");
	traverse(l2);
	reverse(&l2);
	
	n = newnode(0,NULL);
	while(l1!=NULL || l2!= NULL)
	{
		if(l1!=NULL) 
		{
			n->next = l1;
			n = n->next;
			l1= l1-> next;
		}
		if(l2!=NULL) 
		{
			n->next = l2;
			n = n->next;
			l2= l2-> next;
		}
	}
	//head = n;
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
	traverse(head);
	reorderList(head);
	printf("\n");
	traverse(head);
    // printf("\n");
    // after(15,&head,17);
    // //traverse(head);
	// before(1,&head,19);
	// before(2,&head,10);
	// printf("\n");
	// //traverse(head);
	// delcurrent(&head,19);
	// printf("\n");
	// //traverse(head);
	// delcurrent(&head,1);
	// printf("\n");
	// traverse(head);
	// printf("\n");
	// node *temp=serchbypos(head,3);
    // printf("%d",temp->data);
	// //traverse(head);
    return 0;
}