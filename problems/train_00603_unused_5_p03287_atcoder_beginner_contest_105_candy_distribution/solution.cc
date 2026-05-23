#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
int main(){
	ll N,M,ans=0,sum=0;
	cin >> N >> M;
	vector<ll> A(N);
	FOR(i,0,N)cin >> A[i];
	map<ll,ll> ma;
	ma[0]++;
	FOR(i,0,N){
		(sum += A[i]) %= M;
		ans += ma[sum];
		ma[sum]++;
	}
	cout << ans << endl;
}