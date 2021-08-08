#include<stdlib.h>
#include"record.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
tnode *newnode(item value)
{
    tnode *temp=(tnode*)malloc(sizeof(tnode));
    temp->data.id=value.id;
    temp->data.index=value.index;
    temp->left=NULL;
    temp->right=NULL;
    temp->bfact=0;
    return temp;
}
/*void print_preorder(tnode* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}*/
void print_inorder(tnode* root)
{
    if(root!=NULL)
    {
        print_inorder(root->left);
        printf("A%d %d\t",root->data.id,root->data.index);
        print_inorder(root->right);
    }
}
/*void print_postorder(tnode* root)
{
    if(root!=NULL)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d",root->data);
    }
}*/
int depth(tnode* root)
{
    if(root==NULL) return 0;
    else
    {
        int l=depth(root->left);
        int r=depth(root->right);
        return 1+((l>r)?l:r);
    }
}
void cal_bfact(tnode* root)
{
    if(root==NULL) return;
    root->bfact=depth(root->left)-depth(root->right);
}
void leftrotate(tnode **root)
{
    tnode* temp;
    if(*root==NULL) return;
    temp=(*root)->right->left;
    (*root)->right->left=*root;
    *root=(*root)->right;
    (*root)->left->right=temp;
    cal_bfact(*root);
    cal_bfact((*root)->left);
    
}
void rightrotate(tnode **root)
{
    tnode *temp;
    if(*root==NULL) return;
    temp=(*root)->left->right;
    (*root)->left->right=*root;
    *root=(*root)->left;
    (*root)->right->left=temp;
    cal_bfact(*root);
    cal_bfact((*root)->right);
}
void balance(tnode **root)
{
    if(*root==NULL) return;
    cal_bfact(*root);
    if((*root)->bfact>1)
    {
        if((*root)->left->bfact<0)  leftrotate(&(*root)->left);
        
        rightrotate(root);
        //cal_bfact(*root);
        
    }
    else if((*root)->bfact<-1)
    {
        if((*root)->right->bfact>0) rightrotate(&(*root)->right);
        leftrotate(root);
        //cal_bfact(*root);
        
    }
    else return;
}
void insert(tnode **root,item value)
{
    if(*root==NULL) *root=newnode(value);
    
    else
    {
        if(value.id<(*root)->data.id) insert(&((*root)->left),value);
        else if(value.id>(*root)->data.id) insert(&((*root)->right),value);
        balance(root);
    }
    //printf("%d ",(*root)->data);
    
}
void delnode(tnode **root,int value)
{
    if(*root==NULL) return;
    if(value<(*root)->data.id) delnode(&((*root)->left),value);
    else if(value>(*root)->data.id) delnode(&((*root)->right),value);
    else
    {
        tnode *temp=*root;
        if((*root)->left==NULL && (*root)->right==NULL)
        {
            *root=NULL;
            free(temp);
        }
        else if((*root)->left==NULL && (*root)->right!=NULL)
        {
            *root=(*root)->right;
            free(temp);
        }
        else if((*root)->left!=NULL && (*root)->right==NULL)
        {
            *root=(*root)->left;
            free(temp);
        }
        else{
            temp=(*root)->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            (*root)->data=temp->data;
            delnode(&((*root)->right),temp->data.id);
        }
    }
    if(*root==NULL) return;
    balance(root);
}
tnode *search(tnode *root,int value)
{
    if(root==NULL) return NULL;
    else{
        if(root->data.id==value) return root;
        else if(value<root->data.id) return search(root->left,value);
        else return search(root->right,value);
    }
}
void search_record(FILE* fp2,FILE* fp1)
{
    // rewind(fp1);
    // rewind(fp2);
    fp1=fopen("c:\\Users\\rahma\\DB.txt","r+");
	fp2=fopen("c:\\Users\\rahma\\IND.txt","r+");
    char arr[100],*ptr;
    int j;
    item i;
    tnode* root=NULL;
    while(fgets(arr,sizeof(arr),fp2)!=NULL)
    {
        //puts(arr);
        ptr=strtok(arr," ");
		while(ptr!=NULL){
			sscanf(ptr,"%d",&i.id);
			ptr=strtok(NULL," ");
            sscanf(ptr,"%d",&i.index);
            ptr=strtok(NULL," ");
            insert(&root,i);
        }
    }
    printf("Please enter the id of the stident\n");
    scanf("%d",&j);
    tnode* temp=search(root,j);
    //printf("%d %d\n",temp->data.id,temp->data.index);
    fseek(fp1,(long)temp->data.index,0);
    fgets(arr,sizeof(arr),fp1);
    puts(arr);
    fclose(fp1);
    fclose(fp2);     

}
void update_file(FILE* fp2,FILE *fp1)
{
    char arr[100], ptr[100],tmp[100];
    // node *head=NULL,*l1=NULL,*l2=NULL;
    tnode* root=NULL;
    item i;
    i.index=0;
	fp1=fopen("c:\\Users\\rahma\\DB.txt","r+");
	FILE* fp3=fopen("c:\\Users\\rahma\\replica2.txt","w+");
    while(fgets(arr,sizeof(arr),fp1)!=NULL)
    {
        sscanf(arr,"%s%s%d",ptr,tmp,&i.id);
        //insert(&root,i);
        fprintf(fp3,"%d %d ",i.id,i.index);
        i.index=ftell(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove("c:\\Users\\rahma\\IND.txt");
    rename("c:\\Users\\rahma\\replica2.txt","c:\\Users\\rahma\\IND.txt");
}
void print(FILE* fp1)
{
    fp1=fopen("c:\\Users\\rahma\\DB.txt","r");
    char arr[100];
    while(fgets(arr,sizeof(arr),fp1)!=NULL)
    {
        puts(arr);
    }
    fclose(fp1);
}
void delete_record(FILE* fp2,FILE* fp1,tnode** root)
{
    char arr[100];
    fp1=fopen("c:\\Users\\rahma\\DB.txt","r");
	FILE* fp3=fopen("c:\\Users\\rahma\\replica.txt","w");
    int n,c=0;
    print(fp1);
    printf("Please enter the line number to be deleted\n");
    scanf("%d",&n);
    while(fgets(arr,sizeof(arr),fp1)!=NULL)
    {
        c++;
        if(c!=n) fputs(arr,fp3);
    }
    fclose(fp1);
    fclose(fp3);
    remove("c:\\Users\\rahma\\DB.txt");
    rename("c:\\Users\\rahma\\replica.txt","c:\\Users\\rahma\\DB.txt");
    update_file(fp2,fp1);
}
void insert_record(FILE* fp2,FILE* fp1,tnode** root)
{
    fp1=fopen("c:\\Users\\rahma\\DB.txt","a");
	fp2=fopen("c:\\Users\\rahma\\IND.txt","a");
    char a[100],b[100],c[100],d[100];
    int m,y;
    item k;
    fprintf(fp1,"\n");
    int n=ftell(fp1);
    printf("Please enter name,id,DOB,stream,year of admission respectively\n");
    scanf("%s%s%d%s%s%d",a,b,&m,c,d,&y);
    fprintf(fp2," %d %d",m,n);
    k.id=m;
    k.index=n;
    insert(root,k);
    fprintf(fp1,"%s %s %d %s %s %d",a,b,m,c,d,y);
    fclose(fp1);
    fclose(fp2);
}
void record(FILE* fp1,FILE* fp2,tnode** root)
{ 
    printf("Please enter s to search\n");
    printf("Please enter i to insert a new record\n");
    printf("Please enter d to delete an existing record\n");
   char ch;
    do{
            
        printf("\nEnter your choice\n");
        scanf(" %c",&ch);
        switch(ch)
        {
            case 's': search_record(fp2,fp1);
            break;
            case 'i': insert_record(fp2,fp1,root);
            break;
            case 'd': delete_record(fp2,fp1,root);
            break;
            default: if(ch!='E') printf("Invalid input\n");
            break;       

        }
    }while(ch!='E') ;          
}