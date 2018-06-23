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
	
	lli n,i,j,k,ans,f,z;
	cin>>n;
	
	f = z = 0;
	
	rep(i,1,n)
	{
		cin>>j;
		f += (bool)(j==5);
		z += (bool)(j==0);
	}
	
	if(z==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	
	if(f<9)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	f = (f/9)*9;
	rep(i,1,f)
		cout<<"5";
	rep(i,1,z)
		cout<<"0";
	return 0;
}
