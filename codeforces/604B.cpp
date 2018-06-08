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
	
	lli n,k,i,j,curr;
	lli lower,upper,mid,ans = INF;
	bool valid;
	
	cin>>n>>k;
	
	lli s[n+1],v[k+1];
	
	rep(i,1,n)
		cin>>s[i];
		
		
	if(k>=n)
	{
		cout<<s[n]<<endl;
		return 0;
	}
	
	lower = 1; upper = 2e6;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		
		if(s[n] > mid)
		{
			lower = mid+1;
			continue;
		}
		
		j = 1;
		repr(i,n,n-k+1)
		{
			v[j] = mid-s[i];j++;
		}
		
		i = 1;j = 1;
		while(i<=n-k && j<=k)
		{
			if(s[i]<=v[j])
				i++;
			j++;
		}
		
		if(i == n-k+1)
		{
			ans = min(ans,mid);
			upper = mid-1;
		}
		else
			lower = mid+1;
	}
	
	cout<<ans<<endl;
	
	return 0;
}


