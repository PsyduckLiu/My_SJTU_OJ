#include <iostream>

using namespace std;

int main()
{
    int sum,tax;
    int i;

    cin>>sum;
    if (sum<=3500) cout<<0;
    if (sum>3500&&sum<=5000) {
        tax=(sum-3500)*3/100;
    }
    if (sum>5000&&sum<=8000) {
        tax=45+(sum-5000)*10/100;
    }
    if (sum>8000&&sum<=12500) {
        tax=45+300+(sum-8000)*20/100;
    }
    if (sum>12500&&sum<=38500) {
        tax=45+300+900+(sum-12500)*25/100;
    }
    if (sum>38500&&sum<=58500) {
        tax=45+300+900+6500+(sum-38500)*30/100;
    }
    if (sum>58500&&sum<=83500) {
        tax=45+300+900+6500+6000+(sum-58500)*35/100;
    }
    if (sum>83500) {
        tax=45+300+900+6500+6000+8750+(sum-83500)*45/100;
    }
    cout<<tax;
    return 0;
}
