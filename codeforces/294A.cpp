#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
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
	
	lli n,m,i,j,k,r,c;
	
	cin>>n;
	
	lli a[n+2];
	
	rep(i,1,n)
		cin>>a[i];
		
	cin>>m;
	
	rep(i,1,m)
	{
		cin>>r>>c;
		a[r-1] += c-1;a[r+1] += a[r]-c;
		a[r] = 0;
	}
	
	rep(i,1,n)
		cout<<a[i]<<endl;
}
