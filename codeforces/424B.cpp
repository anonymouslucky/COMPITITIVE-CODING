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
	
	lli T,n,s,i,j;
	lli required = 1e6;
	cin>>n>>s;
	
	lli x[n+1],y[n+1],k[n+1];
	long double r[n+1],total[n+1],d;
	long double lower,upper,mid,ans;
	lli L,R,m;
	
	multiset< P<long double,lli> > ms;
	P<long double,lli> curr;
	
	rep(i,1,n)
	{
		cin>>x[i]>>y[i]>>k[i];
		r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);
		ms.insert(make_pair(r[i],k[i]));
	}
	
	total[0] = 0.0;
	rep(i,1,n)
	{
		curr = *ms.begin(); ms.erase(ms.begin());
		r[i] = curr.first; k[i] = curr.second;
		total[i] = total[i-1] + k[i];
	}
	
	bool found = 0;
	
	lower=0.0; upper = 2*r[n];
	ans = 2*r[n];
	while(abs(upper-lower)>tol)
	{
		mid = (lower+upper)/2.0;
		L = 1;R = n;
		j = 0;
		while(L<=R)
		{
			m = (L+R)>>1;
			if(r[m]<=mid)
			{
				j = max(j,m);
				L = m+1;
			}
			else
				R = m-1;
		}
		
		if(s+total[j]>=required)
		{
			ans = min(ans,mid);
			upper = mid;
			found=1;
		}
		else
			lower = mid;
	}
	
	
	
	if(!found)
	{
		cout<<"-1"<<endl;
		return 0;
	}


	
	cout<<fixed<<setprecision(16);
	cout<<ans<<endl;
	
	return 0;
}
