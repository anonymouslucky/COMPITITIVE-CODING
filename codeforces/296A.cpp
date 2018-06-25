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
	
	lli n,i,j,k;
	unordered_map<lli,lli> m;
	
	cin>>n;
	
	k = 1;
	rep(i,1,n)
	{
		cin>>j;
		m[j]+=1;
		k = max(k,m[j]);
	}
	
	j = n-k;
	if(j>=k-1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}
