// conversion of infix to prefix expression
#include<stdio.h>
#include<ctype.h>
char opstk [100];
int top=-1;
int len=0;
char arr[100];
int var=0;
       void push(char a)
{
      top++;
      opstk[top]=a;
}
       char pop()
{
       return opstk[top--];
}

	int priority(char a)
{
if(a=='$'&& opstk[top]=='$')
return 1;
if(a=='*'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'))
return 1;

if(a=='/'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'))
return 1;

 if(a=='+'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'||opstk[top]=='+'||opstk[top]=='-'))
 return 1;
  if(a=='-'&&(opstk[top]=='*'||opstk[top]=='/'||opstk[top]=='$'||opstk[top]=='+'||opstk[top]=='-'))
 return 1;
 else return 0;
}
     void flength(char a[100])
{          int i=0;
    while(a[i]!='\0')
     {
       len++;
       i++;
     }

}
void insert(char a)
{
	  arr[var]=a;
	 var++;
}

void show()
{   int i;
for(i=var-1;i>=0;i--)
{
printf("%c",arr[i]);
}
}
void fun(char a[100])
{
 char s;
while(len>0)
{
s=a[len-1];
       if(isalnum(s))
insert(s);
else if(s==')')
push(s);

 else if(s=='(')
{
while(opstk[top]!=')')
{
insert(pop());
}
pop();
}

 else
  {
    while(priority(s))
    {
     insert(pop());
    }
   push(s);
  }
  len--;
}
	  }

int main()
{
char a[100];
printf("enter the expression");
scanf("%s",&a);
    flength(a);
    fun(a);
    while(top>=0)
{
    insert(pop());
}
    show();
    return 0;
    }
