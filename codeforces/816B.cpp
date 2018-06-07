
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

	lli n,k,q,i,j;
	
	cin>>n>>k>>q;
	
	lli l[n+1],r[n+1];
	
	memset(freq,0,sizeof freq);
	
	rep(i,1,n)
	{
		cin>>l[i]>>r[i];
		freq[l[i]] += 1;freq[r[i]+1]-=1;
	}
	
	rep(i,1,200001)
		freq[i] += freq[i-1];
	
	rep(i,1,200001)
	{
		freq[i] = freq[i]>=k?1:0;
		freq[i] += freq[i-1];
	}
		
	while(q--)
	{
		cin>>i>>j;
		cout<<(freq[j]-freq[i-1])<<endl;
	}
	
	
	return 0;
}
