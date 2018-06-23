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
	
	lli n,m,i,j,k,b,g;
	
	cin>>n>>m;
	
	k = __gcd(n,m);
	bool vis[k+1];
	memset(vis,0,sizeof vis);
	
	cin>>b;
	
	rep(i,1,b)
	{
		cin>>j;
		vis[j%k] = 1;
	}
	
	cin>>g;
	
	rep(i,1,g)
	{
		cin>>j;
		vis[j%k] = 1;
	}

	bool valid = 1;
	
	rep(i,0,k-1)
	{
		if(!vis[i])
			valid = 0;	
	}	
	if(valid)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
