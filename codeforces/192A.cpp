#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 100010
#define tol 1e-6
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli T,n,i,j,count;
	
	cin>>n;
	vector<lli> v;
	
	count = 0;
	rep(i,1,200000)
	{
		j = (i*(i+1))/2;
		if(j>n)
			break;
		v.pb(j);
		count++;
	}
	
	rep(i,0,count-1)
	{
		if(binary_search(v.begin(),v.end(),n-v[i]))
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	return 0;
}
