//sort  a list of numbers using quick sort
#include<stdio.h>
#include<conio.h>
int parti(int x[],int lb,int ub)
{

    int val=x[lb],down=lb+1,up=ub,t;
    while(down<=up)
    {


    while(down<=up &&x[down]<val)
    down++;
    while(x[up]>val)
        up--;
    if(down<up)
    {

        t=x[down];
        x[down]=x[up];
        x[up]=t;
    }
}
x[lb]=x[up];
x[up]=val;
return up;
}
void quicksort(int x[],int lb,int ub)
{

    int p;
    if(lb<ub)
    {

p=parti(x,lb,ub);
        quicksort(x,lb,p-1);
        quicksort(x,p+1,ub);

    }
}

int main()
{

    int x[20],i,n;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&x[i]);
    quicksort(x,0,n-1);
    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d ",x[i]);
    getch();

}
