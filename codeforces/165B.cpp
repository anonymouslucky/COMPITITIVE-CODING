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
	
	lli i,j,k,n,ans=INF;
	lli lower,upper,mid,curr;
	
	cin>>n>>k;
	
	lower = 1; upper = n;
	
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		curr = mid;j = mid;
		while(j>0)
		{
			curr += (j/k);
			j/=k;
		}
		if(curr>=n)
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


