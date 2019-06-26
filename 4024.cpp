#include <iostream>
 
using namespace std;
 
int main()
{
    int A,B,num1,num2,num3,num4;
    cin>>A>>B;
    num1=A+B;
    num2=A*B;
    num3=A/B;
    num4=A%B;
 
    cout<<A<<"+"<<B<<"="<<num1<<endl;
    cout<<A<<"*"<<B<<"="<<num2<<endl;
    cout<<A<<"/"<<B<<"="<<num3<<endl;
    cout<<A<<"%"<<B<<"="<<num4<<endl;
    return 0;
}
