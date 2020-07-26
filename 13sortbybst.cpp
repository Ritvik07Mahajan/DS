//sort a list of nembers using binary search tree
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;

};


struct node *createnode()
{
    struct node *n;
        n=(node *)malloc(sizeof(struct node));
    return (n);

}
void insertbt(struct node **tree,int element)
{

if(*tree==NULL)
{
*tree=createnode();
(*tree)->info=element;
(*tree)->left=(*tree)->right=NULL;
    }

    else{
        if (element<(*tree)->info)
        insertbt(&((*tree)->left),element);
        else if(element>=(*tree)->info)
           insertbt(&((*tree))->right,element);
    }
}

void inorder(struct node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d ",t->info);
        inorder(t->right);
    }


}
int main()
{
    int num,ch;
    struct node *root=NULL;
    while(1)
    {
        printf("enter 1 to insert element in the list\n");
        printf("enter 2 for display\n");
        printf("enter 3 to exit\n\n");
        printf("enter your choice\n");
        scanf("%d",&ch);

       switch(ch)
    {
        case 1:printf("enter a number to insert in the tree\n");
        scanf("%d",&num);
        insertbt(&root,num);
        break;
        case 2:

                       inorder(root);
                       printf("\n");
        break;
        case 3:exit(0);
        break;
        case 4:printf("invalid choice\n");
    }
}
return 0;
}
