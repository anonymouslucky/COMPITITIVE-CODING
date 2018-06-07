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

	lli n,k,i,j;
	
	string str;
	
	cin>>k;
	cin>>str;
	n = str.length();
	
	lli freq[n+1];
	memset(freq,0,sizeof freq);
	
	freq[0] = 0;
	rep(i,1,n)
		freq[i] = freq[i-1] + (bool)(str[i-1]=='1');
	
	lli ans = 0;
	
	rep(i,1,n)
	{
		j = (upper_bound(freq,freq+i,freq[i]-k)-lower_bound(freq,freq+i,freq[i]-k));
		ans += j;
	}
	
	cout<<ans<<endl;
	return 0;
}


