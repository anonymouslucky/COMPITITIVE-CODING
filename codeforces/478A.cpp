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
	
	lli c1,c2,c3,c4,c5,sum;
	cin>>c1>>c2>>c3>>c4>>c5;
	sum = c1+c2+c3+c4+c5;
	
	if(sum!=0 && sum%5 ==0)
	{
		sum /= 5;
		cout<<sum<<endl;
	}
	else
		cout<<"-1"<<endl;
	return 0;
}
