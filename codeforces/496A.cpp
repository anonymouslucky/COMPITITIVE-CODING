#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
#define mod 1000000007
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
	
	lli i,j,k,n,ans = INF;
	cin>>n;
	
	lli h[n+1];
	h[0] = 0;
	rep(i,1,n)
		cin>>h[i];
		
	rep(i,2,n-1)
	{
		if(ans > h[i+1]-h[i-1])
		{
			ans = h[i+1]-h[i-1];
			j = i;
		}
	}
	h[j] = 0;
	sort(h,h+n+1);
	
	ans = 0;
	rep(i,2,n-1)
	{
		ans = max(ans,h[i+1]-h[i]);
	}
	
	cout<<ans<<endl;
	return 0;
}
