#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
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
	
	lli k,l,m,n,d,i,j;
	
	cin>>k>>l>>m>>n>>d;
	bool vis[d+1];
	memset(vis,0,sizeof vis);
	
	for(i=k;i<=d;i+=k)
		vis[i] = 1;
	
	for(i=l;i<=d;i+=l)
		vis[i] = 1;
	
	for(i=m;i<=d;i+=m)
		vis[i] = 1;
		
	for(i=n;i<=d;i+=n)
		vis[i] = 1;
	
	j = 0;
	rep(i,1,d)
		if(vis[i])
			j++;
	
	cout<<j<<endl;
	return 0;
}
