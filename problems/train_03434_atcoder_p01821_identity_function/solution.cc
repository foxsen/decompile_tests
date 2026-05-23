#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long long int lcm(long long int a, long long int b) {
	return a * b / gcd(a, b);
}

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	L = N;
	vector<int>v(1, 1);
	for (int i = 2; i*i <= N; i++) {
		while (N%i == 0) {
			if (v.back() == i) {
				cout << -1 << endl;
				return 0;
			}
			v.push_back(i);
			N /= i;
		}
	}
	if (N > 1)v.push_back(N);
	long long int box = 1;
	for (int i = 1; i < v.size(); i++) {
		box = lcm(box, v[i] - 1);
	}
	N = L;
	//cerr << box << endl;
	if (gcd(box, N) != 1) {
		cout << -1 << endl;
		return 0;
	}
	long long int bag = box;
	R = box;
	for (int i = 2; i*i <= box; i++) {
		if (box%i == 0) {
			bag *= i - 1;
			bag /= i;
			while (box%i == 0) {
				box /= i;
			}
		}
	}
	if (box > 1) {
		bag *= box - 1;
		bag /= box;
	}
	box = R;
	//cerr << bag << endl;
	int ans = MOD;
	for (int i = 1; i*i <= bag; i++) {
		if (power(N, i, box) == 1%box) {
			ans = min(ans, i);
		}
		if (power(N, bag/i, box) == 1%box) {
			ans = min(ans, (int)bag/i);
		}
	}
	if (ans == MOD)ans = -1;
	cout << ans << endl;
	return 0;
}
