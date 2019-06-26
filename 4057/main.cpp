#include <iostream>

using namespace std;

int main()
{
    int i,j,m,n,a,num,p,q;
    char ch[10001],ch2[10001];
    a=0;
    num=0;

    cin.getline(ch,10001);
    for (i=0;ch[i]!='\0';i++)
    for (j=i+1;ch[j]!='\0';j++) {
        m=i;
        n=j;
        while (ch[m]==ch[n]) {
            if (m>n)  break;
            if (m!=n) a+=2;
            if (m==n) a+=1;
            m+=1;
            n-=1;
        }
        if (m<=n) a=0;
        if (m>n) {
            if (a>num) {
                num=a;
                a=0;
                p=i;
                q=0;
                while (p<=j) {
                    ch2[q]=ch[p];
                    q+=1;
                    p+=1;
                }
                }
            else a=0;
            }
        }


    if (num==0) cout<<num;
    else {
        cout<<num<<endl;
        for (i=0;ch2[i]!='\0';i++) cout<<ch2[i];
    }

    return 0;
}
