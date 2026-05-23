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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin>>N,N) {
		vector<string>v(N);
		for (auto &i : v)cin >> i;
		vector<long long int>w(N);
		for (int i = 0; i < N; i++) {
			if (v[i] == "x")w[i] = MOD;
			else w[i] = stoi(v[i]);
		}
		L = -MOD, R = MOD;
		for (int i = 0; i < N; i++) {
			if (v[i] != "x") {
				continue;
			}
			if ((i & 1)) {
				if (i) {
					if (w[i - 1] != MOD) {
						L = max(L, w[i - 1] + 1);
					}
				}
				if (i + 1 < N) {
					if (w[i + 1] != MOD) {
						L = max(L, w[i + 1] + 1);
					}
				}
			}
			else {
				if (i) {
					if (w[i - 1] != MOD) {
						R = min(R, w[i - 1] - 1);
					}
				}
				if (i + 1 < N) {
					if (w[i + 1] != MOD) {
						R = min(R, w[i + 1] - 1);
					}
				}
			}
		//	cout << L << " " << R << endl;
		}
		for (int i = 1; i < N; i++) {
			if (v[i] != "x"&&v[i - 1] != "x") {
				if (i & 1) {
					if (w[i - 1] >= w[i])L = R + 1;
				}
				else {
					if (w[i - 1] <= w[i])L = R + 1;
				}
			}
			if (v[i] == "x"&&v[i - 1] == "x") {
				L = R + 1;
			}
		}
	//	for (int i = 0; i < N; i++) {
	//		cout<<
	//	}
		if (L == R) {
			cout << L << endl;
		}
		else if (L < R) {
			cout << "ambiguous" << endl;
		}
		else {
			cout << "none" << endl;
		}
	//	cout << L << " " << R << endl;
	}
}
