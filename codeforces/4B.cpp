#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 40
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

lli mintime[N],maxtime[N];
lli summin[N],summax[N];

bool valid(lli index,lli left,lli n)
{
	return (left>=(summin[n]-summin[index-1]) && left<=(summax[n]-summax[index-1]));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli d,sumtime,i,j,k;
	
	
	cin>>d>>sumtime;
	
	rep(i,1,d)
	{
		cin>>mintime[i]>>maxtime[i];
		summin[i] = summin[i-1]+mintime[i];
		summax[i] = summax[i-1]+maxtime[i];
	}
	
	if(d == 1)
	{
		if(sumtime>=mintime[1] && sumtime<=maxtime[1])
		{
			cout<<"YES"<<endl;
			cout<<sumtime<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		return 0;
	}
	
	k = 0;
	
	if(!(sumtime>=summin[d] && sumtime<=summax[d]))
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	rep(i,1,d-1)
	{
		rep(j,mintime[i],maxtime[i])
		{
			if(valid(i+1,sumtime-k-j,d))
			{
				cout<<j<<" ";
				k += j;
				break;
			}
		}
	}
	
	cout<<(sumtime-k)<<endl;
	return 0;
}
