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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,i,j,k;
	
	cin>>n;
	
	priority_queue<lli> pq;
	unordered_map<lli,lli> m;
	
	rep(i,1,n*n)
	{
		cin>>j;
		pq.push(j);
		m[j]++;
	}
	
	lli ans[n];
	i=0;
	while(!pq.empty())
	{
		j = pq.top();pq.pop();
		if(m[j] == 0)
			continue;
		ans[i]=j;
		for(k=0;k<i;k++)
			m[__gcd(ans[i],ans[k])]-=2;
		m[j]-=1;
		i++;
	}
	
	rep(i,0,n-1)
		cout<<ans[i]<<" ";
	
	return 0;
} 
