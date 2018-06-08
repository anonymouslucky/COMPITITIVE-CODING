#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e18
#define N 100010
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
	
	lli n,i,j,k,f,s;
	
	vector<lli> v;
	string lowest[] = {"47","4477","444777","44447777","4444477777"};
	string str;
	
	rep(k,0,4)
	{
		//sscanf(lowest[k],"%lld",i);
		//i = atoi(lowest[k]);
		str = lowest[k];
		do
		{
			stringstream ss(str);
			ss>>i;
			v.pb(i);
		}
		while(next_permutation(str.begin(),str.end()));
	}
	
	cin>>n;
	
	cout<<(*lower_bound(v.begin(),v.end(),n))<<endl;

	return 0;
}


