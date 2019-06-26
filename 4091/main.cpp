#include <iostream>

using namespace std;
class Time {
 friend ostream& operator<<(ostream &os,const Time &t);
 friend istream& operator>>(istream &in, Time &t);


 private :
     int tt,ss,mm,second;
 public :
    Time &operator++() {++second; return *this;}
    Time operator++ (int x) {
       Time tmp=*this;
       ++second;
       return tmp;
    }
    Time &operator--() {--second;   return *this;}
    Time operator--(int x) {
       Time tmp=*this;
       --second;

       return tmp;
    }
    Time &operator+=(const Time &t) {second+=t.second; return *this;}
    Time &operator-=(const Time &t) {second-=t.second; return *this;}
};
ostream &operator<<(ostream &os,const Time &t)
{
    int h,m,s;
    h=t.second/3600;
    m=t.second%3600/60;
    s=t.second%60;
    if (s<0) {
        s=60+s;
        m=59;
        h=23;
    }

    if (h>=24) h=h%24;
    if (h<10) {
        if (m<10) {
            if (s<10) os<<'0'<<h<<':'<<'0'<<m<<':'<<'0'<<s<<endl;
            if (s>=10) os<<'0'<<h<<':'<<'0'<<m<<':'<<s<<endl;
        }
        if (m>=10) {
            if (s<10) os<<'0'<<h<<':'<<m<<':'<<'0'<<s<<endl;
            if (s>=10) os<<'0'<<h<<':'<<m<<':'<<s<<endl;
        }

      }

    if (h>=10&&m<10){
            if (s<10) os<<h<<':'<<'0'<<m<<':'<<'0'<<s<<endl;
            else os<<h<<':'<<'0'<<m<<':'<<s<<endl;
        }
    if (h>=10&&m>=10&&s<10)  os<<h<<':'<<m<<':'<<'0'<<s<<endl;

    if (h>=10&&m>=10&&s>=10) os<<h<<':'<<m<<':'<<s<<endl;
    return os;
}
istream &operator>>(istream &in, Time &t)
{

    in >> t.tt >> t.ss>> t.mm;
    t.second=t.tt*3600+t.ss*60+t.mm;
    return in;
}



int main()
{
   Time time1,time2;
   cin>>time1;
   cin>>time2;

   cout<<(time1+=(time2++));
   cout<<(time1-=time2);
   cout<<++time2;
   cout<<(time2+=(time1--));
   cout<<--time1;
   cout<<(time2-=time1);
    return 0;
}
