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
	
	lli n,x,i,j,k,ans=0;
	cin>>n>>x;
	
	lli num[n];
	rep(i,0,n-1)
		cin>>num[i];
	
	unordered_map<lli,lli> m;
	
	rep(i,0,n-1)
	{
		if(m.find(num[i]^x)!=m.end())
			ans+=m[num[i]^x];
		m[num[i]]+=1;
	}
	cout<<ans<<endl;
	return 0;
} 
