#include <iostream>

using namespace std;

int main()
{
    double num1,num2,num3;
    bool result;

    cin>>num1>>num2>>num3;
    result=(num1+num2)>num3&&(num1+num3)>num2&&(num2+num3)>num1;

    if (result)
        if ((num1*num1+num2*num2)==num3*num3||(num1*num1+num3*num3)==num2*num2||(num3*num3+num2*num2)==num1*num1)
        cout<<"1"<<endl;
        else cout<<"0"<<endl;
    else cout<<"-1"<<endl;


    return 0;
}
