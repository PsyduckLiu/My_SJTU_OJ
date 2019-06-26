#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,i,j=0,k=0,num=0,l,f,e,t;
    char model[105];
    char s[105];
    char a[1005][105],b[1005][105];
    char c;

    cin>>n;

    cin.get();
    cin>>model;

    for (i=0;i<strlen(model);i++) {
        if (model[i]=='-') {
            j+=1;
            if (j==1) f=i;
            if (j==2) {e=i;
            break;}
        }
    }
    for (i=f;i<=e;i++) {
        s[k]=model[i];
        k++;
    }

     s[k]='\0';
    strcpy(model,s);

    l=strlen(model);

     for (i=0;i<n;i++) {
            cin>>a[i];
            j=0;
            t=0;
            for (k=0;k<strlen(a[i]);k++) {
             if (a[i][k]=='-') {
               j+=1;
               if (j==1) f=k;
               if (j==2) {e=k;
               break;}
        }
    }
    for (int m=f;m<=e;m++) {
        s[t]=a[i][m];
        t++;
    }

     s[t]='\0';
    strcpy(a[i],s);

    }

    for (i=0;i<n;i++) {
        if (l!=strlen(a[i])) continue;

        else {
            for (j=0;j<n;j++) {
                    strcpy(b[j],a[j]);
            for (k=l-1;k>=l/2;k--) {
                        c=b[j][k];
                        b[j][k]=b[j][l-k-1];
                        b[j][l-k-1]=c;

            }
            }


            for (j=0;j<l-2;j++) {
                if (strcmp(model,a[i])==0) {
                        num+=1;
                        break;}
                if (strcmp(model,b[i])==0) {
                        num+=1;
                        break;}

                c=model[l-2];
                for (k=l-2;k>=2;--k) model[k]=model[k-1];
                model[1]=c;

        }
    }
    }

    cout<<num;
    return 0;
}



