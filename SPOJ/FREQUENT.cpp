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
		lli fre,id,pre,post,pre_id,post_id;
		void init(lli i)
		{
			id = pre_id = post_id = i;
			fre = pre = post = 1;
		}
		
		void infi()
		{
			id = pre_id = post_id = 1000000;
			fre = pre = post = 0;
		}
			
		void merge(Node n1,Node n2)
		{
			pre = n1.pre;pre_id = n1.pre_id;
			post = n2.post; post_id = n2.post_id;
			if(n1.pre_id == n1.post_id && n1.post_id == n2.pre_id)
				pre += n2.pre;
			if(n2.pre_id == n2.post_id && n2.pre_id == n1.post_id)
				post += n1.post;
			
			if(n1.fre > n2.fre)
			{
				fre = n1.fre;id = n1.id;
			}
			else
			{
				fre = n2.fre; id = n2.id;
			}
			
			if(n1.post_id == n2.pre_id && n1.post+n2.pre > fre)
			{
				fre = n1.post+n2.pre;
				id = n1.post_id;
			}
			
			if(pre > fre)
			{
				fre = pre;
				id = pre_id;
			}
			
			if(post > fre)
			{
				fre = post;
				id = post_id;
			}
			
		}
};
 
Node tree[4*SIZE];
lli A[SIZE];
 
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
 
Node query(lli node,lli start,lli end,lli l,lli r)
{
	Node n;
	
	if(start > end || start > r || end<l)
	{
		n.infi();
		return n;
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
	lli T,N,Q,i,j,k,l,r;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node n;
	while(1)
	{
		cin>>N;
		if(N == 0)
			break;
		cin>>Q;
		for(i=1;i<=N;i++)
			cin>>A[i];
		build(1,1,N);
		while(Q--)
		{
			cin>>l>>r;
			n = query(1,1,N,l,r);
			cout<<(n.fre)<<endl;
		}
	}
	
}
