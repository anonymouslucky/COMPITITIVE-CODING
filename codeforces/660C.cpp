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

	lli n,i,j,k,I,J;
	lli lower,upper,mid;
	
	cin>>n>>k;
	
	lli a[n+1],freq[n+1];
	freq[0] = 0;
	rep(i,1,n)
	{
		cin>>a[i];
		freq[i] = freq[i-1] + (bool)(a[i] == 1);
	}
	
	lli ans = 0;
	rep(i,1,n)
	{
		lower = 1; upper = i;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			if(freq[i]-freq[mid-1]+k >= i-mid+1)
			{
				if(i-mid+1 > ans)
				{
					ans = i-mid+1;
					I = mid; J = i;
				}
				upper = mid-1;
			}
			else
				lower = mid+1;
		}
	}
	
	
	cout<<ans<<endl;
	rep(i,1,n)
	{
		if(i>=I && i<=J)
			cout<<"1 ";
		else
			cout<<(a[i])<<" ";
	}
	return 0;
}
