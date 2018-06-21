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

ULL mulmod(ULL a, ULL b, ULL c)
{
	ULL x = 0,y = a%c;
	
	while(b>0)
	{
		if(b&1) x = (x+y)%c;
		y = (y<<1)%c;
		b >>= 1;
	}
	
	return x;
}

ULL pow(ULL a, ULL b, ULL c)
{
	ULL x = 1, y = a;
	
	while(b>0)
	{
		if(b&1) x = mulmod(x,y,c);
		y = mulmod(y,y,c);
		b >>= 1;
	}
	
	return x;
}

bool miller_rabin(ULL p, int it)
{
	if(p<2) return false;
	if(p==2) return true;
	if((p&1)==0) return false;
	
	ULL s = p-1;
	
	while(s%2==0) s >>= 1;
	
	while(it--)
	{
		ULL a = rand()%(p-1)+1,temp = s;
		ULL mod = pow(a,temp,p);
		
		if(mod==-1 || mod==1) continue;
		
		while(temp!=p-1 && mod!=p-1)
		{
			mod = mulmod(mod,mod,p);
			temp <<= 1;
		}
		
		if(mod!=p-1) return false;
	}
	
	return true;
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	
	//freopen("output.txt","w",stdout);
	lli i,t,n,k=20;
	cin>>t;
	rep(i,1,t)
	{
		cin>>n;
		if(miller_rabin(n,18))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}
