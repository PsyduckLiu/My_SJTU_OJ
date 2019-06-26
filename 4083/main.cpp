#include <iostream>
#include <cstring>
struct studentT{
       char xuehao[10];
       char name[21];
       int chengji;
   } ;
using namespace std;

int main()
{
   studentT student[10000];
   studentT tmp;
   int num=0;
   char kind[10001][2];
   int j=0,k=0,l,m=1,n=1;
   char xuehao3[10000][10];
   char name4[10000][21];
   int c=0,d=0;
   int e,f;
   int q=0;
   do {
    if (q==0) cin.getline(kind[q],2,' ');
    else {
        cin.get();
         cin.getline(kind[q],2,' ');
    }
   if (*kind[q]=='1') {

       cin.getline(student[num].xuehao,10,' ');

      if (num==0) {
         cin.getline(student[num].name,21,' ');
         cin>>student[num].chengji;
         cout<<"SUCCESS"<<endl;
      }
      for (l=0;l<num;l++) {
        m=strcmp(student[l].xuehao,student[num].xuehao);
        if (m==0) cout<<"FAILED"<<endl;
        break;
        }
        if (m!=0) {
      cin.getline(student[num].name,21,' ');
      cin>>student[num].chengji;
      cout<<"SUCCESS"<<endl;
      } }}

     if (*kind[q]=='2') {
            if (num==0) continue;
            else {for (j=0;j<num;j++) cout<<student[j].xuehao<<' '<<student[j].name<<' '<<student[j].chengji<<endl;
        }}

     if (*kind[q]=='3') {
        cin.getline(xuehao3[c],10,' ');
            c+=1;
            for (l=0;l<num;k++) {
        m=strcmp(student[l].xuehao,student[num].xuehao);
        if (m==0) {cout<<student[1].xuehao<<' '<<student[1].name<<' '<<student[1].chengji<<endl;
                    break;}
     }
     }

     if (*kind[q]=='4') {
        cin.getline(name4[d],21,' ');
            d+=1;
       for (l=0;l<num;k++) {
        n=strcmp(student[l].name,student[num].name);
        if (n==0) {cout<<student[1].xuehao<<' '<<student[1].name<<' '<<student[1].chengji<<endl;
                    break;}
     }}
     if (*kind[q]=='5') {
        for (e=1;e<num;e++) {
            for (f=0;f<num-e;f++) {
                if (strcmp(student[f+1].xuehao,student[f].xuehao)<0) {
                    tmp=student[f]; student[f]=student[f+1]; student[f+1]=tmp;
                    }
            }

        }
        for (j=0;j<num;j++) cout<<student[j].xuehao<<' '<<student[j].name<<' '<<student[j].chengji<<endl;
     }
     if (*kind[q]=='6') {
        for (e=1;e<num;e++) {
            for (f=0;f<num-e;f++) {
                if (student[f+1].chengji<student[f].chengji) {
                    tmp=student[f]; student[f]=student[f+1]; student[f+1]=tmp;
                    }
            }

        }
        for (j=0;j<num;j++) cout<<student[j].xuehao<<' '<<student[j].name<<' '<<student[j].chengji<<endl;
     }
     if (*kind[q]=='7')   cout<"END";
    q+=1;
    n=1;m=1;
    num+=1;

}while (*kind[q]!='7');






    return 0;
}
