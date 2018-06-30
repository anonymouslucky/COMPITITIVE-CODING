#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  5000010
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
	
	lli i,a,b,n,ans=-1;
	cin>>a>>b>>n;
	
	for(i=0;i<=9;i++)
	{
		if((a*10+i)%b==0)
		{
			ans = a*10+i;
		}
	}
	
	if(ans == -1)
	{
		cout<<ans<<endl;
		return 0;
	}
	
	cout<<ans;
	rep(i,1,n-1)
		cout<<"0";
	
	return 0;
} 
