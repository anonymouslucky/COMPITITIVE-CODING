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

lli f[11];

void pre()
{
	f[0] = 1;
	lli i;
	rep(i,1,10)
		f[i] = i*f[i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	pre();
	
	string str1,str2;
	lli n,m,i,j,k,minus,plus;
	
	cin>>str1;
	cin>>str2;
	
	n = str1.length();
	
	minus = plus = k = 0;
	rep(i,0,n-1)
	{
		if(str1[i] == '+')
			plus++;
		else
			minus++;
	}
	
	rep(i,0,n-1)
	{
		if(str2[i] == '+')
			plus--;
		else if(str2[i] == '-')
			minus--;
		else
			k++;
	}
	
	if(plus<0 || minus<0 || (plus+minus)!=k)
	{
		cout<<"0.0"<<endl;
		return 0;
	}
	
	double ans = f[k]/(f[plus]*f[minus]);
	ans = (double)ans/(double)(1<<k);
	
	cout<<fixed<<setprecision(12);
	cout<<ans<<endl;
	return 0;
}
