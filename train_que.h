#include<stdlib.h>
#include<string.h>
#define item2 char*
typedef struct q
{
    item2 *arr;
    int front,rear,size;
}queue;
void init(queue *,int );
int isempty(queue *);
int isfull(queue *);
void enqueue(queue *,item2);
item2 dequeue(queue *);