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
	
	lli T,i,j,k,l,n,p,ans;
	lli lower,upper,mid,curr;
	
	lli r[9][1010];
	
	rep(i,1,8)
	{
		r[i][0] = 0;
		rep(j,1,1009)
		{
			r[i][j] = r[i][j-1]+i*j;
		}
	}
	
	cin>>T;
	
	
	//freopen("output.txt","w",stdout);
	while(T--)
	{
		cin>>p;
		cin>>l;
		lli t[l+1];
		rep(i,1,l)
			cin>>t[i];
		
		lower = 0; upper = 10000000;
		ans = upper;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			curr = 0;
			rep(i,1,l)
			{
				j = lower_bound(r[t[i]],r[t[i]]+1010,mid)-r[t[i]];
				if(r[t[i]][j] > mid)
					j--;
				curr += j;
			}
			if(curr >= p)
			{
				ans = min(ans,mid);
				upper = mid-1;
			}
			else
				lower = mid+1;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
