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
	
	lli n,i,j,k;
	lli lower,upper,mid,ans;
	bool valid;
	cin>>n;
	
	lli h[n+1];
	
	lower = upper = 0;
	h[0] = 0;
	rep(i,1,n)
	{
		cin>>h[i];
		upper += h[i];
	}
	
	ans = upper;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		j = mid;valid = 1;
		rep(i,1,n)
		{
			j+=(h[i-1]-h[i]);
			if(j<0)
			{
				valid = 0;
				break;
			}
		}
		
		if(valid)
		{
			ans = min(ans,mid);
			upper = mid-1;
		}	
		else
			lower = mid+1;
	}
	
	cout<<ans<<endl;
	return 0;
}
