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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	lli a,b,s;
	cin>>a>>b>>s;
	
	a = abs(a); b = abs(b);
	if(s<a+b)
	{
		cout<<"No"<<endl;
		return 0;
	}
	
	if((s-a-b)%2 == 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	
	return 0;
}
