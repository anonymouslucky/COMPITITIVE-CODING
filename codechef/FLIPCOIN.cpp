#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  100010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

class Node
{
	public:
		lli heads,lazy,size;
		void init()
		{
			heads = 0; size = 1; lazy=0;
		}
};

Node tree[4*N];

void build(lli index,lli start,lli end)
{
	if(start == end)
	{
		tree[index].init();
	}
	else
	{
		lli mid = (start+end)>>1;
		build(2*index,start,mid);
		build(2*index+1,mid+1,end);
		tree[index].size = tree[2*index].size+tree[2*index+1].size;
		tree[index].heads = 0;tree[index].lazy = 0;
	}
}

void update(lli index,lli start,lli end,lli l,lli r)
{
	
	tree[index].lazy %= 2;
	if(tree[index].lazy != 0)
	{
		tree[index].heads = tree[index].size-tree[index].heads;
		if(start!=end)
		{
			tree[2*index].lazy += 1;
			tree[2*index+1].lazy += 1;
		}
		tree[index].lazy = 0;
	}
	
	if(start>end || start>r || end<l)
		return;
	
	if(start>=l && end<=r)
	{
		tree[index].heads = tree[index].size-tree[index].heads;
		if(start!=end)
		{
			tree[2*index].lazy += 1;
			tree[2*index+1].lazy += 1;
		}
		tree[index].lazy = 0;
		return;
	}
	
	lli mid = (start+end)>>1;
	update(2*index,start,mid,l,r);
	update(2*index+1,mid+1,end,l,r);
	tree[index].heads = tree[2*index].heads+tree[2*index+1].heads;
}

lli query(lli index,lli start,lli end,lli l,lli r)
{
	tree[index].lazy %= 2;
	if(tree[index].lazy != 0)
	{
		tree[index].heads = tree[index].size-tree[index].heads;
		if(start!=end)
		{
			tree[2*index].lazy += 1;
			tree[2*index+1].lazy += 1;
		}
		tree[index].lazy = 0;
	}
	
	if(start>end || start>r || end<l)
		return 0;
	
	if(start>=l && end<=r)
		return tree[index].heads;
	
	lli mid = (start+end)>>1;
	return query(2*index,start,mid,l,r)+query(2*index+1,mid+1,end,l,r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,q,i,j,k,l,r;
	cin>>n>>q;
	
	build(1,0,n-1);
	
	rep(i,1,q)
	{
		cin>>j>>l>>r;
		if(j == 0)
			update(1,0,n-1,l,r);
		else
		{
			k = query(1,0,n-1,l,r);
			cout<<k<<endl;
		}
	}
	
	return 0;
}
