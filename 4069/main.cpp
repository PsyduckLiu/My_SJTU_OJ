#include <iostream>

using namespace std;

void num(char a[],char b);

int main()
{
    char str[31];

    cin.getline(str,31,' ');
    char ch;
    cin.get(ch);


    num(str,ch);

    return 0;
}
void num(char a[],char b)
{
    int i,j=0;
    char *p;
    p=a;

    for (i=0;*(p+i)!='\0';i++) {
        if (*(p+i)==b) {
           j+=1;
        if (j==1) cout<<i;
        if (j!=1) cout<<' '<<i;

        }}

      if (j==0) cout<<"NULL";
    }

