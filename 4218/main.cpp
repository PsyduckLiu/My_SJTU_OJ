#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;


int *dq1;
int *dq2;
int *le;
int *ri;
int *a;
int n,d,front1,tail1,front2,tail2,ans;
int l,r;

void dandiao1()
{
    int i;
    for(i = 0 ; i < d; ++i)

		{

			while(front1 <= tail1 && a[ dq1[tail1] ] <= a[i])
				--tail1;

			dq1[ ++tail1 ] = i;
		}
		l=0;
        le[l]=a[dq1[front1]];

		for(i=d ; i < n ; ++i)
        {

			while(front1 <= tail1 && a[ dq1[tail1] ] <= a[i])

				--tail1;

			dq1[ ++tail1 ] = i;

			while(dq1[ front1 ] <= i - d)

				++front1;
            if(i != n-1) le[++l]=a[dq1[front1]];

		}
         le[++l]=a[dq1[front1]];

         for (i=n-d+1;i<=n-2;i++) le[i]=*max(a+i+1,a+n-1);
         le[n-1]=0;

}
void dandiao2()
{
    int i;
    for(i = n-1 ; i >=n-d; --i)

		{

			while(front2 >= tail2 && a[ dq2[tail2] ] <= a[i])
				++tail2;

			dq2[ --tail2 ] = i;
		}
        r=n-1;
        ri[r]=a[dq2[front2]];
        for(i=n-d-1 ; i >= 0 ; --i)
        {

			while(front2 >= tail2 && a[ dq2[tail2] ] <= a[i])

				++tail2;

			dq2[ --tail2 ] = i;

			while(dq2[ front2 ] >= i+d)

				--front2;
           if (i!=n-1) ri[--r]=a[dq2[front2]];

		}
         ri[--r]=a[dq2[front2]];

         for (i=d-2;i>=1;i--) ri[i]=*max(a+0,a+i-1);
         ri[0]=0;
}

int main()

{

	int i;
	cin>>n>>d;
	dq1=new int[n];
	dq2=new int[n];
	le=new int[n];
	ri=new int[n];
	a=new int[n];

    for(i = 0 ; i < n ; ++i)  cin>>a[i];
    front1 = 0;
    tail1 = -1;
    front2 = n-1;
    tail2 = n;
    ans=0;
    dandiao1();
    dandiao2();
     for (i=0;i<n;i++) {

        if (le[i]>2*a[i]||ri[i]>2*a[i]) ans++;
     }

     cout<<ans;
	return 0;

}
