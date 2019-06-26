#include <iostream>
#include <iomanip>
 
using namespace std;
 
int m,n,p[250000];
long long int v;
 
void QuickSort(int start, int last);
 
int main()
{
    int i,block=0;
    double level,prop;
    cin>>m>>n;
 
    for(i=0;i<m*n;i++)
    {
        cin>>p[i];
    }
    cin>>v;
 
    QuickSort(0,m*n-1);
    i=0;
    while(v>(long long)(p[i+1]-p[i])*(block+1)&&i<m*n-1)
    {
        block++;
        v-=(long long)(p[i+1]-p[i])*block;
        i++;
    }
    block++;
    level=p[i]+(double)v/(block);
    prop=(double)block/(m*n)*100;
    cout<<fixed<<setprecision(2)<<level<<'\n'<<prop;
    return 0;
}
 
void QuickSort(int start, int last)
{
    int i=start;
    int j=last;
    int temp=p[i];
    if (i<j)
    {
        while(i<j)
        {
            while(i<j&&p[j]>=temp)
                j--;
            if(i<j)
            {
                p[i]=p[j];
                i++;
            }
            while (i<j&&temp>p[i])
                i++;
            if (i<j)
            {
                p[j]=p[i];
                j--;
            }
        }
        p[i] = temp;
        QuickSort(start, i - 1);
        QuickSort(i + 1, last);
    }
}
