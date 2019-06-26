#include <iostream>
#include <cstdio>
using namespace std;
 
char tmp[1000000],tmp2[1000000];
int main()
{
 
    int i,n,j,no,l1=0,l2;
    bool flag;
    char bracket;
    scanf("%d",&n);
    for (i=0; i<n; ++i)
    {
        scanf("%d",&no);
        flag=true;
        l2=0;
        if (no==1)
        {
            scanf("%c",&bracket);
            scanf("%c",&bracket);
            tmp[l1++]=bracket;
            continue;
        }
        if (no==2)
        {
            if (l1==0)
                continue;
            --l1;
            continue;
        }
        if (no==3)
        {
            if (l1==0)
                continue;
            printf("%c\n",tmp[l1-1]);
            continue;
        }
        if (no==4)
        {
            if (l1==0)
            {
                printf("YES\n");
                continue;
            }
            if (l1%2==1)
            {
                printf("NO\n");
                continue;
            }
 
            for (j=0; j<l1; ++j)
            {
                if (tmp[j]=='('||tmp[j]=='['||tmp[j]=='{')
                {
                    tmp2[l2++]=tmp[j];
                    continue;
                }
                else
                {
                    if (l2==0)
                    {
 
                        flag=false;
                        break;
                    }
                    if (tmp[j]==')')
                    {
                        if (tmp2[l2-1]=='(')
                        {
                            --l2;
                            continue;
                        }
                        else
                        {
 
                            flag=false;
                            break;
 
                        }
                    }
                    if (tmp[j]==']')
                    {
                        if (tmp2[l2-1]=='[')
                        {
                            --l2;
                            continue;
                        }
                        else
                        {
                  flag=false;
                            break;
 
                        }
                    }
                    if (tmp[j]=='}')
                    {
                        if (tmp2[l2-1]=='{')
                        {
                            --l2;
                            continue;
                        }
                        else
                        {
 
                            flag=false;
                            break;
 
                        }
                    }
                }
            }
 
 
            if (flag&&l2==0)
                printf("YES\n");
            else
                printf("NO\n");
            continue;
 
        }
    }
    return 0;
}
