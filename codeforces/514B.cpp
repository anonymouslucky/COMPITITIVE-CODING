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
	
	lli n,x0,y0,x,y,i;
	double m;
	map<double,bool> ms;
	cin>>n>>x0>>y0;
	
	rep(i,1,n)
	{
		cin>>x>>y;
		if(x == x0)
			m = INF;
		else
			m = (double)(y-y0)/(double)(x-x0);
		ms[m]=1;
	}
	
	lli ans = ms.size();
	cout<<ans<<endl;
	return 0;
}
