#include<stdio.h>
#include<stdlib.h>
#define item int
#define bucket 7
typedef struct v{
    int value;
    struct v* next;
}node;
typedef struct a{
    node* head;
}list;
typedef struct g{
    list* arr;
}hash;
node *newnode(item value)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->value=value;
    temp->next=NULL;
    return temp;
}
hash *create()
{
    hash* temp=(hash*)malloc(sizeof(hash));
    temp->arr=(list*)malloc(bucket*sizeof(list));
    for(int i=0;i< bucket;i++) temp->arr[i].head=NULL;
    return temp;
}
int hashfunction(int key)
{
    return (key % bucket);
}
void insert(int key,hash *h)
{
    node* temp=newnode(key);
    if(h->arr[hashfunction(key)].head==NULL)
    {
        h->arr[hashfunction(key)].head=temp;
    }
    else
    {
        node* n=h->arr[hashfunction(key)].head;
        while(n->next!=NULL)
        {
            n=n->next;
        }
        n->next=temp;
    }
}
void print(hash* h)
{
    for (int i = 0; i < bucket; ++i)
    {
        printf("[%d]",i);
        node* temp = h->arr[i].head;
        while(temp)
        {
            printf("->%d",temp->value);
            temp=temp->next;
        }
        printf("->NULL\n");
    }    
}
int main()
{
    hash* h=create();
    insert(7,h);
    insert(0,h);
    insert(3,h);
    insert(10,h);
    insert(4,h);
    insert(5,h);
    print(h);
    return 0;
}