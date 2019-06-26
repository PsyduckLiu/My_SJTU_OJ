#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int a[155][155];
int N;
int count=0;
void bianli(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<setw(6)<<a[i][j];
        }
        cout<<endl;
    }
}
bool isOK(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j] == -1){
                return false;
            }
        }
    }
    return true;
}
 
 
int main(){
    cin>>N;
    int flag = 0;
    int j = 0,k = 0;
    memset(a,-1,sizeof(a));
    while(1){
        if(isOK()){
            break;
        }
        if(flag == 0){
            for(;;j++){
                if(j >= N || a[k][j] > 0){
                    flag=1;
                    j--;
                    break;
                }
                a[k][j] = ++count;
            }
        }
        else if(flag == 1){
            while(1){
                ++k;
                if(k >= N || a[k][j] > 0){
                    flag=2;
                    k--;
                    break;
                }
                a[k][j] = ++count;
            }
        }
        else if(flag == 2){
            while(1){
                j--;
                if(j < 0 || a[k][j] > 0){
                        flag=3;
                        j++;
                        break;
                    }
                    a[k][j] = ++count;
                }
        }
        else if(flag == 3){
            while(1){
                k--;
                if(k < 0 || a[k][j] > 0){
                    flag=0;
                    k++;
                    j++;
                    break;
                }
                a[k][j] = ++count;
            }
        }
    }
    bianli();
    return 0;
}
