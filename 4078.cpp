#include<algorithm>
#include<iostream>
using namespace std;
 
struct student{
    string name;
    int chinese;
    int math;
    int english;
};
 
student s[1025];
 
bool compare(student a,student b){
    if(a.chinese+a.english+a.math!=b.english+b.chinese+b.math){
        return a.chinese+a.english+a.math>b.english+b.chinese+b.math;
    }else{
        if(a.chinese!=b.chinese){
            return a.chinese>b.chinese;
        }else{
            if(a.math!=b.math){
                return a.math>b.math;
            }else{
                if(a.english!=b.english){
                    return a.english>b.english;
                }else{
                    return a.name<b.name;
                }
            }
        }
    }
}
 
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].chinese>>s[i].math>>s[i].english;
    }
    sort(s,s+n,compare);
    int k;
    cin>>k;
    cout<<s[k-1].name<<" "<<s[k-1].chinese+s[k-1].english+s[k-1].math;
    return 0;
}
