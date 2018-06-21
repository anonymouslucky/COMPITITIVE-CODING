#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 400010
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
	
	lli n,i,j,k,num,den;
	cin>>n;
	
	i = 1;j=n-1;
	while(i<j)
	{
		if(gcd(i,j) == 1)
		{
			num=i;den=j;
		}
		i++;j--;
	}
	
	cout<<num<<" "<<den<<endl;
	return 0;
}
