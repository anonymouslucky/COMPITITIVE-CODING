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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	lli a,b,c,d,t,i,j,ans = INF;
	cin>>a>>b>>c>>d;
	
	rep(i,0,100)
	{
		rep(j,0,100)
		{
			if(b+i*a == d+j*c)
				ans = min(ans,b+i*a);
		}
	}
	
	if(ans == INF)
		ans = -1;
	
	cout<<ans<<endl;
	return 0;
}
