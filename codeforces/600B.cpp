#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
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
	
	lli i,j,k,n,m;
	lli lower,upper,mid,ans;
	cin>>n>>m;
	
	lli a[n],b[m];
	
	rep(i,0,n-1)
		cin>>a[i];
	rep(i,0,m-1)
		cin>>b[i];
	
	sort(a,a+n);
	
	rep(i,0,m-1)
	{
		if(b[i]<a[0])
		{
			cout<<"0 ";
			continue;
		}
		
		if(b[i]>=a[n-1])
		{
			cout<<n<<" ";
			continue;
		}
		
		lower = 0;upper=n-1;
		ans = 0;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			if(a[mid]<=b[i])
			{
				ans = max(ans,mid+1);
				lower = mid+1;
			}
			else
				upper = mid-1;
		}
		cout<<ans<<" ";
	}
	
	
	
	return 0;
}


