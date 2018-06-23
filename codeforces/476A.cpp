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
	
	
	lli n,m,i,j,lower,upper,mid;
	cin>>n>>m;
	
	
	bool valid = 0;
	for(i=m;i<=n;i+=m)
	{
		lower=0;upper=i;
		while(lower<=upper)
		{
			mid = (lower+upper)>>1;
			j = mid+(i-mid)*2;
			if(j==n)
			{
				valid = 1;
				break;
			}
			else if(j<n)
				upper = mid-1;
			else
				lower = mid+1;
		}
		if(valid)
			break;
	}
	
	if(valid)
		cout<<i<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
