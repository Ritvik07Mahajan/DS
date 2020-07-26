//Implementation of circular queues
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int max=4;
int q[4];
int flag=1;
void insert(int x)
{


    if((front==0&&rear==max-1)||(rear==front-1))
    {
        printf("queue is overflow as the maximum size is 4\n");
        flag=0;
    }
else{
    if(front==-1)
{

front=rear=0;
q[rear]=x;
}
 else if(rear==max-1&&front!=0)
        {
            rear=0;
            q[rear]=x;


        }
    else{
        rear++;
    q[rear]=x;
    }

    }
}

void del()
{
    int a;
    if(front==-1)
    {
        printf("queue is underflow\n");
        getch();
        exit(0);


    }
    else if(front==rear)
    {
        a=q[front];
    front=-1;
    rear=-1;

    }
    else if(front==max-1)

        {
            a=q[front];
            front=0;

        }
        else a=q[front++];
        printf("deleted element is:%d\n",a);
    }

void view()
{
int i;
printf("Items are :");
for(i=front;i!=rear;i=(i+1)%max)
{
    printf("%d ",q[i]);
}
printf("%d ",q[i]);

    }



int main()
{int i,n,element;
printf("enter the no of element to insert and it should be less then or equal  to 4(size of array) \n");
        scanf("%d",&n);
        if(n>4)
        {

            printf("input should be less than or equal to 4 and now it will terminate\n");
            getch();
            exit(0);
        }
        printf("now enter elements to insert in the list\n");
        for(i=0;i<n;i++)
        {


            scanf("%d",&element);
            insert(element);

        }
        printf("elements inserted in the list \n");
    int ch;


    printf("enter 1 to insert a single element at a time\n");
    printf("enter 2 to delete a single element at a time\n");
    printf("enter 3 to view the list\n");
    printf("enter 4 to exit\n\n");
    printf("press enter to continue\n");
    getch();
while(1)
{


    printf("enter your choice\n");
    scanf("%d",&ch);


    switch(ch)
    {

        case 1:
printf("please enter the element\n");

            scanf("%d",&element);
            insert(element);
            if(flag==0)
            {

            }
                else
            printf("element inserted\n");



        break;
        case 2:del();
        break;
        case 3:view();
        break;
        case 4:exit(0);
        break;
        default: printf("invalid choice");

    }
}
return 0;

}
