#include <iostream>
 
using namespace std;
 
int m,n;
 
int ass[1000000];
 
int sum1[1000000]; 
 
 
 
int binarysearch(int high,int low,int m,int n)
 
{
 
	int l=low;
 
	int r=high;
 
	int mid;
 
	int ans;
 
	while (l<r)
 
	{
 
		mid=(l+r)/2;
 
		bool flag=true;
 
		int sum=0;
 
		int count=1;
 
		int maxsum=0;
 
		for (int i=0;i<m;i++)
 
		{
 
			if (ass[i]>mid)
 
			{
 
				flag=false;
 
				break;
 
			}
 
			sum+=ass[i];
 
			if (sum>mid)
 
			{
 
				maxsum=max(sum-ass[i],maxsum);
 
				count+=1;
 
				sum=ass[i];
 
			}
 
 
 
		}
 
		if (!flag || count>n)
 
		{
 
			l=mid+1;
 
		}
 
		else {r=mid;ans=maxsum;}
 
	}
 
	mid=(l+r)/2;
 
	return mid;
 
}
 
int main(int argc, char const *argv[])
 
{
 
	cin>>m>>n;
 
	int sum=0;
 
	for (int i=0;i<m;i++)
 
	{
 
		cin>>ass[i];
 
		sum+=ass[i];
 
	}
 
	cout<<binarysearch(sum,0,m,n); 
 
	return 0;
 
}
