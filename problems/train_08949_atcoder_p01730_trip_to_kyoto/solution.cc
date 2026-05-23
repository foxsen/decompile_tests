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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>x(N);
	vector<int>y(N);
	int xl = MOD, xr = -MOD, yl = MOD, yr = -MOD;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		x[i] <<= 1, y[i] <<= 1;
		x[i] += 400000000;
		y[i] += 100000000;
		int X, Y;
		tie(X, Y) = make_pair(x[i] + y[i], x[i] - y[i]);
		xl = min(xl, X);
		xr = max(xr, X);
		yl = min(yl, Y);
		yr = max(yr, Y);
		
	}
	int xmid = (xl + xr) / 2;
	int ymid = (yl + yr) / 2;
	int ans = MOD;
	int len = 100;
	for (int i = xmid - len; i <= xmid + len; i++) {
		for (int j = ymid - len; j <= ymid + len; j++) {
			if (abs(i - j) % 2)continue;
			int w = (i + j) / 2;
			int h = i - w;
			if (w % 20 && h % 20)continue;
			int box = 0;
			for (int k = 0; k < N; k++) {
				if ((w+1000000000) / 20 == (x[k]+1000000000) / 20) {
					if (h == y[k])box = max(box, abs(w - x[k]));
					else box = max(box, abs(h - y[k]) + min(40 - (w % 20 + x[k] % 20), (w % 20 + x[k] % 20)));
				}
				else if ((h+1000000000) / 20 == (y[k]+1000000000) / 20) {
					if (w == x[k])box = max(box, abs(h - y[k]));
					else box = max(box, abs(w - x[k]) + min(40 - (h % 20 + y[k] % 20), (h % 20 + y[k] % 20)));
				}
				else {
					box = max(box, abs(h - y[k]) + abs(w - x[k]));
				}
			}
			//cout << w << " " << h << " " << box << endl;
			ans = min(ans, box);
		}
	}
	cout << ans / 2;
	if (ans & 1)cout << "." << 5;
	cout << endl;
}
