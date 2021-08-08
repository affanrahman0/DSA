#include"browser.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void circular_traverse(node *rear)
{
    node *temp=rear->next;
    do{
        printf("%s",temp->data.arr);
        temp=temp->next;

    }while(temp!=rear->next);
}
void print()
{
    printf("press f to show next recorded history\n");
    printf("press b to show previous recorded history\n");
    printf("Press E to Exit");
}
int main()
{
	FILE *fp;
    node *rear=NULL,*curr;
    item i;
    char ch;
	fp=fopen("c:\\Users\\rahma\\import.txt","r+");
    while(fgets(i.arr,sizeof(i.arr),fp)!=NULL)
    {
        insertrear_circular(&rear,i);
    }
    curr=rear->next;
    print();
    do
    {
        printf("Please enter a key accordind to your need\n");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'f':
                curr=curr->next;
                printf("%s",curr->data.arr);
                break;
            case 'b':
                curr=curr->prev;
                printf("%s",curr->data.arr);
                break;
            default :
                if(ch!='E')printf("Invalid input\n");
                break;

        }
    }while(ch!='E');


    //circular_traverse(rear);
    fclose(fp);
    return 0;
}    