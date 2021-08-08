#include<stdio.h>
#include<stdlib.h>
struct bag
{
    int a;
    char x[20];
    float b;
};
int main()
{
    struct bag *ptr;
    ptr=(struct bag*)malloc(sizeof(struct bag));
    scanf("%d%s%f",&ptr->a,ptr->x,&ptr->b);
    printf("%d%s%f",ptr->a,ptr->x,ptr->b);

}