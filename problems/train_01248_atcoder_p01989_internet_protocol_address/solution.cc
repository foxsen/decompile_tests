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
#include "functional"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < i + 4; j++) {
			if (j >= s.size())break;
			for (int k = j + 1; k < j + 4; k++) {
				if (k >= s.size())break;
				for (int l = k + 1; l < k + 4; l++) {
					if (l + 1 != s.size()) {
						if (s[k + 1] == '0')break;
						continue;
					}
					if (l >= s.size())break;
					int a = 0, b = 0, c = 0, d = 0;
					for (int m = 0; m <= i; m++) {
						a *= 10;
						a += s[m] - '0';
					}
					for (int m = i + 1; m <= j; m++) {
						b *= 10;
						b += s[m] - '0';
					}
					for (int m = j + 1; m <= k; m++) {
						c *= 10;
						c += s[m] - '0';
					}
					for (int m = k + 1; m <= l; m++) {
						d *= 10;
						d += s[m] - '0';
					}
					//cout << i << " " << j << " " << k << " " << l << endl;
					//cout << a << " " << b << " " << c << " " << d << endl;
					if (a <= 255 && b <= 255 && c <= 255 && d <= 255)ans++;
					if (s[k + 1] == '0')break;
				}
				if (s[j + 1] == '0')break;
			}
			if (s[i + 1] == '0')break;
		}
		if (s[0] == '0')break;
	}
	cout << ans << endl;
}
