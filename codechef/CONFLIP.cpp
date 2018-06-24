#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N 200010
#define mod 1000000007
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
	
	lli t,n,q,i,j,k,ans,flipped;
	cin>>t;
	while(t--)
	{
		cin>>k;
		while(k--)
		{
			cin>>j>>n>>q;
			flipped = n/2;
			if(n&1)
				flipped+=1;
			if(j == q)
				cout<<(n-flipped)<<endl;
			else
				cout<<flipped<<endl;
		}
	}
	
	return 0;
}
