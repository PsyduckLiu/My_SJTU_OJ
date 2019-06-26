#include <iostream>
 
using namespace std;
int divide(long long int a[],int low,int high)
{
    int k=a[low];
    do{
    while (low<high&&a[high]>=k) --high;
    if (low<high) {a[low]=a[high];++low;}
    while (low<high&&a[low]<=k) ++low;
    if (low<high) {a[high]=a[low];--high;}
    }while (low!=high);
    a[low]=k;
    return low;
}
void quicksort(long long int a[],int low,int high)
{
    int mid;
    if (low>=high) return;
    mid=divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}
int main()
{
    long long int *a,*b,max=0,min=0;
    int n,i;
    cin>>n;
    a=new long long int [n];
    b=new long long int [n];
    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<n;i++) cin>>b[i];
    quicksort(a,0,n-1);
    quicksort(b,0,n-1);
    for (i=0;i<n;i++) max+=a[i]*b[i];
    for (i=0;i<n;i++) min+=a[i]*b[n-1-i];
    cout<<max<<" "<<min;
 
    delete [] a;
    delete [] b;
    return 0;
}
