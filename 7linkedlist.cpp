// Implementation of linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;

};
struct node *Start=NULL;
struct node *createnode()
{
    struct node *n;
        n=(node *)malloc(sizeof(struct node));
    return (n);

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
temp->link=NULL;
if(Start==NULL)
Start=temp;
       else
      {
          t=Start;
while(t->link!=NULL)
{
    t=t->link;
}
    t->link=temp;
    }
    }
    printf("list created\n");

}
void insertatbeg()
{

    struct node *temp;
    temp=createnode();
printf("enter a number to insert \n");
    scanf("%d",&temp->info);
    temp->link=Start;
    Start=temp;
    printf("element inserted\n");
}

void insertatend()
{
    struct node* temp,*t;
temp=createnode();

printf("enter a number to insert in the linked list\n");
scanf("%d",&temp->info);
temp->link=NULL;
t=Start;
while(t->link!=NULL)
{
    t=t->link;
}
    t->link=temp;

printf("element inserted\n");
}

void insertafter()
{
    int x;
    struct node *temp,*r,*s;
    s=Start;
    r=NULL;
    temp=createnode();
    printf("enter a number to insert \n");
    scanf("%d",&temp->info);
    printf("enter the element after which you want to insert\n ");
    scanf("%d",&x);
    r=s;
    s=s->link;
    while(r->info!=x)
    {

        if(r->link==NULL)
        {

            printf("%d is not in the list\n",x);
            return;
}
        r=s;
        s=s->link;
        }
    r->link=temp;
    temp->link=s;
    printf("element inserted\n");
}
void insertbefore()
{
    int x;
    struct node *temp,*r,*s;

    s=Start;
    r=NULL;
    temp=createnode();
    printf("enter a number to insert \n");
    scanf("%d",&temp->info);
    printf("enter the element before which you want to insert\n ");
    scanf("%d",&x);
    while(s->info!=x)
    {

        if(s->link==NULL)
        {

            printf("%d is not in the list\n",&x);
        }
        r=s;
        s=s->link;
    }
    r->link=temp;
    temp->link=s;
    printf("element inserted\n");

}

void insertnode()
{
    if(Start==NULL)
    {
        printf("first create the list and then insert\n\n");
        return;

    }
    int ch;
printf("Enter 1 to insert at begining\n ");
printf("Enter 2 to insert at end\n ");
printf("Enter 3 to insert after an element\n ");
printf("Enter 4 to insert before an element\n\n ");
printf("press enter to continue\n");
getch();
printf("now enter your choice for insertion operation\n");
scanf("%d",&ch);



switch(ch)
{
    case 1:insertatbeg();
    break;
    case 2:insertatend();
    break;
    case 3:insertafter();
    break;
    case 4:insertbefore();
    break;
    default:printf("invalid choice\n");

}
}

void delbeg()
{
struct node *r;
    if(Start==NULL)
    {

        printf("list is empty\n");

    }
    else{
        r=Start;
        Start=Start->link;
        free(r);

    printf("element deleted\n");
}
}
void delend()
{
 struct node *r,*s;
            s=Start;
            r=NULL;
    if(Start==NULL)
    {

        printf("list is empty\n");

    }
    else{

            while(s->link!=NULL)
            {    r=s;
                s=s->link;

            }
            r->link=NULL;
            free(s);
printf("element deleted\n");
    }
}
void delmid()
{ int x;

    printf("enter the element you want to delete\n");
    scanf("%d",&x);
    struct node *r,*s;
           s=Start;
            r=NULL;
    if(Start==NULL)
    {

        printf("list is empty\n");

    }

    else{
           while(s->info!=x)
            {
                if(s->link==NULL)
                {
                    printf("%d is not in the list\n",x);
                    return;
                }
                r=s;
                s=s->link;


}
r->link=s->link;
        free(s);
        printf("%d is deleted from the list\n",x);

    }

}
void deloccu()
{
    int x;
    printf("enter the particular element");
    scanf("%d",&x);
    struct node *r,*s;
            s=Start;
            r=NULL;
            while(s!=NULL)
            {

                if(s->info==x)
                {
                    if(r==NULL)
                    {
                        Start=s->link;
                        free(s);
                        s=Start;
                    }
                    else{
                        r->link=s->link;
                        free(s);
                        s=r->link;
                    }
                }
                 else if(s->link==NULL)
                {
                    printf("%d is not in the list\n",x);
                    return;
                }
                else
                {

                    r=s;
                    s=s->link;
            }
            }
            printf("All occurance of %d are deleted from the list\n",x);

}
void deletenode()
{
    int ch;
    printf("enter 1 to delete the element from begining\n");
    printf("enter 2 to delete the element from end\n");
    printf("enter 3 to delete the element anywhere in the middle\n");
    printf("enter 4 to delete a particular occurance of an element\n\n");
    printf("press enter to continue\n");
    getch();
    printf("enter your choice for deletion operation\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:delbeg();
        break;
        case 2:delend();
        break;
        case 3:delmid();
        break;
        case 4:deloccu();
        break;
        default:printf("Invalid choice\n");
    }

}
void view()
{

    struct node *t;
    if(Start==NULL)
        printf("list is empty\n");
    else{
        t=Start;
        printf("inserted elements are\n");
        while(t->link!=NULL)
        {

            printf("%d ",t->info);
            t=t->link;
        }
        printf("%d \n",t->info);
    }
}
void listrev()
{

    struct node *r,*s,*t;
    if(Start==NULL)
        printf("list is empty\n");
    else{
        s=Start;
        r=NULL;
        t=s->link;
        s->link=NULL;
        while(t!=NULL)
        {

            r=s;
            s=t;
            t=s->link;
            s->link=r;
        }
        Start=s;
         printf("Whole list is reversed\n");
    }




}

int main()
{
    while(1)
{
    int ch;
    printf("enter 1 to create list\n");
    printf("enter 2 to insert\n");
    printf("enter 3 to view\n");
    printf("enter 4 to delete\n");
    printf("enter 5 to reverse the list\n");
    printf("enter 6 to exit\n\n");
    printf("press enter to continue\n");
    getch();


    printf("enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {

        case 1:createlist();
        break;
        case 2:insertnode();
        break;
        case 3:view();
        break;
        case 4:deletenode();
        break;
        case 5:listrev();
        break;
        case 6:exit(0);
        break;
        default: printf("invalid choice\n");
        getch();
}
}
return 0;
}



