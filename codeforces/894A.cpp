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
	
	lli n,k,i,j;
	string str;
	
	cin>>str;
	n = str.length();	
	lli freq[n+1];
	freq[0] = 0;
	rep(i,1,n)
	{
		freq[i] = freq[i-1]+(bool)(str[i-1] == 'Q');
	}
	
	lli ans = 0;
	rep(i,1,n)
	{
		if(str[i-1]!='A')
			continue;
		ans += (freq[i-1]*(freq[n]-freq[i]));
	}
	
	cout<<ans<<endl;
	return 0;
}
