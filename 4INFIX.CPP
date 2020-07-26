// conversion of infix to postfix expression
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
char opstk[100];
int top=-1;
int arr[100];
int i=0;
void push(char a)
{
top++;
opstk[top]=a;

}
char pop(){
return opstk[top--];
}
int priority(char a)
{
if(a=='$'&& opstk[top]=='$')
return 1;
if(a=='*'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'))
return 1;
//else if(a=='*'&&(opstk[top]=='+'||opstk[top]=='-'))


if(a=='/'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'))
return 1;

//else if(a=='/'&&(opstk[top]=='+'||opstk[top]=='-'))
//push(a);


else if(a=='+'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'||opstk[top]=='+'||opstk[top]=='-'))
 return 1;
  else if(a=='-'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'||opstk[top]=='+'||opstk[top]=='-'))
 return 1;
 else return 0;
}
void insert(char a)
{
arr[i]=a;
i++;

}
void show()
{   int j;
for(j=0;j<i;j++)
printf("%s",&arr[j]);
}


void fun(char a[100])
{     int i=0; char s;
while(a[i]!='\0')
{
s=a[i];
if(isalnum(s))
//printf("%c",s);
 insert(s);
else if(s=='(')
push(s);

 else if(s==')')
{
while(opstk[top]!='(')
{
//printf("%c",pop());
  insert(pop());
}
pop();
}

 else
  {
    while(priority(s))
    {
    // printf("%c",pop());
      insert(pop());
    }
   push(s);
  }
i++;
}}
int main()
{            char a[100];

printf("enter the infix expression");
scanf("%s",&a);
fun(a);
while(top>=0)
{
// printf("%c",pop());
insert(pop());
}
show();

return 0;
}
