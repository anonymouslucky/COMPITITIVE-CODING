#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define MAX 1e18
 
using namespace std;
 
 
class Node{
	public:
		lli first,second,sum;
		void init(lli first,lli second){
			this->first = first;this->second = second;
			this->sum = 0;
		}
		
		void merge(Node n1,Node n2){
			lli A[4] = {n1.first,n1.second,n2.first,n2.second};
			sort(A,A+4);
			this->first = A[3];this->second = A[2];
			this->sum = A[3]+A[2];
		}
		
};
 
 
 
Node tree[2000001];
lli A[100001];
 
void build(lli node,lli start,lli end){
	if(start == end){
		tree[node].init(A[start],0);
		//cout<<"Sum::"<<tree[node].sum<<endl;
	}else{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].merge(tree[2*node],tree[2*node+1]);
		//cout<<"Sum::"<<tree[node].sum<<endl;
	}
}
 
void update(lli node,lli start,lli end,lli idx,lli val){
	if(start == end){
		tree[node].init(val,0);
	}else{
		lli mid = (start+end)/2;
		if(start<=idx && idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		tree[node].merge(tree[2*node],tree[2*node+1]);
	}
}
 
Node query(lli node,lli start,lli end,lli l,lli r){
	if(start>end || l> end || r<start){
		Node a;
		a.init(0,0);
		return a;
	}
	
	if(l<=start && end<=r){
		return tree[node];
	}
	
	lli mid = (start+end)/2;
	Node n1 = query(2*node,start,mid,l,r);
	Node n2 = query(2*node+1,mid+1,end,l,r);
	Node n;
	n.merge(n1,n2);
	return n;
}
 
 
int main(){
	lli N,i,j,l,r,Q;
	char c;
	scanf("%lld",&N);
	
	for(i=1;i<=N;i++)
		scanf("%lld",&A[i]);
	
	build(1,1,N);
	
	
	scanf("%lld",&Q);
	
	for(i=1;i<=Q;i++){
		cin>>c;
		scanf("%lld%lld",&l,&r);
		
		if(c == 'U'){
			update(1,1,N,l,r);
		}else{
			Node n = query(1,1,N,l,r);
			printf("%lld\n",n.sum);
		}
		
		
	}
}
