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
	
	lli n,m,mini,maxi,i,j,k;
	cin>>n>>m;
	
	maxi = ((n-m+1)*(n-m))/2;
	i = n/m;
	j = n%m;
	k = m-j;
	mini = k*((i*(i-1))/2)+ j*((i*(i+1))/2);
	
	cout<<mini<<" "<<maxi<<endl;
}
