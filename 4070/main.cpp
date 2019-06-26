#include <iostream>

using namespace std;
char *del(char a[],char b);
int main()
{
    char ch;
    char str[32][31];
    int i,j,k,l,n=0;
    l=0;
    char *m[32];
    char *tmp;
    cin.get(ch);
    cin.get();

    for (i=0;i<32;i++) {
        cin.getline(str[i],31,'\n');
        if (str[i][0]=='@') {
                k=i;
                break;
}
    }

if (k==1) {
        m[0]=del(str[0],ch);
        for (i=0;*(m[0]+i)!='\0';i++) cout<<*(m[0]+i);}
 else {
  for (i=0;i<k;i++) {
       m[i]=str[i];
       m[i]=del(str[i],ch);
  }

  for (j=1;j<k;j++) {
        for (i=0;i<k-j;i++) {

            while (*(m[i]+l)==*(m[i+1]+l)) {
                l+=1;
                if (*(m[i]+l)=='\0'||*(m[i+1]+l)=='\0') break;
            }
             if  (*(m[i]+l)>*(m[i+1]+l)) {
            n=1;}
            if (n==1) {
         tmp=m[i];m[i]=m[i+1];m[i+1]=tmp;
        }

        n=0;
        l=0;
}
  }
  for (i=k-1;i>=0;i--){

            if (i==k-1) cout<<m[i];
            else {cout<<endl; cout<<m[i];}

   }
 }


    return 0;
}
char *del(char a[],char b)
{
   int i,j;
   i=j=0;
   for(i=0;a[i]!='\0';i++) {
    if (a[i]!=b) {
        a[j]=a[i];
        j++;
    }
    }a[j]='\0';
    return a;

}
