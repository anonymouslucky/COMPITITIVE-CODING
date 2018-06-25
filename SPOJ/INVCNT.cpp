#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define MAX 1e16
#define SIZE 200001
 
 
using namespace std;
 
lli BIT[SIZE],N;
 
void update(lli x,lli v){
	for(;x<=N;x+=x&-x)
		BIT[x] += v;
}
 
lli query(lli x){
	lli result = 0;
	for(;x>0;x-=x&-x)
		result += BIT[x];
	return result;
}
 
 
int main(){
	lli T,i,j,index,ans = 0;
	
	cin>>T;
	
	while(T--){
		cin>>N;
		lli A[N],B[N];
		map<lli,lli> m;
		ans = 0;
		for(i=0;i<N;i++){
			cin>>A[i];B[i] = A[i];BIT[i]=0;
		}
		BIT[N] = 0;
		sort(B,B+N);
		m[B[0]] = 1;
		index = 2;
		for(i=1;i<N;i++){
			if(B[i] != B[i-1]){
				m[B[i]] = index;
				index++;
			}
		}
		
		for(i=0;i<N;i++){
			A[i] = m[A[i]];
		}
		
		for(i=N-1;i>=0;i--){
			ans += query(A[i]-1);
			update(A[i],1);
		}
		
		cout<<ans<<endl;
		
	}
}
