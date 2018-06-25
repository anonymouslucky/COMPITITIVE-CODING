#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  10000010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

lli tree[4*N],lazy[4*N];

void update(lli index,lli start,lli end,lli l,lli r)
{
	if(lazy[index]!=0)
	{
		tree[index] += lazy[index];
		if(start!=end)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(start>end || start>r || end<l)
		return;
	
	if(start>=l && end<=r)
	{
		tree[index] += 1;
		if(start!=end)
		{
			lazy[2*index] += 1;
			lazy[2*index+1] += 1;
		}
		lazy[index] = 0;
		return;
	}
	
	lli mid = (start+end)>>1;
	update(2*index,start,mid,l,r);
	update(2*index+1,mid+1,end,l,r);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

lli query(lli index,lli start,lli end,lli l,lli r)
{
	if(lazy[index]!=0)
	{
		tree[index] += lazy[index];
		if(start!=end)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(start>end || start>r || end<l)
		return INF;
	
	if(start>=l && end<=r)
		return tree[index];
		
	lli mid = (start+end)>>1;
	return min(query(2*index,start,mid,l,r),query(2*index+1,mid+1,end,l,r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	lli t,n,i,j,k,l,r,ans;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		memset(tree,0,sizeof tree); 
		memset(lazy,0,sizeof lazy);
		
		lli L[n+1],R[n+1];
		k =0;
		rep(i,1,n)
		{
			cin>>L[i]>>R[i];
			k = max(k,R[i]);
		}
		
		ans = 0;
		repr(i,n,1)
		{
			l = L[i]; r = R[i];
			j = query(1,1,k,l,r);
			if(j == 0)
				ans++;
			update(1,1,k,l,r);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
