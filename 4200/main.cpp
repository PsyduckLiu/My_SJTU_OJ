#include <iostream>
#include <cstring>
using namespace std;
class Person {
public:
    Person() {}
    bool isLegal(); //判断输入是否合理，合理返回true,否则返回flase
    void read();    //读入居民信息




    char name[6];        //姓名
    char birthday[11];   //生日



};
void Person::read()
{
    cin>>name>>birthday;
}
bool Person::isLegal()
{
    int a=(birthday[0]-'0')*1000+(birthday[1]-'0')*100+(birthday[2]-'0')*10+(birthday[3]-'0')*1;
    int b=(birthday[5]-'0')*10+(birthday[6]-'0')*1;
    int c=(birthday[8]-'0')*10+(birthday[9]-'0')*1;

    if (a<1898||a>2018) return false;
    if (b>12||b<=0) return false;
    if (c<=0||c>31) return false;
    if (b==4||b==6||b==9||b==11) {
        if (c>30) return false;
    }
    if ((a%4==0&&a%100!=0)||a%400==0) {
        if (b==2) {
            if (c>29) return false;
        }
    }
    else {
            if (b==2) {
                if (c>28) return false;}
                }

    if (a==1898) {
        if (b<12) return false;
        else {
            if (c<20) return false;
        }
    }
    if (a==2018) {
        if (b==12) {
            if (c>28) return false;
        }
    }
    return true;
}
class Solution{
public:
    Solution() { count = 0;}
    void regPerson(const Person &person);//统计有效生日人数，以及最年轻与最年长的人
    void displayResult();  //输出相关信息

private:
    char eldestName[6]; //最年长人的姓名
    char eldestBirthday[11]; //最年长人的生日
    char youngestName[6]; //最年轻人的姓名
    char youngestBirthday[11];  //最年轻人的生日
    int count;
    int min1;
    int min2;
    int min3;
    int max1;
    int max2;
    int max3;   //有效生日人数
};
void Solution::displayResult()
{
    cout<<count<<' '<< youngestName<<' '<<eldestName;
}
void Solution::regPerson(const Person &person)
{
    count+=1;
    int a=(person.birthday[0]-'0')*1000+(person.birthday[1]-'0')*100+(person.birthday[2]-'0')*10+(person.birthday[3]-'0')*1;
    int b=(person.birthday[5]-'0')*10+(person.birthday[6]-'0')*1;
    int c=(person.birthday[8]-'0')*10+(person.birthday[9]-'0')*1;
    if (count==1) {
        strcpy(eldestName,person.name);
        strcpy(eldestBirthday,person.birthday);
        strcpy(youngestName,person.name);
        strcpy(youngestBirthday,person.birthday);
        min1=max1=a;
        min2=max2=b;
        min3=max3=c;
    }
    else {
    if (a<min1) {
        strcpy(youngestName,person.name);
        strcpy(youngestBirthday,person.birthday);
        min1=a;
        min2=b;
        min3=c;
    }
    if (a>max1) {
         strcpy(eldestName,person.name);
        strcpy(eldestBirthday,person.birthday);
        max1=a;
        max2=b;
        max3=c;
    }
    if (a==min1) {
        if (b<min2) {
        strcpy(youngestName,person.name);
        strcpy(youngestBirthday,person.birthday);
        min1=a;
        min2=b;
        min3=c;
        }
        if (b==min2) {
            if (c<min3) {
        strcpy(youngestName,person.name);
        strcpy(youngestBirthday,person.birthday);
        min1=a;
        min2=b;
        min3=c;
            }
        }
    }
    if (a==max1) {
        if (b>max2) {
        strcpy(eldestName,person.name);
        strcpy(eldestBirthday,person.birthday);
        max1=a;
        max2=b;
        max3=c;
        }
        if (b==max2) {
            if (c>max3) {
        strcpy(eldestName,person.name);
        strcpy(eldestBirthday,person.birthday);
        max1=a;
        max2=b;
        max3=c;
            }
        }
    }
}}
int main()
{
    Solution solution;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++){
        Person person;
        person.read();
        if (person.isLegal()){
            solution.regPerson(person);
        }
    }
    solution.displayResult();

    return 0;
}
