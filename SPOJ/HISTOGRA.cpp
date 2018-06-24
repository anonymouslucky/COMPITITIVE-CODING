#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 100010
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
		lli val,id;
		void init(lli v,lli i)
		{
			val = v; id = i;
		}
		void merge_childs(const Node& left , const Node& right)
		{
			if(left.val<right.val)
			{
				val = left.val; id = left.id;
			}
			else
			{
				val = right.val; id = right.id;
			}
		}
};

lli h[N],n;
Node tree[4*N];

void build(lli index,lli start,lli end)
{
	if(start == end)
		tree[index].init(h[start],start);
	else
	{
		lli mid = (start+end)>>1;
		build(2*index,start,mid);
		build(2*index+1,mid+1,end);
		tree[index].merge_childs(tree[2*index],tree[2*index+1]);
	}
}

Node query(lli index,lli start,lli end,lli l,lli r)
{
	Node left,right,res;
	res.init(INF,-1);
	if(start>end || start>r || end<l)
		return res;
	if(start>=l && end<=r)
		return tree[index];
	
	lli mid = (start+end)>>1;
	left = query(2*index,start,mid,l,r);
	right = query(2*index+1,mid+1,end,l,r);
	res.merge_childs(left,right);
	return res;
}

lli ans(lli l,lli r)
{
	if(l>r)
		return -1;
	
	Node res = query(1,1,n,l,r);
	if(l==r)
		return res.val;
	return max((r-l+1)*res.val,max(ans(l,res.id-1),ans(res.id+1,r)));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli i,j,k;
	
	while(1)
	{
		cin>>n;
		if(n == 0)
			break;
		rep(i,1,n)
			cin>>h[i];
			
		build(1,1,n);
		cout<<ans(1,n)<<endl;
	}
	
	return 0;
}
