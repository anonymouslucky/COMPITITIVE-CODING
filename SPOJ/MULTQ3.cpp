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
	lli zeroes,ones,twos;
	void init(lli i)
	{
		zeroes = ones = twos = 0;
		if(i%3 == 0)
			zeroes++;
		else if(i%3 == 1)
			ones++;
		else
			twos++;
	}	
	
	void infi()
	{
		zeroes = ones = twos = 0;
	}
	
	void merge(Node n1,Node n2)
	{
		zeroes = n1.zeroes+n2.zeroes;
		ones = n1.ones + n2.ones;
		twos = n1.twos + n2.twos;
	}
	
	void rotate(lli r)
	{
		lli t;
		if(r == 1)
		{
			t = zeroes;
			zeroes = twos;
			twos = ones;
			ones = t;
		}
		if(r == 2)
		{
			t = zeroes;
			zeroes = ones;
			ones = twos;
			twos = t;
		}
	}
};
 
Node tree[4*SIZE];
lli lazy[4*SIZE],A[SIZE];
 
void build(lli node,lli start,lli end)
{
	if(start == end)
	{
		tree[node].init(0);
	}
	else
	{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].merge(tree[2*node],tree[2*node+1]);
	}
}
 
 
void update(lli node,lli start,lli end,lli l,lli r,lli val){
	val %= 3;
	lazy[node]%=3;
	if(lazy[node] != 0){
		tree[node].rotate(lazy[node]);
		if(start!=end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start > end or end < l or start>r){
		return ;
	}
	
	if(start>=l && end<=r){
		tree[node].rotate(val);
		if(start!=end){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
		return;
	}
	
	lli mid = (start+end)/2;
	
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);
	
	tree[node].merge(tree[2*node],tree[2*node+1]);	
}
 
Node query(lli node,lli start,lli end,lli l,lli r)
{
	Node n;
	if(start>end || start > r || end<l)
	{
		n.infi();
		return n;
	}
	lazy[node]%=3;
	if(lazy[node]!=0)
	{
		tree[node].rotate(lazy[node]);
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
	n.merge(left,right);
	return n;
}
 
 
int main()
{
	lli N,Q,i,j,k,l,r;
	scanf("%lld%lld",&N,&Q);
	Node n;
	memset(A,0,sizeof A);
	build(1,1,N);
	while(Q--)
	{
		scanf("%lld%lld%lld",&i,&l,&r);
		l++;r++;
		if(i == 0)
		{
			update(1,1,N,l,r,1);
		}
		else
		{
			n = query(1,1,N,l,r);
			printf("%lld\n",n.zeroes);
		}
	}
}
