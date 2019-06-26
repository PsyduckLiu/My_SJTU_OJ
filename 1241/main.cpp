#include <iostream>

#include <iomanip>



using namespace std;

double GPA[8] = {1.7,2.3,2.7,3.0,3.3,3.7,4.0,4.3};

int main()

{

    double all = 0;

    int n=0;
    int score;
    cin>>n;

    for(int i=0;i<n;++i) {
        cin>>score;

        if(score==60||score==61) {
                all += 1.0;
                continue;}
        if(score==100) {
                all += 4.3;
                continue;}
        if(score==65||score==66) {
                all += 2.0;
                continue;}
        all += GPA[int(score-60)/5];

    }

    all = all/n;

    cout<<fixed<<setprecision(2)<<all;

    return 0;

}
