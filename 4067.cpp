#include <iostream>
#include <cstring>
using namespace std;
void shit(char c[],int m,char e[]);
 
int main()
{
    char a[52];
    char d[52]={'0'};
    char *p;
    a[0]='0';
    p=a+1;
    cin.getline(p,51,'\n');
 
   shit(a,strlen(a)-1,d);
 
 
 
 
 
    return 0;
}
  void shit(char c[],int m,char e[])
  {
   int i,j=0;
 
 
   if (c[m]>='0'&&c[m]<='8') {
        e[m]=c[m]+1;
     for (i=0;i<m;i++)  e[i]=c[i];
   if (e[0]=='0') {for (j=1;j<strlen(e);j++) cout<<e[j];}
 
        else { for (j=0;j<strlen(e);j++) cout<<e[j];}
}
   else {
    e[m]=c[m]='0';
    shit(c,m-1,e);
    }
 
 
  }
