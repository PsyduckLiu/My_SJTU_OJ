#include <iostream>
#include <cstring>
using namespace std;
 
void shit(char b[],int m);
int main()
{
    int n;
    char a[31];
 
    cin>>n;
    cin.get();
    cin.getline(a,31,'\n');
 
 
    shit(a,n);
 
    return 0;
}
void shit(char b[],int m)
{
    int i,j,k,l,s,t,n;
    char *p;
    k=2*m-2;
    if (m!=1) l=(strlen(b)/k+1)*2;
    s=-1;
    t=0;
    char ch[100][31];
 
    for (i=0;i<m;i++) {
        for (j=0;j<31;j++) {
            ch[i][j]='(';
        }
    }
    if (m==1) {for (i=0;b[i]!='\0';i++) cout<<b[i];}
    else {
    for (p=b;p<b+(strlen(b)/k)*k;p+=k) {
        for (i=0;i<k;i++) {
 
            if (i<m) {s+=1;  ch[s][t]=p[i]; }
 
            else {
                   s-=1;
                   ch[s][t+1]=p[i];
             }}
            s-=2;
            t+=2;
    }
    if(strlen(b)%k!=0) {
         p=b+(strlen(b)/k)*k;
         n=strlen(b)%k;
 
         if (n<=m) {           for (i=0;i<n;i++)  {         s+=1;  ch[s][t]=p[i]; }}
         if (n>m) {
            for (i=0;i<m;i++) { s+=1;  ch[s][t]=p[i]; }
            for (i=m;i<n;i++) {
                s-=1;  ch[s][t+1]=p[i];
            }
         }
    }
 
 
 
       for (i=0;i<m;i++) {
        for (j=0;j<l;j++) {
            if  (ch[i][j]!='(')  cout<<ch[i][j];
 
        }
       }
    }
 
}
