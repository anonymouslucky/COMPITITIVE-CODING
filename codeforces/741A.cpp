#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  1000010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
#define SIZE 100010
#define SQRSIZE 1000

using namespace std;

vector<lli> adj[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,i,j,k,l;
	cin>>n;
	
	lli a[n+1];
	
	rep(i,1,n)
	{
		cin>>a[i];
		adj[i].pb(a[i]);
	}
	
	bool vis[n+1];
	memset(vis,0,sizeof vis);
	
	queue<lli> q;
	bool valid = 1;
	lli ans = 1;
	rep(i,1,n)
	{
		if(vis[i])
			continue;
		q.push(i);
		vis[i] = 1;
		k = 0;
		while(!q.empty())
		{
			j = q.front(); q.pop();
			k+=1;
			if(!vis[adj[j][0]])
			{
				vis[adj[j][0]] = 1;
				q.push(adj[j][0]);
			}
			else
			{
				l = adj[j][0];
			}
		}
		if(l!=i)
		{
			valid = 0;
			break;
		}
		if(k%2==0)
			k/=2;
		ans = (ans*k)/__gcd(ans,k);
	}
	
	if(!valid)
	{
		cout<<"-1"<<endl;
	}
	else
		cout<<ans<<endl;
	return 0;
}
