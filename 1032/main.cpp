#include<iostream>

using namespace std;

int digui(int m,int n){
    if(m==0){
        return n+1;
    }
    else
        if(m != 0 && n == 0){
        return digui(m-1,1);
    }
    else
        if(m != 0 && n != 0){
        return digui(m-1,digui(m, n - 1));
    }
}
int main(){
    int n,m;
    cin>>m>>n;
    cout<<digui(m,n)<<endl;
    return 0;
}

