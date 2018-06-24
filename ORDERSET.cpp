#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 200010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

lli BIT[N+10],n;

void update(lli x,lli val)
{
	for(;x<=N;x+=x&-x)
		BIT[x] += val;
}

lli query(lli x)
{
	lli res = 0;
	for(;x>0;x-=x&-x)
		res += BIT[x];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	memset(BIT,0,sizeof BIT);
	
	lli q,i,j,k,l;
	lli lower,upper,mid,ans;
	char c;
	
	P<char,lli> curr;
	map<lli,bool> m;
	unordered_map<lli,lli> first;
	lli second[N];
	
	
	//freopen("output.txt","w",stdout);
	cin>>q;
	vector< P<char,lli> > v(q);
	
	rep(i,1,q)
	{
		cin>>c>>j;
		v[i-1] = mk(c,j);
		m[j] = 1;
	}
	
	
	n=1;
	for(auto x:m)
	{
		first[x.first] = n;second[n] = x.first;
		n++;
	}
	
	n-=1;
	
	bool ins[N],del[N];
	memset(ins,0,sizeof ins);
	memset(del,1,sizeof del);
	
	
	rep(i,1,q)
	{
		curr = v[i-1];
		c = curr.first;
		if(c == 'I')
		{
			j = curr.second;j = first[j];
			if(!ins[j] && del[j])
			{
				ins[j] = 1;del[j]=0;
				update(j,1);
			}
		}
		else if(c == 'D')
		{
			j = curr.second;j = first[j];
			if(!del[j] && ins[j])
			{
				del[j] = 1;ins[j] = 0;
				update(j,-1);
			}
		}
		else if(c == 'C')
		{
			j = curr.second;j = first[j];
			k = query(j-1);
			cout<<k<<endl;
		}
		else
		{
			j = curr.second;
			k = query(n);
			if(k<j)
			{
				cout<<"invalid"<<endl;
				continue;
			}
			
			lower = 1;upper=n;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				k = query(mid);
				if(k>j)
					upper = mid-1;
				else if(k<j)
					lower = mid+1;
				else
				{
					ans = mid;
					upper = mid-1;
				}
			}
			ans = second[ans];
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
