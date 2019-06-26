#include <iostream>
 
#include <cstdio>
 
using namespace std;
 
int N,top=-1;
 
char stack[1000005];
int stack2[1000005];
int flag[1000005];
 
void push(char c)
{
    stack[++top]=c;
 
}
 
void pop()
{
 
    if (top!=-1)
 
        top-=1;
 
}
 
void topp()
{
 
    if (top!=-1)
 
        printf("%c\n",stack[top]);
 
}
 
void judge()
 
{
 
    if (flag[top]==2 || top == -1)
 
        printf("YES\n");
 
    else
        printf("NO\n");
 
}
int main(int argc, char const *argv[])
 
{
 
    scanf("%d",&N);
 
    int op;
 
 
 
    for (int i=0; i<N; i++)
 
    {
 
        scanf("%d",&op);
 
        char tmp;
 
        switch(op)
 
        {
 
        case 1:
 
        {
            bool flag1=true;
 
            scanf(" %c",&tmp);
 
            push(tmp);
 
            switch (tmp)
 
            {
 
            case '(':
                stack2[top]=top;
                break;
 
            case ')':
                stack2[top]=stack2[top-1];
                if (stack2[top]==-1 || stack[stack2[top]]!='(')
                    flag1=false;
                else if (stack2[top-1]==0)
                    stack2[top]=-1;
                else
                    stack2[top]=stack2[stack2[top-1]-1];
                break;
 
            case '[':
                stack2[top]=top;
                break;
 
            case ']':
                stack2[top]=stack2[top-1];
                if (stack2[top]==-1 || stack[stack2[top]]!='[')
                    flag1=false;
                else if (stack2[top-1]==0)
                    stack2[top]=-1;
                else
                    stack2[top]=stack2[stack2[top-1]-1];
                break;
 
            case '{':
                stack2[top]=top;
                break;
 
            case '}':
                stack2[top]=stack2[top-1];
                if (stack2[top]==-1 ||stack[stack2[top]]!='{')
                    flag1=false;
                else if (stack2[top-1]==0)
                    stack2[top]=-1;
                else
                    stack2[top]=stack2[stack2[top-1]-1];
                break;
 
            }
 
            if (stack2[top]==-1 && flag1 && flag[top-1]!=-1)
 
                flag[top]=2;
 
            else if (!flag1)
 
                flag[top]=-1;
 
            else
                flag[top]=1;
 
        }
 
        break;
 
        case 2:
            pop();
            break;
 
        case 3:
            topp();
            break;
 
        case 4:
            judge();
            break;
 
        }
 
    }
 
    return 0;
 
}
