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
	
	lli n,m,i,j,k;
	cin>>n>>m;
	
	lli f[m+1];
	f[0] = 0;
	rep(i,1,m)
		cin>>f[i];
	
	sort(f,f+m+1);
	lli ans = INF;
	rep(i,n,m)
		ans = min(ans,f[i]-f[i-n+1]);
	cout<<ans<<endl;
	
	return 0;
}
