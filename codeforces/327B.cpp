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

bool vis[N];
lli p[100010];

void pre()
{
	memset(vis,0,sizeof vis);
	lli i,j,index=1;
	for(i=2;i<N;i++)
	{
		if(vis[i])
			continue;
		p[index++] = i;
		for(j=i;j<N;j+=i)
			vis[j] = 1;
		if(index>100000)
			break;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	pre();
	
	lli n,i;
	cin>>n;
	
	rep(i,1,n)
		cout<<p[i]<<" ";
	
	return 0;
}
