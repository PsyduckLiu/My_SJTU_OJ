#include <iostream>

using namespace std;
void print(char a,int b);
void print2(char a,int b,int c);
int main()
{
    char ch;
    int i,j,k;

    cin>>ch>>i;
    j=i/2+1;
    print(ch,j);
    print2(ch,i-j,i);
    return 0;
}
void print(char a,int b)
{
    int i,j;
    for(i=1;i<=b;i++) {

        for(j=1;j<=b-i;j++) cout<<" ";
        for (j=1;j<=2*i-1;j++) cout<<a;
        cout<<endl;
    }
}
void print2(char a,int b,int c)
{
    int i,j;
    for(i=1;i<=b;i++) {

        for(j=c;j>c-i;j--) cout<<" ";
        for (j=1;j<=c-2*i;j++) cout<<a;
        cout<<endl;
    }
    cout<<endl;
}
