#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
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
	
	string str;
	lli n,m,i,j,k,l,r;
	
	cin>>str;
	n = str.length();
	
	lli ans[n+1];
	ans[0] = 0;
	rep(i,1,n-1)
		ans[i] = ans[i-1]+(bool)(str[i-1] == str[i]);
	
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		cout<<(ans[r-1]-ans[l-1])<<endl;
	}
	
	return 0;
}
