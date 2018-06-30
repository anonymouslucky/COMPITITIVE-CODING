#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  5000010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

lli small_div[N];
lli ans[N];

void pre()
{
	lli i,j,k;
	rep(i,2,N-1)
	{
		if(small_div[i]!=0)
			continue;
		for(j=i;j<N;j+=i)
		{
			if(small_div[j]==0)
				small_div[j]=i;
		}
	}
	
	ans[1]=0;
	rep(i,2,N-1)
		ans[i] = 1+ans[i/small_div[i]];
	
	rep(i,2,N-1)
		ans[i] += ans[i-1];
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	pre();
	
	
	lli t,a,b;
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",ans[a]-ans[b]);
	}
	
	return 0;
} 
