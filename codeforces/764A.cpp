#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 10000010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)

using namespace std;

lli gcd(lli a,lli b)
{
	return (b==0)?a:gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	lli n,m,z,lcm;
	cin>>n>>m>>z;
	
	lcm = (n*m)/gcd(n,m);
	
	z /= lcm;
	
	cout<<z<<endl;
	
	return 0;
}
