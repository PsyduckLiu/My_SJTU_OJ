#include <iostream>
int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
using namespace std;
class date{public:
int y;
int m;
int d;


    void input(int a,int b,int c)
    {
        y=a; m=b; d=c;
    }

};

int main()
{
    date time;
    char str[9];
    int i,j=1;
    unsigned int n;
    int year,month,day;
    int ye[4];
    int mo[2];
    int da[2];
    cin>>str>>n;

   year=(str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0');
   month=(str[4]-'0')*10+(str[5]-'0');
   day=(str[6]-'0')*10+(str[7]-'0');

   time.input(year,month,day);


   for (i=0;i<n;i++) {

    time.d++;
    if (time.m!=2) {
        if (time.d>DAY[time.m-1]) {
        time.m++;
        time.d=1;}}
    if (time.m==2) {
        if ((time.y%4==0&&time.y%100!=0)||time.y%400==0) {
        if (time.d>29) {
        time.m++;
        time.d=1;}}
        else {if (time.d>28) {
        time.m++;
        time.d=1;}}
    }
    if(time.m>12){
    time.y++;
    time.m=1;}
if (time.y>=10000) {cout<<"out of limitation!";
                     j=0;
                     break;
                     }

        }
    if (time.y<10) {ye[0]=ye[1]=ye[2]=0; ye[3]=time.y;}
    if (time.y>=10&&time.y<100) {ye[0]=ye[1]=0; ye[3]=time.y%10; ye[2]=time.y/10;}
    if (time.y>=100&&time.y<1000) {ye[0]=0; ye[1]=time.y/100; ye[2]=(time.y-ye[1]*100)/10; ye[3]=time.y%10;}
    if (time.y>=1000) {ye[0]=time.y/1000; ye[1]=(time.y-ye[0]*1000)/100; ye[2]=(time.y-ye[0]*1000-ye[1]*100)/10; ye[3]=time.y%10;}
    if (time.m<10) {mo[0]=0; mo[1]=time.m;}
    if (time.m>=10) {mo[0]=time.m/10; mo[1]=time.m%10;}
    if (time.d<10) {da[0]=0; da[1]=time.d;}
    if (time.d>=10) {da[0]=time.d/10; da[1]=time.d%10;}

   if (j==1) {for (i=0;i<=3;i++) cout<<ye[i];
              for (i=0;i<=1;i++) cout<<mo[i];
              for (i=0;i<=1;i++) cout<<da[i];}

    return 0;
}
