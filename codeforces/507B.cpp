#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
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
	
	double r,x,y,x_,y_,d;
	cin>>r>>x>>y>>x_>>y_;
	
	d = sqrt((x-x_)*(x-x_)+(y-y_)*(y-y_));
	d /= (2*r);
	lli ans = ceil(d);
	
	cout<<ans<<endl;
	
	return 0;
}
