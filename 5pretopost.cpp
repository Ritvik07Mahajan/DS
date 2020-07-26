// conversion of prefix to postfix expression
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void subst(char *source,int s_index,int l,char *des)
{

    int i=0;
    while(l!=0)
    {

        des[i]=source[s_index];
        i++;
        s_index++;
        l--;

    }
    des[i]='\0';
}
int findlength(char *exp)
{

    int length=strlen(exp);
    int m,n;
    char temp[30];
    if(length==0)
    {

        return 0;
    }
    if(isalpha(exp[0]))
    {

        return 1;

    }
    if(strlen(exp)<3)
    {

        return 0;

    }
    else{
        subst(exp,1,length-1,temp);
        m=findlength(temp);

        subst(exp,m+1,length-m-1,temp);
        n=findlength(temp);

        if(n==0||m==0)
            printf("invalid expression");
            return m+n+1;

    }
}

void pre_to_post(char *pre,char *post)
{

    int length=strlen(pre);
    int m,n;
    char op[100],temp[100],op1[100],op2[100],post2[100];
    if(length==1)
    {

        if(isalpha(pre[0]))
        {
            post[0]=pre[0];
            post[1]='\0';
            return ;

        }
        else{
            printf("invalid expression");
            return;

        }

    }
    else
    {

        op[0]=pre[0];
        op[1]='\0';
        subst(pre,1,length-1,temp);
        m=findlength(temp);

        subst(pre,m+1,length-m-1,temp);
        n=findlength(temp);

        if(op[0]!='/'&&op[0]!='*'&& op[0]!='+'&&op[0]!='-'&&op[0]!='$'||m==0||n==0||m+n+1!=length)
        {

            printf("invalid case");

        }
        else
        {
            subst(pre,1,m,op1);
            subst(pre,m+1,n,op2);

            pre_to_post(op1,post);
            pre_to_post(op2,post2);
            strcat(post,post2);
            strcat(post,op);
            return;

             }
    }
}

int main()
{

    char prefix[100],postfix[100];
    printf(" enter prefix expression");
    scanf("%s",&prefix);
    pre_to_post(prefix,postfix);

    printf(" the corresponding postfix expression is  %s\n",postfix);
    return 0;
    }
