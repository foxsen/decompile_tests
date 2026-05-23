#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		int n, x;	cin >> n >> x;
		ll ans = 127 * (n - 1);
		if (n & 1)
			ans += x;
		else
			ans += 127 ^ x;
		cout << ans << "\n";
	}
	return 0;
}
