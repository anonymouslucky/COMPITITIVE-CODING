#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
 
using namespace std;

lli freq[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string t,p;
	lli n,m,i,j,k;
	lli lower,upper,mid,ans=0;
	
	cin>>t;
	cin>>p;
	
	n = t.length();m=p.length();
	lli a[n+1];
	bool visited[n+1];
	
	rep(i,1,n)
		cin>>a[i];
		
	lower = 0;upper=n;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		
		memset(visited,0,sizeof visited);
		rep(i,1,mid)
		{
			visited[a[i]] = 1;
		}
		
		j = 0;
		rep(i,1,n)
		{
			if(j == m)
				break;
			if(!visited[i] && t[i-1] == p[j])
				j++;
		}
		
		if(j == m)
		{
			lower = mid+1;
			ans = max(ans,mid);
		}
		else
			upper = mid-1;
	}
	
	cout<<ans<<endl;
	return 0;
}
