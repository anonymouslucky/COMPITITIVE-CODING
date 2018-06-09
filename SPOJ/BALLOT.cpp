#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

bool cmp(const P<lli,lli>& p1 , const P<lli,lli>& p2)
{
	if(p1.first < p2.first)
		return 1;
	else if(p1.first == p2.first)
		return p1.second < p2.second;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli i,j,k,n,b;
	lli lower,upper,mid,curr,ans;
	
	while(1)
	{
		cin>>n>>b;
		if(n == -1 && b==-1)
			break;
		
		lli a[n+1];
		
		rep(i,1,n)
			cin>>a[i];
		
		lower = 1; upper = 5e6;
		ans =INF;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			curr = 0;
			rep(i,1,n)
				curr += ceil((double)a[i]/(double)mid);
			
			if(curr<=b)
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
