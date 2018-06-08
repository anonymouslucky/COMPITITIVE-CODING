#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 100010
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
	
	lli i,j,k,n,m,ans = -1;
	lli lower,upper,mid,check;
	
	cin>>n>>m;
	
	lli d[m+1],h[m+1];
	rep(i,1,m)
	{
		cin>>d[i]>>h[i];
		ans = max(ans,h[i]);
	}
	
	d[0] = h[0] = 0;
	
	rep(i,1,m-1)
	{
		k = d[i+1]-d[i];
		lower = h[i] - k;
		upper = h[i] + k;
		lower = max(lower,0ll);
		check = -1;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			j = abs(mid-h[i])+abs(mid-h[i+1]);
			if(j<=k)
			{
				check = max(check,mid);
				lower = mid+1;
			}
			else
				upper = mid-1;
		}
		if(check == -1)
		{
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		ans = max(ans,check);
	}
	
	ans = max(ans,h[1]+d[1]-1);
	ans = max(ans,h[m]+n-d[m]);
	
	
	cout<<ans<<endl;

	return 0;
}


