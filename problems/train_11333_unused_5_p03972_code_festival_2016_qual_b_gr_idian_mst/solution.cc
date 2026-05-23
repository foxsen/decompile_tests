#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int64_t W, H;
	cin >> W >> H;
	vector<int64_t> P;
	P.reserve(W + H);
	int64_t x;
	for (int i = 0; i < W + H; i++)
		cin >> x, P.push_back((x << 1) | (i < W));
	sort(P.begin(), P.end());
	W++, H++;
	int64_t r = 0;
	for (auto p : P) {
		int64_t t = p & 1;
		r += (p >> 1) * ((-t & H) + (~(-t) & W));
		H -= !t;
		W -= t;
	}
	cout << r << endl;
	return 0;
}
