#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll a[3], m[3], p[3];
	
	while (true) {
		REP(i, 3) scanf("%lld %lld", &a[i], &m[i]);
		
		bool f = true;
		REP(i, 3) if (a[i] != 0 || m[i] != 0) f = false;
		if (f) break;
		
		ll mem[3];
		REP(i, 3) {
			ll cnt = 0;
			p[i] = 1;
			while (true) {
				p[i] = a[i] * p[i] % m[i];
				cnt++;
				if (p[i] == 1) break;
			}
			mem[i] = cnt;
		}
		
		
		
		cout << lcm(lcm(mem[0], mem[1]), mem[2]) << endl;
	}
	return 0;
}