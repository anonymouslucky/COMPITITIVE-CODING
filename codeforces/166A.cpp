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

bool cmp(const P<lli,lli>& p1 , const P<lli,lli>& p2)
{
	if(p1.first > p2.first)
		return 1;
	else if(p1.first == p2.first)
		return p1.second < p2.second;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,k,i,j,left,right,ans;
	lli lower,upper,mid;
	cin>>n>>k;
	
	vector< P<lli,lli> > v(n);
	lli p[n+1],t[n+1];
	
	rep(i,0,n-1)
	{
		cin>>p[i]>>t[i];
		v[i] = mk(p[i],t[i]);
	}
	
	sort(v.begin(),v.end(),cmp);
	
	rep(i,1,n)
	{
		p[i] = v[i-1].first; t[i] = v[i-1].second;
	}
	
	lower = 1; upper = k-1;
	left = k;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		if(p[mid]==p[k] && t[mid]==t[k])
		{
			left = min(left,mid);
			upper = mid-1;
		}
		else
			lower = mid+1;
	}
	
	lower = k+1; upper = n;
	right = k;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		if(p[mid] == p[k] && t[mid]==t[k])
		{
			right = max(right,mid);
			lower = mid+1;
		}
		else
			upper = mid-1;
	}
	
	ans = right-left+1;
	cout<<ans<<endl;
	return 0;
}


