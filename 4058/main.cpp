#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,i,j,m;
    char A[81],B[81],tmp;
    bool flag;
    m=0;

    cin>>n;

    cin.getline(A,81);

    for (i=0;A[i]!='\0';i++){
        for (j=i+1;A[j]!='\0';j++) {
            if (A[i]==A[j]) {A[j]='.'; }

          }
    }
    for (i=0;A[i]!='\0';i++) {
        if (A[i]>='a'&&A[i]<='z') A[i]=A[i]-'a'+'A';
        else {if (A[i]>='A'&&A[i]<='Z') A[i]=A[i]-'A'+'a';}
        if ((A[i]<='Z'&&A[i]>='A')||(A[i]<='z'&&A[i]>='a')) continue;
        else {
            if (A[i]<'0'||A[i]>'9') A[i]='.';

        }
    }

    for (i=0;A[i]!='\0';i++) {
        if(A[i]!='.') {
            B[m]=A[i];
            m+=1;
        }
    }
    B[m]='\0';
    for (i=1;i<m;i++) {

        for (j=0;j<m-i;j++) {
            if (B[j+1]>B[j]) {
                tmp=B[j];
                B[j]=B[j+1];
                B[j+1]=tmp;

            }

        }

    }
    for (i=0;i<n;i++) {
        for (j=0;B[j]!='\0';j++) {
            cout<<B[j];
        }
    }
    return 0;
}
