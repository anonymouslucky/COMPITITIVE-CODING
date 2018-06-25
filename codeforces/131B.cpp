#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  1000010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
#define SIZE 100010
#define SQRSIZE 1000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,i,j,k,l;
	cin>>n;
	
	lli t[21];
	memset(t,0,sizeof t);
	
	rep(i,1,n)
	{
		cin>>j;
		t[10+j]+=1;
	}
	
	lli ans = 0;
	rep(i,-10,-1)
	{
		j = i+10;k = j+2*abs(i);
		ans += t[j]*t[k];
	}
	ans += (t[10]*(t[10]-1))/2;
	cout<<ans<<endl;
	
	return 0;
}
