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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	lli n,t,sum,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		sum = (n*(n+1))/2;
		i=1;
		j=0;
		while(i<=n)
		{
			j += i;
			i*=2;
		}
		sum = sum - 2*j;
		cout<<sum<<endl;
	}
	
	return 0;
}
