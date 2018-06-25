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
	
	ULL x,y,a,b;
	cin>>x>>y>>a>>b;
	
	ULL lcm = (x*y)/__gcd(x,y);
	
	a = ceil((double)a/(double)lcm)*lcm;
	b = (b/lcm)*lcm;
	
	if(a>b)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	ULL ans = (b-a)/lcm+1;
	
	cout<<ans<<endl;
	return 0;
}
