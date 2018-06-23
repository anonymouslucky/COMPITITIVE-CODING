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

vector<lli> p;
bool vis[110];

void pre()
{
	memset(vis,0,sizeof vis);
	lli i,j;
	rep(i,2,100)
	{
		if(vis[i])
			continue;
		p.pb(i);
		for(j=i;j<=100;j+=i)
			vis[j] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	pre();
	
	lli n,m,i,j;
	cin>>n>>m;
	
	if(!(binary_search(p.begin(),p.end(),n) && binary_search(p.begin(),p.end(),m)))
	{
		cout<<"NO"<<endl;
	}
	else
	{
		i = lower_bound(p.begin(),p.end(),n)-p.begin();
		j = lower_bound(p.begin(),p.end(),m)-p.begin();
		if(i+1==j)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}
