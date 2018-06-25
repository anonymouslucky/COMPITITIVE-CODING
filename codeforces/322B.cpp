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
	
	lli r,g,b,i,j,k;
	cin>>r>>g>>b;
	
	lli ans = r/3 + g/3 + b/3;
	i = min(r,min(g,b));
	
	if(i>=1)
		ans =  max(ans , 1+(r-1)/3+(g-1)/3+(b-1)/3);
	
	if(i>=2)
		ans = max(ans ,2+(r-2)/3+(g-2)/3+(b-2)/3);
	
	
	cout<<ans<<endl;
	
	return 0;
}
