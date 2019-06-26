#include<iostream>
#include<algorithm>
 
using namespace std;
 
int N;
 
struct arrange{
     int start;
     int end;
}
Arrange[100010];
 
bool cmp(arrange a,arrange b){
     return a.end<b.end;
}
 
int selector() {
    int num=1,i=0;
    for(int j=1;j<N;j++)
    if(Arrange[j].start>=Arrange[i].end){
        i=j;
        num++;
    }
return num;
 
}
 
 
 
int main()
 
{
 
    int t,ans;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>Arrange[i].start>>Arrange[i].end;
    sort(Arrange,Arrange+N,cmp);
    ans = selector();
    cout<<ans<<endl;
 
return 0;
 
}
