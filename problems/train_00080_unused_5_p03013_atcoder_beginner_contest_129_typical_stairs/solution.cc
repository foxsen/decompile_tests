#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll N,M,a,MOD=1e9+7;
	cin >> N >> M;
	vector<ll> X(N+5,0);
	for(int i=0;i<M;i++){
		cin >> a;
		X[a]=-1;
	}
	X[0] = 1;
	if(X[1]!=-1)X[1] = 1;
	for(int i=2;i<N+1;i++){
		if(X[i]==-1)continue;
		X[i] = ( (X[i-1]!=-1)*X[i-1] + (X[i-2]!=-1)*X[i-2] ) % MOD;
	}
	cout << X[N] << endl;
}