#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#define MAX 1e18
#define SIZE 100010
 
 
using namespace std;
 
lli tree[4*SIZE],A[SIZE];
 
void build(lli node,lli start,lli end)
{
	if(start == end)
	{
		tree[node] = A[start];
	}
	else
	{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}
 
lli query(lli node,lli start,lli end,lli l,lli r)
{
	if(start>end || start>r || end < l)
		return MAX;
	if(start>=l && end<=r)
		return tree[node];
	
	lli mid = (start+end)/2;
	lli val1 = query(2*node,start,mid,l,r);
	lli val2 = query(2*node+1,mid+1,end,l,r);
	return min(val1,val2);
}
 
 
int main()
{
	lli T,i,j,k,l,r,N,Q,cnt = 1;
	
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&N,&Q);
		for(i=1;i<=N;i++)
			scanf("%lld",&A[i]);
		build(1,1,N);
		printf("Scenario #%lld:\n",cnt);
		cnt++;
		while(Q--)
		{
			scanf("%lld%lld",&l,&r);
			if(l>r)
				swap(l,r);
			k = query(1,1,N,l,r);
			printf("%lld\n",k);
		}
	}
	
}
