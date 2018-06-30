#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  30010
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
	
	lli a,b,c,i,j,k,A,B,C,first,second,third;
	cin>>A>>B>>C;
	
	k = (A+B+C);
	if(k&1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	k/=2;
	j = min(A,B);
	
	rep(first,0,j)
	{
		a = A;b = B;c = C;
		a-=first;b-=first;
		second = min(b,c);
		b-=second;c-=second;
		third = min(a,c);
		a-=third;b-=third;
		if(first+second+third == k)
		{
			cout<<first<<" "<<second<<" "<<third<<endl;
			return 0;
		}
	}
	
	
	
	cout<<"Impossible"<<endl;
	return 0;
} 
