#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  1000010
#define mod 1000000007
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
#define SIZE 100010
#define SQRSIZE 1000

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli y,n,k,x,i;
	cin>>y>>k>>n;
	
	n = (n/k)*k;
	bool valid = 0;
	for(i=k;i<=n;i+=k)
	{
		x = i-y;
		if(x>=1)
		{
			cout<<x<<" ";
			valid = 1;
		}
	}
	
	if(!valid)
		cout<<"-1"<<endl;
	
	return 0;
}
