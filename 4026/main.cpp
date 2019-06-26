#include <iostream>

using namespace std;

int main()
{
  int num1,num2,num3,num4,num5;
  char num6,num7,num8,num9;
   cin>>num1;

   num2=num1%10;
   num3=(num1-num2)/10%10;
   num4=(num1-num2-num3*10)/100%10;
   num5=(num1-num2-num3*10-num4*100)/1000%10;

   num6=num2+12+'A';
   num7=num3+12+'A';
   num8=num4+12+'A';
   num9=num5+12+'A';

   cout<<num9<<num8<<num7<<num6<<endl;
    return 0;
}
