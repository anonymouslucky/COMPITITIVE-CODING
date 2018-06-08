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
	
	lli n,m,k,i,j;
	lli lower,upper,mid,ans;
	cin>>n>>m>>k;
	
	lower = 1; upper = n*m;
	ans = 0;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		j=0;
		rep(i,1,n)
			j += min((mid-1)/i,m);
		
		if(j<k)
		{
			ans = max(ans,mid);
			lower = mid+1;
		}
		else
			upper = mid-1;
	}
	
	cout<<ans<<endl;
	return 0;
}


