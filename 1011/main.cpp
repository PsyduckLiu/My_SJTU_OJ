#include <iostream>
#include <iomanip>
using namespace std;

class MyComplex
{
   friend istream& operator >> (istream &in,MyComplex &obj);
   friend ostream& operator << (ostream &os,const MyComplex &obj);

   friend MyComplex operator + (const MyComplex &r1,const MyComplex &r2);
   friend MyComplex operator - (const MyComplex &r1,const MyComplex &r2);

   friend MyComplex operator * (const MyComplex &r1,const MyComplex &r2);
   friend MyComplex operator / (const MyComplex &r1,const MyComplex &r2);
private:
   double x,y;
public:
   MyComplex & operator += (const MyComplex &r1);
   MyComplex & operator -= (const MyComplex &r1);

   MyComplex & operator *= (const MyComplex &r1);
   MyComplex & operator /= (const MyComplex &r1);
};

int main()
{
  MyComplex z1;
  MyComplex z2;

  cin >> z1 >> z2;

  cout << z1 + z2 <<endl;
  cout << z1 - z2 <<endl;
  cout << z1 * z2 <<endl;
  cout << z1 / z2 <<endl;
  cout << (z1 += z2) <<endl;
  cout << (z1 -= z2) <<endl;
  cout << (z1 *= z2) <<endl;
  cout << (z1 /= z2) <<endl;

  return 0;
}
MyComplex operator + (const MyComplex &r1,const MyComplex &r2)
{
    MyComplex tmp;

    tmp.x=r1.x+r2.x;
    tmp.y=r1.y+r2.y;

    return tmp;
}

MyComplex &MyComplex::operator += (const MyComplex &r1)
{

    this->x=r1.x+this->x;
    this->y=r1.y+this->y;

    return *this;
}

MyComplex operator - (const MyComplex &r1,const MyComplex &r2)
{
    MyComplex tmp;

    tmp.x=r1.x-r2.x;
    tmp.y=r1.y-r2.y;

    return tmp;
}

MyComplex &MyComplex::operator -= (const MyComplex &r1)
{

    this->x=this->x-r1.x;
    this->y=this->y-r1.y;

    return *this;
}

MyComplex operator * (const MyComplex &r1,const MyComplex &r2)
{
    MyComplex tmp;

    tmp.x=r1.x*r2.x-r1.y*r2.y;
    tmp.y=r1.x*r2.y+r1.y*r2.x;

    return tmp;
}

MyComplex &MyComplex::operator *= (const MyComplex &r1)
{
    double a,b;
    a=this->x;
    b=this->y;
    this->x=a*r1.x-b*r1.y;
    this->y=a*r1.y+b*r1.x;

    return *this;
}

MyComplex operator / (const MyComplex &r1,const MyComplex &r2)
{
    MyComplex tmp;

    tmp.x=(r1.x*r2.x+r1.y*r2.y)/(r2.x*r2.x+r2.y*r2.y);
    tmp.y=(r2.x*r1.y-r1.x*r2.y)/(r2.x*r2.x+r2.y*r2.y);

    return tmp;
}

MyComplex &MyComplex::operator /= (const MyComplex &r1)
{
    double a,b;
    a=this->x;
    b=this->y;
    this->x=(a*r1.x+b*r1.y)/(r1.x*r1.x+r1.y*r1.y);
    this->y=(r1.x*b-a*r1.y)/(r1.x*r1.x+r1.y*r1.y);

    return *this;
}
istream& operator >> (istream &in,MyComplex &obj)
{
    in>>obj.x>>obj.y;
    return in;
}

ostream& operator << (ostream &os,const MyComplex &obj)
{
    os<<setiosflags(ios::fixed)<<setprecision(2)<<obj.x<<' '<<setiosflags(ios::fixed)<<setprecision(2)<<obj.y;
    return os;
}
