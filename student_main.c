#include"student.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void print()
{
    printf("press a to add a new student in his/her proper place.\n");
    printf("press b to delete an existing record\n");
    printf("press c to update an existing record\n");
    printf("press d to search a record name-wise as well as enrollment-wise\n");
    printf("press e to display the name in dictionary order\n");
    printf("Press f to print the list\n");
    printf("Press E to Exit\n");
}
int main()
{
	FILE *fp;
    node *rear=NULL,*curr;
    item i;
    char str[100];
    print();
	fp=fopen("c:\\Users\\rahma\\import.txt","r+");
    while(fgets(str,sizeof(str),fp)!=NULL)
    {
        sscanf(str,"%s%lld%lld%d",&i.name,&i.roll,&i.reg,&i.year);
        insertrear_circular(&rear,i);
    }
    //circular_traverse(rear);
    student(&rear);
    
    fclose(fp);
    return 0;
}    