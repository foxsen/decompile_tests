#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;

LL mod = 1000000007;

LL mi (LL x, LL m) {
	// compute pow(x, m-2)
	LL acc = 1;
	LL p = m-2;
	while (p) {
		if (p%2 == 1) {
			acc *= x;
			acc %= m;
		}
		x *= x % m;
		x %= m;
		p >>= 1;
	}
	
	return acc;
}

int main()
{
	LL n;
	cin >> n;

	vector<LL> x(n);

	for (auto &e : x) {
		cin >> e;
	}

	vector<LL> mijs(n-1);

	mijs[0] = 1;
	for (LL i = 1; i < n-1; ++i) {
		mijs[i]=mijs[i-1]+mi(i+1, mod);
		mijs[i]%=mod;
	}

	LL sum = 0;
	for (LL i = 0; i < n-1; ++i) {
		sum += (x[i+1]-x[i])*mijs[i] % mod;
		sum %= mod;
	}

	for (LL i = 1; i <= n-1; ++i) {
		sum *= i;
		sum %= mod;
	}

	cout << sum << "\n";

}