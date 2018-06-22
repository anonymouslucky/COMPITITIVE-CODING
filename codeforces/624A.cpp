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
	
	double d,l,i,j,k,v1,v2,ans;
	
	cin>>d>>l>>v1>>v2;
	
	ans = (l-d)/(v1+v2);
	cout<<fixed<<setprecision(18);
	cout<<ans<<endl;
	return 0;
}
