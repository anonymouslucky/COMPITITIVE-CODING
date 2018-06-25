#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define SIZE 1000001
#define MAX 1e16
 
 
using namespace std;
 
lli A[100001],tree[SIZE],lazy[SIZE],N;
 
 
void build(lli node,lli start,lli end){
	if(start == end){
		tree[node] = A[start];
	}else{
		lli mid = (start+end)/2;
		
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = tree[2*node]+tree[2*node+1];	
	}
}
 
 
void update(lli node,lli start,lli end,lli l,lli r,lli val){
	
	if(lazy[node] != 0){
		tree[node] += (end-start+1)*lazy[node];
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
		tree[node] += (end-start+1)*val;
		if(start!=end){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
		return;
	}
	
	lli mid = (start+end)/2;
	
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);
	
	tree[node] = tree[2*node]+tree[2*node+1];
	
}
 
 
 
lli query(lli node,lli start,lli end,lli l,lli r){
	if(start > end or end < l or start>r){
		return 0;
	}
	
	if(lazy[node] != 0){
		tree[node] += (end-start+1)*lazy[node];
		if(start!=end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(start>=l && end<=r){
		return tree[node];
	}
	
	lli mid = (start+end)/2;
	
	lli s1 = query(2*node,start,mid,l,r);
	lli s2 = query(2*node+1,mid+1,end,l,r);
	
	return s1+s2;
	
}
 
int main(){
	
	lli T,cn = 1,Q,i,c,x,y,v,ans;
	
	scanf("%lld",&T);
	
	
	while(T--){
		memset(tree,0,sizeof tree);
		memset(lazy,0,sizeof lazy);
		scanf("%lld%lld",&N,&Q);
		while(Q--){
			scanf("%lld",&c);
			if(c == 0){
				scanf("%lld%lld%lld",&x,&y,&v);
				update(1,1,N,x,y,v);
			}else{
				scanf("%lld%lld",&x,&y);
				ans = query(1,1,N,x,y);
				printf("%lld\n",ans);
			}
			
		}
		cn++;
	}
	
}
