#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  5000010
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
	
	lli i,j,n;
	
	unordered_map<lli,bool> m;
	
	rep(i,1,500)
		m[(i*(i+1))>>1]=1;
	
	cin>>n;
	
	if(m[n])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
} 
