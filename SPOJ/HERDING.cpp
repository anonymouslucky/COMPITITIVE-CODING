#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 1000010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

lli root[N],size[N];
void init(lli n)
{
	lli i;
	rep(i,1,n)
	{
		root[i] = i;
		size[i] = 1;
	}
}

lli find_root(lli i)
{
	while(i!=root[i])
	{
		root[i] = find_root(root[i]);
		i = root[i]; 
	}
	return i;
}

void U(lli i,lli j)
{
	lli rooti = find_root(i);
	lli rootj = find_root(j);
	if(rooti == rootj)
		return;
	root[rooti] = rootj;
	size[rootj] += size[rooti];
	size[rooti] = 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,m,i,j,k,u,v,sx,sy,ex,ey;
	
	cin>>n>>m;

	char grid[n+1][m+1];
	string str;
	
	rep(i,1,n)
	{
		cin>>str;
		rep(j,1,m)
			grid[i][j] = str[j-1];
	}
	
	lli ans = 0;
	
	init(n*m);
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			u = m*(i-1)+j;
			if(grid[i][j] == 'E')
				v = u+1;
			else if(grid[i][j] == 'W')
				v = u-1;
			else if(grid[i][j] == 'N')
				v = u-m;
			else
				v = u+m;
			U(u,v);
		}
	}
	
	rep(i,1,n*m)
	{
		if(size[i]>0)
			ans++;
	}
		
	cout<<ans<<endl;
	return 0;
}


