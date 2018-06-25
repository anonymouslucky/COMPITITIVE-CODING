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
		lli sum,minimum;
		void init(lli i)
		{
			sum = minimum = i;
		}
		void infi()
		{
			sum = 0; minimum = INF;
		}
		void merge(const Node& left,const Node& right)
		{
			sum = left.sum+right.sum;
			minimum = min(left.minimum,right.minimum);
		}
};

lli apples[N];
Node tree[4*N];

void build(lli index,lli start,lli end)
{
	if(start == end)
	{
		tree[index].init(apples[start]);
	}
	else
	{
		lli mid = (start+end)>>1;
		build(2*index,start,mid);
		build(2*index+1,mid+1,end);
		tree[index].merge(tree[2*index],tree[2*index+1]);
	}
}


void update(lli index,lli start,lli end,lli id)
{
	if(start == end)
	{
		tree[index].init(apples[id]);
	}
	else
	{
		lli mid = (start+end)>>1;
		if(id>=start && id<=mid)
			update(2*index,start,mid,id);
		else
			update(2*index+1,mid+1,end,id);
		
		tree[index].merge(tree[2*index],tree[2*index+1]);
	}
}

Node query(lli index,lli start,lli end,lli l,lli r)
{
	Node res,left,right;
	if(start>end || start>r || end<l)
	{
		res.infi();
		return res;
	}
	
	if(start>=l && end<=r)
		return tree[index];
		
	lli mid = (start+end)>>1;
	left = query(2*index,start,mid,l,r);
	right = query(2*index+1,mid+1,end,l,r);
	res.merge(left,right);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli p,n,i,j,k,l,r;
	string str;
	cin>>n;
	rep(i,0,n-1)
		cin>>apples[i];
	
	build(1,0,n-1);
	cin>>p;
	
	while(p--)
	{
		cin>>str>>l>>r;
		if(str == "GROW")
		{
			apples[r] += l;
			update(1,0,n-1,r);
		}
		else if(str == "EAT")
		{
			apples[r] -= l;
			update(1,0,n-1,r);
		}
		else
		{
			Node node = query(1,0,n-1,l,r);
			k = node.sum - node.minimum;
			cout<<k<<endl;
		}
	}
	
	return 0;
}
