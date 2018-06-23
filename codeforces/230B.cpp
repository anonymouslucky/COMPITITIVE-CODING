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

map<lli,bool> T;
bool vis[1000010];

void pre()
{
	memset(vis,0,sizeof vis);
	lli i,j;
	rep(i,2,1000000)
	{
		if(vis[i])
			continue;
		T[i*i] = 1;
		for(j=i;j<=1000000;j+=i)
			vis[j] = 1;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	pre();
	lli i,j,k,n;
	
	cin>>n;
	
	rep(i,1,n)
	{
		cin>>j;
		if(T[j])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
}
