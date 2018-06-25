#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#define MAX 1e18
#define SIZE 100010
 
 
using namespace std;
 
class Node
{
	public:
		lli on,size;
		void init(lli i)
		{
			on = i;
			size = 1;
		}
		void infi()
		{
			on = 0;
			size = 0;
		}
		
		void merge(Node left,Node right)
		{
			on = left.on + right.on;
			size = left.size + right.size;
		}
		
		void reverse()
		{
			on = size-on;
		}
};
 
 
Node tree[4*SIZE];
lli lazy[4*SIZE];
 
void build(lli node,lli start,lli end)
{
	if(start == end)
	{
		tree[node].init(0);
	}
	else
	{
		lli mid = (start+end)/2;
		build(2*node , start,mid);
		build(2*node+1 , mid+1 , end);
		tree[node].merge(tree[2*node],tree[2*node+1]);
	}
}
 
void update(lli node , lli start , lli end,lli l,lli r)
{
	lazy[node]%=2;
	if(lazy[node]!=0)
	{
		tree[node].reverse();
		if(start!=end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > end || start>r || end<l)
		return;
	
	if(start>=l && end<=r)
	{
		tree[node].reverse();
		if(start!=end)
		{
			lazy[2*node] += 1;
			lazy[2*node+1] += 1;
		}
		lazy[node] = 0;
		return;
	}
	
	lli mid = (start+end)/2;
	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);
	tree[node].merge(tree[2*node],tree[2*node+1]);
}
 
Node query(lli node,lli start,lli end,lli l,lli r)
{
	Node result;
	if(start>end  || start > r || end<l)
	{
		result.infi();
		return result;
	}
	
	lazy[node]%=2;
	if(lazy[node]!=0)
	{
		tree[node].reverse();
		if(start!=end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start>=l && end<=r)
		return tree[node];
	
	lli mid = (start+end)/2;
	Node left = query(2*node,start,mid,l,r);
	Node right = query(2*node+1,mid+1,end,l,r);
	result.merge(left,right);
	return result;
}
 
 
int main()
{
	lli Q,i,j,k,l,r,x,N;
	Node result;
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>N>>Q;
	build(1,1,N);
	memset(lazy,0,sizeof lazy);
	
	while(Q--)
	{
		cin>>i>>l>>r;
		if(i == 0)
		{
			update(1,1,N,l,r);
		}
		else
		{
			result = query(1,1,N,l,r);
			cout<<result.on<<endl;
		}
		
	}
	
}
