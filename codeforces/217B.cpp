#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
 
using namespace std;

vector<lli> primes;
bool vis[2*N];

void pre()
{
	lli i,j;
	memset(vis,0,sizeof vis);
	rep(i,2,2*N-1)
	{
		if(vis[i])
			continue;
		primes.pb(i);
		for(j=i;j<2*N;j+=i)
			vis[j] = 1;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	pre();
	
	lli n,m,i,j,k;
	
	cin>>n>>m;
	
	lli grid[n+1][m+1];
	
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			cin>>k;
			grid[i][j] = *lower_bound(primes.begin(),primes.end(),k);
			grid[i][j] -= k;
		}
	}
	
	lli ans = INF;
	
	rep(i,1,n)
	{
		k = 0;
		rep(j,1,m)
			k += grid[i][j];
		ans = min(ans,k);
	}
	
	rep(j,1,m)
	{
		k=0;
		rep(i,1,n)
			k += grid[i][j];
		ans = min(ans,k);
	}
	
	
	cout<<ans<<endl;
	return 0;
}


