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
	
	lli l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	
	if(l1>l2)
	{
		swap(l1,l2);
		swap(r1,r2);
	}
	
	lli ans = min(r1,r2)-l2+1;
	
	if(ans<=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	if(k>=l2 && k<=min(r1,r2))
		ans--;
	cout<<ans<<endl;
	return 0;
}
