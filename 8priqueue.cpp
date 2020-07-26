//Implementation of priority queues using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int pri;
    int info;
    struct node *next;

    }; struct node *start=NULL;

void insertion(int item,int prio)

{
    struct node *temp,*t;
    temp=(node *)malloc(sizeof(node));
    temp->info=item;
    temp->pri=prio;

  if(start==NULL || prio <start->pri)
  {
      temp->next=start;
      start=temp;
  }

    else{
            t=start;
    while((t->next!=NULL) && (t->next->pri <=prio))
        t=t->next;

    temp->next=t->next;
    t->next=temp;

}
printf("element inserted \n\n");
}
void del()
{
    struct node *temp;
    if(start==NULL)
        printf("queue underflow\n");
    else{
            temp=start;
        printf("deleted element is %d\n\n",temp->info);
        start=start->next;
    free(temp);

    }
}
void display()
{

    struct node *t;
    t=start;
    if(start==NULL)
        printf("queue is empty\n");
    else{
            printf("elements in the list are\n");
    while(t!=NULL){
        printf("%d ",t->info);
        t=t->next;
    }
    }
    printf("\n");
}
int main()
{ int ch,item,prio;
printf("                      --------priority queue----------\n");
while(1)
{
    printf("enter 1 for insertion\n");
    printf("enter 2 for deletion\n");
    printf("enter 3 to see the list\n");
    printf("enter 4 to exit\n");
    printf("now enter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("enter the number to be inserted\n");
        scanf("%d",&item);
        printf("now enter its priority \n");
        scanf("%d",&prio);

            insertion(item,prio);
        break;
        case 2:del();
            break;

        case 3 :display();
        break;
        case 4:exit(0);
        break;
        default:printf("Your choice is invalid\n");
        break;


    }

}
}
