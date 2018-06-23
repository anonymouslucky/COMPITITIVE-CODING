#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
#define mod 1000000007
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
	
	lli n,s,i,j,k;
	bool valid = 1;
	cin>>s>>n;
	
	multiset< P<lli,lli> > ms;
	P<lli,lli> curr;
	
	rep(i,1,n)
	{
		cin>>j>>k;
		ms.insert(mk(j,k));
	}
	
	rep(i,1,n)
	{
		curr = *ms.begin(); ms.erase(ms.begin());
		j = curr.first; k = curr.second;
		if(s > j)
			s += k;
		else
		{
			valid = 0;
			break;
		}
	}
	
	
	if(valid)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
