#include<bits/stdc++.h>
#define int int64_t
using namespace std;

const int M = 1e9+7;
int fact[2000055] , inv[2000055];

int __power(int x , int p) {
	int res = 1;
	while(p) {
		if(p & 1) res = (res * x)%M;
		p /= 2;
		x = (x * x)%M;
	}
	return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	fact[0] = fact[1] = 1;
	for(int i = 2; i < 2000055; i++) fact[i] = (i * fact[i-1])%M;
	inv[2000054] = __power(fact[2000054] , M-2);
	for(int i = 2000053; i >= 0; i--) inv[i] = (inv[i+1] * (i+1))%M; 
	int r1 , r2 , c1 , c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int ans = 0;
	for(int i = c1; i <= c2; i++) {
		int val1 = (fact[r2+i+1] * inv[r2])%M , val2 = (fact[r1+i] * inv[r1-1])%M;
		val1 = (val1 * inv[i+1])%M;
		val2 = (val2 * inv[i+1])%M;
		ans = (ans + (val1 - val2 + M)%M)%M;
	}
	cout << ans << "\n";
	
    return 0;
}
