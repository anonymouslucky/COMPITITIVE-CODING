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

vector<lli> adj[N];
bool vis[N];
lli dp[N][2];

void dfs(lli s)
{
	vis[s] = 1;
	lli i,v;
	dp[s][0] = 0;
	dp[s][1] = 1;
	rep(i,0,adj[s].size()-1)
	{
		v = adj[s][i];
		if(!vis[v])
		{
			dfs(v);
			dp[s][0] += dp[v][1];
			dp[s][1] += min(dp[v][0],dp[v][1]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,i,j,k,u,v,w;
	cin>>n;
	
	rep(i,1,n-1)
	{
		cin>>u>>v;
		adj[u].pb(v);adj[v].pb(u);
	}
	
	
	dfs(1);
	cout<<min(dp[1][0],dp[1][1])<<endl;
	
	return 0;
}
