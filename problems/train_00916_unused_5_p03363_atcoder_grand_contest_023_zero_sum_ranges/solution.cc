#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n; cin>>n;
	map<ll,ll> m;
	ll ans{}, sum{};
	m[0]++;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		sum += a;
		m[sum]++;
	}
	for(auto i:m){
		ans += i.second*(i.second-1)/2;
	}
	cout << ans << endl;
	
}
