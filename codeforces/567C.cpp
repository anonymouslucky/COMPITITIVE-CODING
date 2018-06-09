#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

bool cmp(const P<lli,lli>& p1 , const P<lli,lli>& p2)
{
	if(p1.first < p2.first)
		return 1;
	else if(p1.first == p2.first)
		return p1.second < p2.second;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,k,i,j,l,r,L,R;
	lli lower,upper,mid;
	
	cin>>n>>k;
	
	lli a[n];
	vector< P<lli,lli> > v(n);
	
	rep(i,0,n-1)
	{
		cin>>a[i];
		v[i] = mk(a[i],i);
	}
	
	
	sort(v.begin(),v.end(),cmp);
	
	lli ans = 0;
	
	map<lli,lli> m;
	map<lli,lli>::iterator it;
	if(k==1)
	{
		
		rep(i,0,n)
			m[a[i]]++;
		
		for(it=m.begin();it!=m.end();it++)
		{
			j = it->second;
			if(j < 3)
				continue;
			ans += (j*(j-1)*(j-2))/6;
		}
		cout<<ans<<endl;
		return 0;
	}
	
	rep(i,0,n-1)
	{
		
		if(v[i].first % k!=0)
			continue;
		
		if(v[i].first >= 0)
		{
			lower = 0; upper = i-1;
			l = INF;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first/k)
					upper = mid-1;
				else if(v[mid].first < v[i].first/k)
					lower = mid+1;
				else 
				{
					if(v[mid].second <= v[i].second)
					{
						l = min(l,mid);
					}	
					upper = mid-1;
				}
			}
			
			if(l == INF)
				continue;
			
			r = -INF;
			lower = 0; upper = i-1;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first/k)
					upper = mid-1;
				else if(v[mid].first < v[i].first/k)
					lower = mid+1;
				else
				{
					if(v[mid].second <= v[i].second)
					{
						r = max(r,mid);
						lower = mid+1;
					}
					else
						upper = mid-1;
				}
			}
			
			L = r-l+1;
			
			lower = i+1; upper = n-1;
			l = INF;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first*k)
					upper = mid-1;
				else if(v[mid].first < v[i].first*k)
					lower = mid+1;
				else
				{
					if(v[mid].second >= v[i].second)
					{
						l = min(l,mid);
						upper = mid-1;
					}
					else
						lower=mid+1;
				}
			}
			
			if(l == INF)
				continue;
				
			r = -INF;
			lower = i+1; upper = n-1;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first*k)
					upper = mid-1;
				else if(v[mid].first < v[i].first*k)
					lower = mid+1;
				else
				{
					if(v[mid].second >= v[i].second)
					{
						r = max(r,mid);
						
					}
					lower = mid+1;
				}
			}
			
			R = r-l+1;
			
			ans += L*R;
		}
		else
		{
			lower = 0; upper = i-1;
			l = INF;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first*k)
					upper = mid-1;
				else if(v[mid].first < v[i].first*k)
					lower = mid+1;
				else 
				{
					if(v[mid].second > v[i].second)
					{
						l = min(l,mid);
						upper = mid-1;
					}	
					else
						lower = mid+1;
				}
			}
			
			if(l == INF)
				continue;
			
			r = -INF;
			lower = 0; upper = i-1;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first*k)
					upper = mid-1;
				else if(v[mid].first < v[i].first*k)
					lower = mid+1;
				else
				{
					if(v[mid].second > v[i].second)
					{
						r = max(r,mid);
					}
					lower = mid+1;
				}
			}
			
			L = r-l+1;
			
			lower = i+1; upper = n-1;
			l = INF;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first/k)
					upper = mid-1;
				else if(v[mid].first < v[i].first/k)
					lower = mid+1;
				else
				{
					if(v[mid].second < v[i].second)
					{
						l = min(l,mid);
					}
					upper = mid-1;
				}
			}
			
			if(l == INF)
				continue;
			
			r = -INF;
			lower = i+1; upper = n-1;
			while(lower<=upper)
			{
				mid = (lower+upper)>>1;
				if(v[mid].first > v[i].first/k)
					upper = mid-1;
				else if(v[mid].first < v[i].first/k)
					lower = mid+1;
				else
				{
					if(v[mid].second < v[i].second)
					{
						r = max(r,mid);
						lower = mid+1;
					}
					else
						upper = mid-1;
				}
			}
			
			R = r-l+1;
			
			ans += L*R;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
