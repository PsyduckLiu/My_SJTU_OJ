#include <iostream>

using namespace std;

int main()
{
    int y,m,d,i,num,t;
    bool result;
cin>>y>>m>>d;

    num=0;
    t=1;
     if (y>0) result=(y%4==0&&y%100!=0)||y%400==0;

    if (y<0||y>9999||m<=0||m>12) { t=0; cout<<"error";}
    else {
    if (m==2) {
        if (result) {
            if (d>29||d<=0) {t=0; cout<<"error";}
        }
        if (result==false||y==0) {
            if (d>28||d<=0) {t=0; cout<<"error";}
        }
    }
    if (m==1||m==3||m==5||m==7||m==8||m==10|m==12)  {
            if (d>31||d<=0) {t=0; cout<<"error";}
            }
    if (m==4||m==6||m==9||m==11) {
            if (d>30||d<=0) {t=0; cout<<"error";}
    }
    }
     if (t!=0){


            for (i=1;i<m;i++) {
            if (i==1||i==3||i==5||i==7||i==8||i==10||i==12) {
                num+=31;
            }
            if (i==4||i==6||i==9||i==11) {
                num+=30;
            }
            if (i==2) {
                if (result&&y>0) num+=29;
                if (result==false||y==0)  num+=28;
            }
        }

    num+=d;
    cout<<num;}

    return 0;
}
