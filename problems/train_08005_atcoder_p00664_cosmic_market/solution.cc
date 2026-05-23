#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
#pragma warning(disable:4996)
int H, W, Q, a[60000], b[60000], c[60000], d[60000], e, f, g;
int main() {
	while (true) {
		cin >> H >> W >> Q; if (H == 0)break;
		for (int i = 0; i < H; i++) { a[i] = -1; c[i] = 0; }
		for (int i = 0; i < W; i++) { b[i] = -1; d[i] = 0; }
		for (int i = 0; i < Q; i++) {
			scanf("%d%d%d", &e, &f, &g);
			if (e == 0) { a[f] = i; c[f] = g; }
			if (e == 1) { b[f] = i; d[f] = g; }
		}
		long long R1 = 0, R2 = 0, M = 0, cnt = 0;
		vector<tuple<int, int, int>>tup;
		for (int i = 0; i < H; i++)tup.push_back(make_tuple(a[i], 0, c[i]));
		for (int i = 0; i < W; i++)tup.push_back(make_tuple(b[i], 1, d[i]));
		sort(tup.begin(), tup.end());
		for (int i = 0; i < tup.size(); i++) {
			int a1 = get<0>(tup[i]), a2 = get<1>(tup[i]), a3 = get<2>(tup[i]);
			if (a2 == 0)R1++; if (a2 == 1)R2++;
			if (a3 == 1)cnt += R1*R2 - M; M = R1*R2;
		}
		cout << cnt << endl;
	}
	return 0;
}