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

bool cmp(const P<lli,lli>& p1 , const P<lli,lli>& p2)
{
	if(p1.first < p2.first)
		return 1;
	else if(p1.first == p2.first)
		return p1.second < p2.second;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli i,j,k,n;
	lli lower,upper,mid,ans,freq;
	
	cin>>n>>k;
	lli a[n+1],sum[n+1];
	
	a[0] = -INF;
	sum[0] = 0;
	rep(i,1,n)
		cin>>a[i];
	
	sort(a,a+n+1);
	rep(i,1,n)
		sum[i] = sum[i-1]+a[i];
	
	
	freq = 0; ans = 0;
	rep(i,1,n)
	{
		lower = 1;upper = i;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			j = i-mid+1;
			if(j*a[i]-sum[i]+sum[mid-1] <= k)
			{
				upper = mid-1;
				if(freq < j)
				{
					freq = j;
					ans = a[i];
				}
			}
			else
				lower = mid+1;
		}
	}
	
	cout<<freq<<" "<<ans<<endl;
	return 0;
}
