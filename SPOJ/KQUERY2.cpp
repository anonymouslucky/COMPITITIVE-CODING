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
 
const lli blk = 500;
lli BIT[200][10010],a[N];
 
void update(lli i,lli x,lli val)
{
	for(;x<=10000;x+=x&-x)
		BIT[i][x] += val;
}
 
lli query(lli i,lli x)
{
	lli res = 0;
	for(;x>0;x-=x&-x)
		res += BIT[i][x];
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,m,i,j,k,l,r,ans;
	cin>>n;
	rep(i,1,n)
	{
		cin>>a[i];
		update(i/blk,a[i],1);
	}
	
	cin>>m;
	rep(i,1,m)
	{
		cin>>j;
		if(j == 1)
		{
			cin>>l>>r>>k;
			ans = 0;
			while(l%blk!=0 && l<=r)
				ans += (a[l++]>k);
			
			while(r%blk!=blk-1 && l<=r)
				ans += (a[r--]>k);
			
			if(l<r)
			{
				l /= blk; r /= blk;
				for(j=l;j<=r;j++)
					ans += query(j,10000)-query(j,k);
			}
			
			cout<<ans<<endl;
		}
		else
		{
			cin>>j>>k;
			update(j/blk,a[j],-1);
			a[j] = k;
			update(j/blk,a[j],1);
		}
	}
	
	return 0;
} 
