#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 400010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	lli n,k,even,odd,ans;
	cin>>n>>k;
	
	even = n/2;odd = n-even;
	
	if(k<=odd)
		ans = (2*k-1);
	else
	{
		k-=odd;
		ans = 2*k;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
