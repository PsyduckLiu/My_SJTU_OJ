#include <iostream>

using namespace std;

int main()
{
   int year,month;
   bool result1;

   cin>>year>>month;
   result1=(year%4==0&&year%100!=0)||year%400==0;

   if (year>=0&&year<=10000&&month>=1&&month<=12)
     if (result1)
   {
       switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout<<"31";  break;
        case 4:
        case 6:
        case 9:
        case 11: cout<<"30"; break;
        case 2: cout<<"29"; break;}
   }
     else
    {
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout<<"31";  break;
        case 4:
        case 6:
        case 9:
        case 11: cout<<"30"; break;
        case 2: cout<<"28"; break;}
    }
     else cout<<"Error!"<<endl;


    return 0;
}
