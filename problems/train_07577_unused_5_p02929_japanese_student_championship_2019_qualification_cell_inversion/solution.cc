#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
string A;

const ll MOD = 1000000007;

int main() {
	cin >> N;
	cin >> A;
	
	if (A[0] == 'W' || A.back() == 'W') {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < 2 * N; i++) {
		if (i % 2 == 0) {
			if (A[i] == 'W')A[i] = 'B';
			else A[i] = 'W';
		}
	}
	ll ans = 1;
	ll cnt = 0;

	for (int i = 0; i < 2 * N; i++) {
		if (A[i] == 'W')cnt++;
		else {
			if (cnt >= 1) {
				ans *= cnt, ans %= MOD;
				cnt--;
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	if (cnt != 0) {
		cout << 0 << endl;
		return 0;
	}
	for (ll i = 1; i <= N; i++) {
		ans *= i, ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}