#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char a[2001];
    cin.getline(a,2001);

    long long int i,sum=0;

    for (i=0;i<strlen(a);i++) {
        if (a[i]==' ') sum+=0;
        else {
            if (a[i]>='A'&&a[i]<='Z') sum+=(a[i]-'A'+1)*(i+1);
            else sum+=(a[i]-'a'+27)*(i+1);
    }}

    cout<<sum;

    return 0;
}
