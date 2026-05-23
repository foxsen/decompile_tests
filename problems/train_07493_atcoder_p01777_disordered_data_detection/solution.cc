#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int D, Q, x[131072], ls, rs, es; vector<int> seg[262144];
int query1(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return 999999999;
	if (a <= l && r <= b) return seg[k].size() ? seg[k][0] : 999999999;
	int lc = query1(a, b, 2 * k, l, (l + r) / 2);
	int rc = query1(a, b, 2 * k + 1, (l + r) / 2, r);
	return min(lc, rc);
}
int query2(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return -999999999;
	if (a <= l && r <= b) return seg[k].size() ? seg[k][seg[k].size() - 1] : -999999999;
	int lc = query2(a, b, 2 * k, l, (l + r) / 2);
	int rc = query2(a, b, 2 * k + 1, (l + r) / 2, r);
	return max(lc, rc);
}
int query3(int a, int b, int x1, int x2, int k, int l, int r) {
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return lower_bound(seg[k].begin(), seg[k].end(), x2) - lower_bound(seg[k].begin(), seg[k].end(), x1);
	int lc = query3(a, b, x1, x2, 2 * k, l, (l + r) / 2);
	int rc = query3(a, b, x1, x2, 2 * k + 1, (l + r) / 2, r);
	return lc + rc;
}
int main() {
	scanf("%d", &D);
	for (int i = 0; i < D; i++) {
		scanf("%d", &x[i]);
		int t = i + 131072;
		while (t > 0) {
			seg[t].push_back(x[i]);
			t >>= 1;
		}
	}
	for (int i = 1; i < 262144; i++) {
		if (seg[i].size() > 1) {
			sort(seg[i].begin(), seg[i].end());
		}
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &ls, &rs, &es);
		int a = min(x[ls - 1], x[rs - 1]);// query1(ls - 1, rs, 1, 0, 131072);
		int b = max(x[ls - 1], x[rs - 1]);// query2(ls - 1, rs, 1, 0, 131072);
		printf("%d\n", rs - ls + 1 - query3(ls - 1, rs, a - es, b + es + 1, 1, 0, 131072));
	}
	return 0;
}