// D - Widespread
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rp(i,n) for(int i=0;i<(n);++i)
#define roundup(a,b) (((a)+(b)-1)/(b))

int main(){
	int N,A,B; cin>>N>>A>>B;
	vector<LL> H(N); rp(i, N) cin>>H[i];

	int ans = INT_MAX;
	LL ab = (LL)A - B;//additional damage
	int L = 0, R = 1e9;
	while(L <= R){
		int t = (L + R)/2;//mid
		LL tb = (LL)t * B;
		LL s = 0;
		rp(i, N){
			LL h = H[i] - tb;
			if(h > 0) s += roundup(h, ab);
		}
		if(t >= s){
			R = t - 1;//mid-1
			ans = t;
		}
		else L = t + 1;//mid+1
	}
	cout<< ans <<endl;
}