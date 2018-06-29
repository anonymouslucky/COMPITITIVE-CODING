#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  30010
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
	
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	
	double ans = (double)(a*d)/(double)(b*d-(b-a)*(d-c));
	
	cout<<fixed<<setprecision(16);
	cout<<ans<<endl;
	
	return 0;
} 
