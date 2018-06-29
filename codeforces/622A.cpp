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
	
	lli n,i,j,k,ans;
	lli lower,upper,mid;
	cin>>n;
	
	lower = 0;upper = 1e8;
	ans=0;j=0;
	while(lower<=upper)
	{
		mid = (lower+upper)>>1;
		k = (mid*(mid+1))/2;
		if(k<=n)
		{
			ans = max(ans,k);
			j=max(j,mid);
			lower = mid+1;
		}
		else
			upper = mid-1;
	}
	
	if(n == ans)
		cout<<j<<endl;
	else
		cout<<(n-ans)<<endl;
	
	return 0;
} 
