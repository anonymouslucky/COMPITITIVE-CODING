#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
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
	
	lli n,a,b,c,i,j;
	cin>>n>>a>>b>>c;
	
	lli dp[n+1];
	
	memset(dp,0,sizeof dp);
	if(a<=n)
		dp[a] = 1; 
	if(b<=n)
		dp[b] = 1;
	if(c<=n)
		dp[c]=1;
	
	j = min(a,b);
	j = min(j,c);
	
	rep(i,j,n)
	{
		if(i>=a && dp[i-a]!=0)
			dp[i] = max(dp[i],dp[i-a]+1);
		if(i>=b && dp[i-b]!=0)
			dp[i] = max(dp[i],dp[i-b]+1);
		if(i>=c && dp[i-c]!=0)
			dp[i] = max(dp[i],dp[i-c]+1);	
	}
	
	cout<<dp[n]<<endl;
}
