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
	
	lli i,j,k,n;
	cin>>n;
	
	string s[n+1];
	map<string,bool> m;
	
	rep(i,1,n)
		cin>>s[i];
	
	repr(i,n,1)
	{
		if(!m[s[i]])
			cout<<s[i]<<endl;
		m[s[i]] = 1;
	}

	return 0;
}


