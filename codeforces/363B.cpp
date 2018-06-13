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
	cin>>n>>k;
	
	lli h[n+1],sum[n+1],mini;
	sum[0] = h[0] = 0;
	rep(i,1,n)
	{
		cin>>h[i];
		sum[i] = sum[i-1]+h[i];
	}
	
	mini = INF;
	rep(i,1,n-k+1)
	{
		if(mini > sum[i+k-1]-sum[i-1])
		{
			mini = sum[i+k-1]-sum[i-1];
			j = i;
		}	
	}
	
	cout<<j<<endl;
	return 0;
}
