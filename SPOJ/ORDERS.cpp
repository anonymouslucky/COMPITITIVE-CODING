#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 200010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

lli n,BIT[N];

void update(lli x,lli val)
{
	for(;x<=n;x+=x&-x)
		BIT[x] += val;
}

lli query(lli x)
{
	lli res = 0;
	for(;x>0;x-=x&-x)
		res += BIT[x];
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli t,i,j,k;
	lli lower,upper,mid;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		lli move[n+1],ans[n+1];
		
		memset(BIT,0,sizeof BIT);
		
		rep(i,1,n)
			update(i,1);
		
		rep(i,1,n)
			cin>>move[i];
		
		repr(i,n,1)
		{
			lower = 1;upper = n;
			k = query(n);
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				j = k-query(mid);
				if(j > move[i])
				{
					lower = mid+1;
				}
				else
				{
					upper = mid-1;
					ans[i] = mid;
				}
			}
			update(ans[i],-1);
		}
		
		rep(i,1,n)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
