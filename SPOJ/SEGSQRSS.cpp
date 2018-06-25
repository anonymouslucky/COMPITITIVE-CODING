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
	lli sum,square,size;
	void init(lli i)
	{
		sum = i;square = i*i;size = 1;
	}
	
	void infi()
	{
		sum = square = size = 0;
	}
	
	void merge(Node left,Node right)
	{
		sum = left.sum + right.sum;
		square = left.square + right.square;
		size = left.size + right.size;
	}
		
};
 
 
Node tree[4*SIZE];
lli state[4*SIZE],lazy[4*SIZE],A[SIZE];
 
void build(lli node,lli start,lli end)
{
	if(start == end)
	{
		tree[node].init(A[start]);
	}
	else
	{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].merge(tree[2*node],tree[2*node+1]);
	}
}
 
void update(lli node,lli start,lli end,lli l,lli r,lli val,lli type)
{
	if(lazy[node]!=0)
	{
		if(state[node] == 0)
		{
			tree[node].square += tree[node].size *(lazy[node]*lazy[node]) + 2*lazy[node]*tree[node].sum;
			tree[node].sum += (tree[node].size*lazy[node]);
			if(start!=end)
			{
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
		}
		else
		{
			tree[node].sum = tree[node].size*lazy[node];
			tree[node].square = tree[node].size*(lazy[node]*lazy[node]);
			if(start!=end)
			{
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node];
				state[2*node] = state[2*node+1] = 1;
			}
		}
		lazy[node] = 0;
		state[node] = 0;
	}
	
	
	if(start > end or end < l or start>r){
		return ;
	}
	
	if(start>=l && end<=r){
		if(type == 0)
		{
			tree[node].square += tree[node].size *(val*val) + 2*val*tree[node].sum;
			tree[node].sum += (tree[node].size*val);
			if(start!=end)
			{
				lazy[2*node] += val;
				lazy[2*node+1] += val;
			}
		}
		else
		{
			tree[node].sum = tree[node].size*val;
			tree[node].square = tree[node].size*(val*val);
			if(start!=end)
			{
				lazy[2*node] = val;
				lazy[2*node+1] = val;
				state[2*node] = state[2*node+1] = 1;
			}
		}
		state[node] = 0;
		return;
	}
	lli mid = (start+end)/2;
	
	update(2*node,start,mid,l,r,val,type);
	update(2*node+1,mid+1,end,l,r,val,type);
	
	tree[node].merge(tree[2*node],tree[2*node+1]);
}
 
Node query(lli node,lli start,lli end,lli l,lli r)
{
	Node n;
	if(start > end or end < l or start>r){
		n.infi();
		return n;
	}
	
	
	if(lazy[node]!=0)
	{
		if(state[node] == 0)
		{
			tree[node].square += tree[node].size *(lazy[node]*lazy[node]) + 2*lazy[node]*tree[node].sum;
			tree[node].sum += (tree[node].size*lazy[node]);
			if(start!=end)
			{
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
		}
		else
		{
			tree[node].sum = tree[node].size*lazy[node];
			tree[node].square = tree[node].size*(lazy[node]*lazy[node]);
			if(start!=end)
			{
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node];
				state[2*node] = state[2*node+1] = 1;
			}
		}
		lazy[node] = 0;
		state[node] = 0;
	}
	
	if(start >= l && end<=r)
	{
		return tree[node];
	}
	
	lli mid = (start+end)/2;
	Node left = query(2*node,start,mid,l,r);
	Node right = query(2*node+1,mid+1,end,l,r);
	n.merge(left,right);
	return n;
}
 
 
 
int main()
{
	lli T,N,Q,l,r,i,j,k,cnt = 1;
	Node n;
	scanf("%lld",&T);
	while(T--)
	{
		memset(state , 0 , sizeof state);
		memset(lazy , 0 , sizeof lazy);
		scanf("%lld%lld",&N,&Q);
		for(i=1;i<=N;i++)
			scanf("%lld",&A[i]);
		build(1,1,N);
		printf("Case %lld:\n",cnt);
		cnt++;
		
		while(Q--)
		{
			scanf("%lld%lld%lld",&i,&l,&r);
			if(i == 2)
			{
				n = query(1,1,N,l,r);
				printf("%lld\n",n.square);
			}
			else if(i == 1)
			{
				scanf("%lld",&j);
				update(1,1,N,l,r,j,0);
			}
			else
			{
				scanf("%lld",&j);
				update(1,1,N,l,r,j,1);
			}
		}
	}
}
