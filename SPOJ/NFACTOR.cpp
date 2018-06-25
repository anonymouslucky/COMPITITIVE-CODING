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

bool vis[N];
vector<lli> primes;
lli ans[N][12];


void pre()
{
	memset(vis,0,sizeof vis);
	memset(ans,0,sizeof ans);
	lli i,j,k,n;
	rep(i,2,N-1)
	{
		if(vis[i])
			continue;
		primes.pb(i);
		for(j=i;j<N;j+=i)
			vis[j] = 1;
	}
	
	ans[1][0] = 1;
	rep(i,2,1000000)
	{
		rep(j,0,10)
			ans[i][j] = ans[i-1][j];
		j = 0;k=0;
		n = i;
		while(j<primes.size() && primes[j]<=sqrt(n))
		{
			if(n%primes[j] == 0)
			{
				k+=1;
				while(n%primes[j] == 0)
					n/=primes[j];
			}
			j++;
		}
		
		if(n!=1)
			k+=1;
		if(k<=10)
			ans[i][k] += 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre();
	lli t,l,r,k;
	cin>>t;
	while(t--)
	{
		cin>>l>>r>>k;
		cout<<(ans[r][k]-ans[l-1][k])<<endl;
	}
	
	return 0;
}
