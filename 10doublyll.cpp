// Implementation of doubly linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{

    int info;
    struct node *prev;
    struct node *next;
};

struct node *start=NULL;
struct node *createnode()
{
    struct node *temp;
    temp=(node*)malloc(sizeof(struct node));
    return temp;

}
void createlist()
{ int n;int i;
    struct node* temp,*t;
    printf("enter the no of elements you want to insert in the list \n");
    scanf("%d",&n);
    printf("now enter elements to insert in the list\n");
    for(i=0;i<n;i++)
    {
    temp=createnode();
    scanf("%d",&temp->info);
temp->next=NULL;
if(start==NULL)
start=temp;
       else
      {
          t=start;
while(t->next!=NULL)
{
    t=t->next;
}
    t->next=temp;
    temp->prev=t;
    }
    }
    printf("list created\n");

}
void insertatbeg()
{
   struct node *n;
   n=createnode();
   printf("enter the number to insert\n");
   scanf("%d",&n->info);
   n->prev=NULL;
   n->next=NULL;
   if(start==NULL)
        start=n;
   else{
        start->prev=n;
   n->next=start;
   start=n;

   }

}
void insertatend()
{
    struct node *n,*t;
    n=createnode();
    printf("enter the number to insert a t end");
    scanf("%d",&n->info);

    n->prev=NULL;
   n->next=NULL;
   if(start==NULL)
        start=n;
   else{

       t=start;
   while(t->next!=NULL)
          t=t->next;

   t->next=n;
   n->prev=t;

   }
}
void insertbefore()
{
    int n;
    struct node *t,*temp;
    temp->next=NULL;
    temp->prev=NULL;

    printf("enter the number you want to insert\n");
    scanf("%d",&temp->info);
    printf("enter the number before which you want to insert\n");
    scanf("%d",&n);
    if(start==NULL)
        printf("list is empty");
    else{
            t=start;
    while(t->next->info!=n)
        t=t->next;

        temp->next=t->next;
        t->next->prev=temp;
        t->next=temp;
        temp->prev=t;


    }
}
void insertafter()
{

int n;
    struct node *t,*temp;
    temp->next=NULL;
    temp->prev=NULL;

    printf("enter the number you want to insert\n");
    scanf("%d",&temp->info);
    printf("enter the number after which you want to insert\n");
    scanf("%d",&n);
    if(start==NULL)
        printf("list is empty");
    else{
            t=start;
            while(t->info!=n)
                t=t->next;
            temp->next=t->next;
        t->next->prev=temp;
        t->next=temp;
        temp->prev=t;


    }
}
void insertatmid()
{ int ch;

    printf("enter 1 to insert before the element\n");
    printf("enter 2 to insert after the element\n");
printf("now enter tour choice\n");
scanf("%d",&ch);
switch(ch)
{
    case 1:insertbefore();
    break;
    case 2:insertafter();
    break;

}


}

void insertnode()
{ int ch;
if(start==NULL)
    {
        printf("first create the list and then insert\n\n");
        return;

    }
    printf("enter 1 to inset at begining \n");
    printf("enter 2 to insert at end\n");
    printf("enter 3 to insert at middle\n\n");
    printf("enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insertatbeg();
        break;
        case 2:insertatend();
        break;
        case 3:insertatmid();
        break;

    }

    printf("element inserted\n\n");

}
void deletenode()
{
int n;
struct node *t;
printf("enter the element you want to delete\n");
scanf("%d",&n);
if(start==NULL)
        printf("list is empty\n");
        else{
            t=start;
            if(t->info==n)
            {
                start=t->next;
                start->prev=NULL;
                free(t);
            }
            else{
            while(t->info!=n)
                t=t->next;

                if(t->next==NULL)
                {
                    t->prev->next=NULL;
                    free(t);
                }

           else {t->prev->next=t->next;
            t->next->prev=t->prev;
            free(t);
           }
        }
    }
    printf("%d is deleted\n\n",n);
}
void display()
{

    struct node *t;

    if(start==NULL)
        printf("list is empty\n");
    else{
        t=start;
        while(t!=NULL)
        {

            printf("%d ",t->info);
            t=t->next;
        }
        printf("\n");
    }
}
int main()
{ int ch;
    while(1)
    {
printf("enter 1 to create list\n");
printf("enter 2 to insert\n");
printf("enter 3 to delete\n");
printf("enter 4 for display\n");
printf("enter 5 for exit\n\n");
printf("now enter your choice\n");
scanf("%d",&ch);
switch(ch)
{  case 1:createlist();
      break;
    case 2:insertnode();
    break;
    case 3:deletenode();
    break;
    case 4:display();
    break;
    case 5:exit(0);

}
}
}
