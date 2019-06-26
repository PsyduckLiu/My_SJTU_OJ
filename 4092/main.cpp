#include <iostream>
using namespace std;

class Matrix
{
    friend ostream& operator<<(ostream &os,const Matrix &t);
    friend istream& operator>>(istream &in, Matrix &t);




public:
    double **data;
    int row;
    int col;
    double &operator() (int a,int b);
    Matrix &operator+=(const Matrix &r1) ;
    Matrix &operator*=(const Matrix &r2) ;
    Matrix &operator=(const Matrix &t);

};
double &Matrix::operator() (int a,int b)
{
    return data[a][b];
}
Matrix &Matrix::operator+=(const Matrix &r1)
{

    int i,j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            this->data[i][j]=this->data[i][j]+r1.data[i][j];
        }
    }
    return *this;
}
Matrix &Matrix::operator=(const Matrix &t)
{
    int i,j;
    for (i=0; i<row; i++) delete []data[i];
    delete []data;
    row=t.row;
    col=t.col;
    data=new double*[row];
    for (i=0; i<row; i++) data[i]=new double[col];
    for (i=0;i<row;i++) {
        for (j=0;j<col;j++) data[i][j]=t.data[i][j];
    }
    return *this;
}
Matrix &Matrix::operator*=(const Matrix &r2)
{
    Matrix tmp;
    int i,j,k;
    tmp.data=new double*[row];
    for (i=0; i<row; i++)
        tmp.data[i]=new double[col];

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            tmp.data[i][j]=data[i][j];
        }
    }
    tmp.row=row;
    tmp.col=col;

    for (i=0; i<row; i++)
        delete []data[i];
    delete []data;
    col=r2.col;
    data=new double*[row];
    for (i=0; i<row; i++)
        data[i]=new double[r2.col];
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
            data[i][j]=0.0;
    }

    for (i=0; i<tmp.row; i++)
    {
        for (j=0; j<r2.col; j++)
        {
            for (k=0; k<tmp.col; k++)
                data[i][j]+=tmp.data[i][k]*r2.data[k][j];
        }
    }

    return *this;
}
istream &operator>>(istream &in,Matrix &t)
{
    int i,j;
    cin>>t.row>>t.col;
    t.data=new double*[t.row];
    for (i=0; i<t.row; i++)
        t.data[i]=new double[t.col];
    for (i=0; i<t.row; i++)
    {
        for (j=0; j<t.col; j++)
        {
            cin>>t.data[i][j];
        }
    }
    return in;
}
ostream &operator<<(ostream &os,const Matrix &t)
{
    int i,j;
    for (i=0; i<t.row; i++)
    {
        if (i!=0)
            cout<<endl;
        for (j=0; j<t.col; j++)
        {
            cout<<t.data[i][j]<<' ';
        }
    }
    return os;
}
int main()
{
    int i;
    Matrix table1,table2;

    cin>>table1>>table2;
    cout<<table1(table1.row/2,table1.col/2)<<endl;
    cout<<endl;
    if (table1.col!=table2.row)
        cout<<"ERROR!"<<endl;
    else
        cout<<(table1*=table2)<<endl;
    cout<<endl;
    if (table1.row!=table2.row||table1.col!=table2.col)
        cout<<"ERROR!"<<endl;
    else
        cout<<(table1+=table2)<<endl;
    cout<<endl;
    cout<<(table1=table2)<<endl;

    for (i=0; i<table1.row; i++)
        delete []table1.data[i];
    delete []table1.data;
    for (i=0; i<table2.row; i++)
        delete []table2.data[i];
    delete []table2.data;




    return 0;
}
