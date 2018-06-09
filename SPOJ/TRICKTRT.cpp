#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n,i,j,k;
	long double lower,upper,mid1,mid2,curr1,curr2,ans,d;
	
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		
		long double x[n+1],y[n+1];
		
		rep(i,1,n)
		{
			cin>>x[i]>>y[i];
		}
		
		
		upper = 2e5;
		lower = -upper;
		d = INF; 
		while(upper-lower>tol)
		{
			mid1 = (2*lower+upper)/3.0;
			mid2 = (lower+2*upper)/3.0;
			curr1 = curr2 = 0.0;
			rep(i,1,n)
				curr1 = max(curr1,sqrt(y[i]*y[i]+(x[i]-mid1)*(x[i]-mid1)));
			
			rep(i,1,n)
				curr2 = max(curr2,sqrt(y[i]*y[i]+(x[i]-mid2)*(x[i]-mid2)));
			if(curr1 < curr2)
			{
				upper = mid2;
				if(d>curr1)
				{
					d = curr1;
					ans = mid1;
				}
			}
			else
			{
				lower = mid1;
				if(d>curr2)
				{
					d = curr2;
					ans = mid2;
				}
			}
		}
		
		cout<<fixed<<setprecision(12);
		cout<<ans<<" "<<d<<endl;
	}
	
}
