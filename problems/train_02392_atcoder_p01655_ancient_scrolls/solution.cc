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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

bool func(int asum, int bsum, int csum, vector<int>sum) {
	if (asum > M || bsum > M || csum > M)return false;
	int aadd = sum[3];
	int badd = sum[2];
	int cadd = sum[1];
	if (asum + aadd > M) {
		int box = asum + aadd - M;
		aadd -= box;
		badd += box;
		cadd += box;
	}
	if (bsum + badd > M) {
		int box = bsum + badd - M;
		badd -= box;
		aadd += box;
		cadd += box;
	}
	if (csum + cadd > M) {
		int box = csum + cadd - M;
		cadd -= box;
		badd += box;
		aadd += box;
	}
	aadd += sum[4];
	badd += sum[4];
	cadd += sum[4];
	int amari = sum[4];
	if (asum + aadd > M) {
		int box = min(amari, asum + aadd - (int)M);
		aadd -= box;
		amari -= box;
	}
	if (bsum + badd > M) {
		int box = min(amari, bsum + badd - (int)M);
		badd -= box;
		amari -= box;
	}
	if (csum + cadd > M) {
		int box = min(amari, csum + cadd - (int)M);
		cadd -= box;
		amari -= box;
	}
	return asum + aadd <= M && csum + cadd <= M && bsum + badd <= M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> N >> M, N) {
		string a, b, c;
		cin >> a >> b >> c;
		vector<int>num(N);
		vector<int>sum(5);
		for (int i = 0; i < N; i++) {
			if (a[i] == b[i] && a[i] != c[i])num[i] = 1;
			if (a[i] == c[i] && a[i] != b[i])num[i] = 2;
			if (b[i] == c[i] && b[i] != a[i])num[i] = 3;
			if (a[i] != b[i] && a[i] != c[i] && b[i] != c[i])num[i] = 4;
			sum[num[i]]++;
		}
		string ans = "-1";
		string ret;
		int asum = 0, bsum = 0, csum = 0;
		vector<char>check;
		for (char i = 'A'; i <= 'Z'; i++)check.push_back(i);
		for (char i = 'a'; i <= 'z'; i++)check.push_back(i);
		for (int i = 0; i < N; i++) {
			sum[num[i]]--;
			for (auto j : check) {
				asum += a[i] != j;
				bsum += b[i] != j;
				csum += c[i] != j;
			//	cout << j << " " << asum << " " << bsum << " " << csum << " " << endl;
			//	for (auto k : sum)cout << k << " ";
			//	cout << endl;
				if (func(asum, bsum, csum, sum)) {
					ret.push_back(j);
					break;
				}
				else {
					asum -= a[i] != j;
					bsum -= b[i] != j;
					csum -= c[i] != j;
				}
			}
		}
	//	cout << ret << endl;
		if (ret.size() == N)ans = ret;
		cout << ans << endl;
	}
}
