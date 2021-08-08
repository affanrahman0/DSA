#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
int main()
{
    queue que;
    init(&que,5);
    enqueue(&que,2);
    enqueue(&que,5);
    enqueue(&que,7);
    enqueue(&que,9);
    printf("%d",dequeue(&que));
   return 0; 
}