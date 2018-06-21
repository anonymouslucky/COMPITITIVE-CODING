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
	
	string str = "abcdef",temp;
	lli i,n,j,ans=0;
	
	cin>>str;
	n = str.length();
	map<string,bool> m;
	
	rep(i,0,n)
	{
		rep(j,0,25)
		{
			temp = str;
			temp.insert(i,1,(char)(97+j));
			if(!m[temp])
			{
				//cout<<temp<<endl;
				m[temp] = 1;
				ans++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
