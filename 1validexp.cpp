//validity of parenthesis in a mathematical expreesion
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int top=-1;
char stack[100];
void push(char a)
{

    top++;
    stack[top]=a;
}
char pop()
{
    return(stack[top--]);

    }

    int main()
    {

        char a[100];int i=0,f=1;
        char t;
        printf("enter the expression");
        scanf("%s",&a);
        while(a[i]!='\0')
        {

            if(a[i]=='('||a[i]=='{'||a[i]=='[')
                push(a[i]);
            else if(a[i]==')'||a[i]=='}'||a[i]==']')
            {
                if(top==-1)
                    f=0;

            t=pop();
            if(a[i]=='}'&&(t=='['||t=='('))
                f=0;
            if(a[i]==')'&&(t=='['||t=='{'))
                f=0;
            if(a[i]==']'&&(t=='{'||t=='('))
                f=0;
        }
        if(f==0)
        {


            printf("invlid expression");
        exit(0);
        }
i++;

    }

    printf("valid");
    return 0;
        }
