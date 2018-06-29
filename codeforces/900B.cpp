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
	
	lli a,b,c,q,r,ans=-1;
	unordered_map<lli,bool> m;
	
	cin>>a>>b>>c;
	lli pos=0;
	while(1)
	{
		pos++;
		q = (a*10)/b;r = (a*10)%b;
		if(q == c)
		{
			ans = pos;
			break;
		}
		if(m[r])
			break;
		m[r]=1;
		a=r;
	}
		
	cout<<ans<<endl;
	return 0;
} 
