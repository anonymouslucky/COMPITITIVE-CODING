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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	lli n,i,j,k,curr;
	lli lower,upper,mid,ans = -INF;
	bool valid;
	
	cin>>n;
	
	lli c[n+1],d[n+1];
	rep(i,1,n)
		cin>>c[i]>>d[i];
	
	lower = -INF; upper = INF;
	
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		
		curr = mid;
		valid = 1;
		repr(i,n,1)
		{
			curr -= c[i];
			j = curr<1900?2:1;
			if(j!=d[i])
			{
				valid = 0;
				break;
			}
		}
		
		if(!valid)
		{
			if(j == 1)
				upper = mid-1;
			else
				lower = mid+1;
		}
		else
		{
			lower = mid+1;
			ans = max(ans,mid);
		}
		
	}
	
	if(ans == INF)
		cout<<"Infinity"<<endl;
	else if(ans == -INF)
		cout<<"Impossible"<<endl;
	else
		cout<<ans<<endl;
	return 0;
}


