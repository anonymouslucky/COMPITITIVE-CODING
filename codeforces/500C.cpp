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
	
	lli n,m,i,j,k;
	cin>>n>>m;
	
	lli b[n+1],day[m+1];
	rep(i,1,n)
		cin>>b[i];
	
	rep(i,1,m)
		cin>>day[i];
		
	unordered_map<lli,bool> pos;
	
	lli ans=0;
	
	rep(i,2,m)
	{
		pos.clear();
		for(j=i-1;j>0;j--)
		{
			if(day[i]==day[j])
				break;
			if(pos.find(day[j])!=pos.end())
				continue;
			ans += b[day[j]];
			pos[day[j]]=1;
		}
	}
	
	cout<<ans<<endl;
	return 0;
} 
