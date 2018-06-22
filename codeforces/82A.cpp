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
	
	lli n,i,j,k;
	cin>>n;
	
	string ans[5] = {"Sheldon", "Leonard", "Penny", "Rajesh" , "Howard"};
	j=i=0;
	k=1;
	
	while(i+k<n)
	{
		j = (j+1)%5;
		i += k;
		if(j == 0)
			k*=2;
	}
	
	cout<<ans[j]<<endl;
	return 0;
}
