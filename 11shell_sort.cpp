//sort  a list of numbers using shell sort
#include<stdio.h>
#include<conio.h>
void shell_sort(int x[],int n)
{
    int i,j,val,inc,k;
    for(inc=n/2;inc>=1;inc=inc/2)
    {
        for(k=inc;k<n;k++)
        {
             val=x[k];

            for(i=k;i>=inc && x[i-inc]>val;i-=inc)
                x[i]=x[i-inc];
            x[i]=val;
        }
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

    shell_sort(x,n);
    printf("Elements after sorting is\n");
    for(i=0;i<n;i++)

    printf("%d ",x[i]);
    getch();
}
