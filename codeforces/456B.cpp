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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli i,j,k,n;
	string str;
	
	cin>>str;
	n = str.length();
	i = str[n-1]-'0';
	
	if(i&1)
	{
		cout<<"0"<<endl;
	}
	else
	{
		j=0;
		if(n>1)
		{
			j=str[n-2]-'0';
		}
		i = 10*j+i;
		if(i%4==0)
			cout<<"4"<<endl;
		else
			cout<<"0"<<endl;
	}
}
