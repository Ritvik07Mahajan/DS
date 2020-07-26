// Evaluation of postfix expression
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
 char opstk[100];
 int top=-1;

void push(int a)
{
top++;
opstk[top]=a;
}
char pop()
{   return opstk[top--];
}


int cal(char a,int o1,int o2)
{ int i,r;
long res=1;
if(a=='+')
return(o1+o2);
else if(a=='-')
return(o2-o1);
else if(a=='*')
return(o1*o2);
else if(a=='/')
return(o2/o1);
else if(a=='$')
{
while(o1>0)

{
res*=o2;
--o1;
}
return (res);
}



else return(0);
}


int fun(char a[100])
{
    int i=0;
    char s,o1,o2;
     int x,y;
     int res;
    while (a[i]!='\0')
   {
    s=a[i];
//if(s=='0'||s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9')
   if(isdigit(s))
{
   push(s-'0');
}
    else
{
    o1=pop();

    o2=pop();

    res=cal(s,o1,o2);
    push(res);  }
     i++;
}
       res=pop();
       return(res);
}

int main()
{

int r;
 char arr[100];
printf("Enter the expression");
scanf("%s",&arr);
r=fun(arr);
printf("%d",r);
getch();
}
