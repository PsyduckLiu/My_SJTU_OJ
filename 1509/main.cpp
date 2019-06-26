#include<iostream>
using namespace std;

 int map[300][3];
 int yearDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};

 int isLeapyear(int year)
 {
    if((year%400==0)||(year%100!=0&&year%4==0))
        return 1;
    else
        return 0;
 }
 int main()
 {
    int aMonth,bWeek,cWeekday;
    int year1,year2;
    int weekDay;

    map[0][0] = 2;
    cin >>aMonth>>bWeek>>cWeekday>>year1>>year2;

    for(int i=1850;i<=2050;i++){
        if(isLeapyear(i)) yearDay[1]=29;
        else              yearDay[1]=28;

        weekDay=map[i-1850][0];
        for(int j=0;j<aMonth-1;j++){
            weekDay=(weekDay+yearDay[j])%7;
        }
        if(weekDay == 0) weekDay = 7;

        map[i-1850][1] = weekDay;
        if(weekDay <= cWeekday)
            map[i-1850][2]=1+cWeekday-weekDay+(bWeek-1)*7;
        else
            map[i-1850][2]=1+cWeekday-weekDay+bWeek*7;


        if(isLeapyear(i)){
        map[i+1-1850][0]=(map[i-1850][0]+366)%7;
         }
         else{
        map[i+1-1850][0]=(map[i-1850][0]+365)%7;
         }
         if(map[i+1-1850][0] == 0) map[i+1-1850][0] = 7;
    }

    for(int i=year1;i<=year2;i++)
    {
        if(isLeapyear(i))
            yearDay[1] = 29;
        else
            yearDay[1] = 28;
        if(map[i-1850][2]>yearDay[aMonth-1])
        {
            cout<<"none"<<endl;
        }
        else {
        cout<<i<<"/";
        if (aMonth<10) cout<<'0'<<aMonth<<"/";
        else cout<<aMonth<<"/";
        if (map[i-1850][2]<10) cout<<'0'<<map[i-1850][2]<<endl;
        else cout<<map[i-1850][2]<<endl;
    }}
    return 0;
 }
