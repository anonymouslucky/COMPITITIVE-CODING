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
	
	
	int i,n;
    cin >> n;
    int tot = 0;
    rep(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        if (tot+a <= 500) {
            tot += a;
            cout << "A";
        } else {
            tot -= b;
            cout << "G";
        }
    }
    cout << endl;
	return 0;
} 
