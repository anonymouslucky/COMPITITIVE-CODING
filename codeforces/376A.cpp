#include<bits/stdc++.h>
#define lli long long int
#define ULL unsigned long long int
#define pb push_back
#define INF 1e18
#define N  5000010
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
	
	string str;
	ULL left,right;
	lli i,j,k,n,pivot;
	
	left = right = 0;
	cin>>str;
	n = str.length();
	
	rep(i,0,n-1)
	{
		if(str[i] == '^')
		{
			pivot = i;
			break;
		}
	}
	
	rep(i,pivot+1,n-1)
	{
		if(str[i]!='=')
			right += ((str[i]-'0')*(i-pivot));
	}
	
	rep(i,0,pivot-1)
	{
		if(str[i]!='=')
			left += ((str[i]-'0')*(pivot-i));
	}
	
	if(left == right)
		cout<<"balance";
	else if(left>right)
		cout<<"left";
	else
		cout<<"right";
	
	return 0;
} 
