#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  20010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

lli tree[4*N],A[N],ans[N];
const lli inf = pow(2,32)-1;

void build(lli index,lli start,lli end)
{
	if(start == end)
		tree[index] = A[start];
	else
	{
		lli mid = (start+end)>>1;
		build(2*index,start,mid);
		build(2*index+1,mid+1,end);
		tree[index] = tree[2*index]&tree[2*index+1];
	}
}

lli query(lli index,lli start,lli end,lli l,lli r)
{
	if(start > end || start>r || end<l)
		return inf;
	
	if(start>=l && end<=r)
		return tree[index];
	
	lli mid = (start+end)>>1;		
	lli left = query(2*index,start,mid,l,r);
	lli right = query(2*index+1,mid+1,end,l,r);
	return (left&right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli t,n,k,i,j,l,r;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		rep(i,0,n-1)
			cin>>A[i];
		
		build(1,0,n-1);
		
		if(k>=(n/2))
		{
			j = query(1,0,n-1,0,n-1);
			rep(i,0,n-1)
				ans[i] = j;
		}
		else
		{
			rep(i,0,n-1)
			{
				l = (i-k+n)%n;r = (i+k)%n;
				if(l<=r)
					ans[i] = query(1,0,n-1,l,r);
				else
					ans[i] = query(1,0,n-1,0,r)&query(1,0,n-1,l,n-1);
			}
		}
		
		rep(i,0,n-1)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}
