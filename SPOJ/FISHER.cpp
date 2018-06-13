#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 210
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,t,i,j,k,u,v,w;
	
	while(1)
	{
		cin>>n>>t;
		if(n == 0 && t == 0)
			break;
			
		lli time[n+1][n+1],toll[n+1][n+1];
		
		rep(i,1,n)
		{
			rep(j,1,n)
				cin>>time[i][j];
		}
		
		rep(i,1,n)
			rep(j,1,n)
				cin>>toll[i][j];
			
		multiset< P<lli, P<lli,lli> > > s;
		P<lli, P<lli,lli> > curr;
		lli T[n+1],D[n+1];
		
		rep(i,1,n)
		{
			T[i] = D[i] = INF;
		}
		
		s.insert(mk(0,mk(0,1)));
		D[1] = 0;
		T[1] = 0;
		
		while(!s.empty())
		{
			curr = *s.begin(); s.erase(s.begin());
			u = curr.second.second;
			j = curr.first; k = curr.second.first;
			if(u == n && k<=t)
			{
				s.clear();
				break;
			}
			
			rep(v,1,n)
			{
				if(v == u)
					continue;
				if(D[v] > j+toll[u][v] || T[v] > k+time[u][v])
				{
					D[v] = j+toll[u][v];
					T[v] = k+time[u][v];
					if(T[v]<=t)
						s.insert(mk(D[v] , mk(T[v],v)));
				}
			}
		}
		
		cout<<j<<" "<<k<<endl;
	}
	
	return 0;
}


