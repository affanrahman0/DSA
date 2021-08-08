#include<stdlib.h>
#define item struct V
struct V{
    int no;
    char  name[10];
    char sur[10];
};
typedef struct q
{
    item *arr;
    int rear,size;
}queue;
void init(queue *,int );
int isempty(queue *);
int isfull(queue *);
void swap(item *,item *);
void enqueue(queue *,item);
item dequeue(queue *);
void heapify(int [],int );
void heap_sort(int [],int );
void hospital(queue *);