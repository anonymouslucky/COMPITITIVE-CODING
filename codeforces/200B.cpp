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
	
	lli n,i,j,k;
	double ans,num,den;
	
	cin>>n;
	
	num = den = 0.0;
	rep(i,1,n)
	{
		cin>>j;
		num += j;
		den += 100.0;
	}
	
	ans = (num/den)*100;
	
	cout<<fixed<<setprecision(12);
	cout<<ans<<endl;
	return 0;
}
