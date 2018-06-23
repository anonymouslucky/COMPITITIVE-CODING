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
	lli n,i,j,k,x,y,sum1,sum2;
	bool op = 0;
	sum1 = sum2 = 0;
	cin>>n;
	
	rep(i,1,n)
	{
		cin>>x>>y;
		sum1 += x;
		sum2 += y;
		if((x+y)&1)
			op = 1;
	}
	
	if((sum1+sum2)%2!=0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	
	if(sum1%2==0)
		cout<<"0"<<endl;
	else
	{
		if(op)
			cout<<"1"<<endl;
		else
			cout<<"-1"<<endl;
	}
		
	return 0;
}
