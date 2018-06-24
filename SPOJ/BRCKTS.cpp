#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 30010
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
		lli open,close;
		void init(lli o,lli c)
		{
			open = o; close = c;
		}
		
		void merge_childs(const Node& left,const Node& right)
		{
			lli matched = min(left.open,right.close);
			open = left.open+right.open-matched;
			close = left.close+right.close-matched;
		}
};


Node tree[4*N];
lli A[N];


void build(lli node,lli start,lli end)
{
	if(start==end)
	{
		if(A[start] == 1)
			tree[node].init(1,0);
		else
			tree[node].init(0,1);
	}
	else
	{
		lli mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].merge_childs(tree[2*node],tree[2*node+1]);
	}
}

void update(lli node,lli start,lli end,lli id)
{
	if(start==end)
	{
		if(A[start] == 1)
		{
			A[start] = -1;
			tree[node].init(0,1);
		}
		else
		{
			A[start] = 1;
			tree[node].init(1,0);
		}
	}
	else
	{
		lli mid = (start+end)/2;
		if(id>=start && id<=mid)
			update(2*node,start,mid,id);
		else
			update(2*node+1,mid+1,end,id);
		tree[node].merge_childs(tree[2*node],tree[2*node+1]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli T = 10,i,j,k,n,m,l,r;
	string str;
	
	//freopen("output.txt","w",stdout);
	rep(j,1,10)
	{
		cin>>n;
		cin>>str;
		
		rep(i,1,n)
		{
			if(str[i-1] == '(')
				A[i] = 1;
			else
				A[i] = -1;
		}
		
		build(1,1,n);
		
		cin>>m;
		cout<<"Test "<<j<<":"<<endl;
		while(m--)
		{
			cin>>k;
			if(k>0)
				update(1,1,n,k);
			else
			{
				if(tree[1].close == 0 && tree[1].open == 0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
	}
	
	
	return 0;
}
