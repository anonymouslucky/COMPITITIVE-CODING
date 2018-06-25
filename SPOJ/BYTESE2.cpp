#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#define MAX 1e18
#define SIZE 210
 
 
using namespace std;
 
lli BIT[SIZE],N;
 
void update(lli x,lli val)
{
	for(;x<=2*N+2;x+=x&-x)
		BIT[x] += val;
}
 
lli query(lli x)
{
	lli result = 0;
	for(;x>0;x-=x&-x)
		result += BIT[x];
	return result;
}
 
 
int main()
{
	lli T,i,j,k,l,r,ans;
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	multiset< pair<lli,lli> > s;
	pair<lli,lli> current;
	
	while(T--)
	{
		cin>>N;
		lli persons[N][2],arr[2*N];
		
		for(i=0;i<N;i++)
		{
			cin>>j>>k;
			s.insert(make_pair(k,j));
			arr[2*i] = j;arr[2*i+1]= k;
		}
		
		sort(arr,arr+2*N);
	    map<lli,lli> m;
		j = 1;
		for(i=0;i<2*N;i++)
		{
			if(m[arr[i]]>0)
				continue;
			else
			{
				m[arr[i]] = j;
				j++;
			}
		}
		
		i=0;
		while(!s.empty())
		{
			current = *s.begin(); s.erase(s.begin());
			persons[i][0] = m[current.second];persons[i][1] = m[current.first];
			i++;
		}
		
		memset(BIT , 0 , sizeof BIT);
		ans = 0;
		for(i=0;i<N;i++)
		{
			update(persons[i][0],1);
			update(persons[i][1],-1);
		}
		
		for(i=1;i<=2*N;i++)
		{
			//cout<<query(i)<<",";
			ans = max(ans,query(i));
		}
		
		cout<<ans<<endl;
	}
}
