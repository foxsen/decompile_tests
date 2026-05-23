#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N, a[4][14], b[9];
char T[15] = "-A23456789TJQK";
char U[5] = "SCHD";
string S; pair<int, int>d[5];
int poker() {
	int e[14], f[9];
	int g[14], h[9];
	for (int i = 0; i < 14; i++) { e[i] = 0; g[i] = 0; }
	for (int i = 0; i < 9; i++) { f[i] = 0; h[i] = 0; }
	for (int i = 0; i < 5; i++) {
		e[d[i].first]++;
		f[d[i].second]++;
	}
	for (int i = 0; i < 14; i++) { g[e[i]]++; }
	for (int i = 0; i < 4; i++) { h[f[i]]++; }
	if (h[5] == 1) {
		if (d[0].first != 1) { goto E; }
		if (d[1].first != 10) { goto E; }
		if (d[2].first != 11) { goto E; }
		if (d[3].first != 12) { goto E; }
		if (d[4].first != 13) { goto E; }
		return 8; E:;
		for (int i = 1; i < 5; i++) {
			if (d[i].first != d[i - 1].first + 1) {
				goto F;
			}
		}
		return 7; F:;
		return 4;
	}
	if (g[4] == 1) { return 6; }
	if (g[2] == 1 && g[3] == 1) { return 5; }
	for (int i = 1; i < 5; i++) {
		if (d[i].first != d[i - 1].first + 1) {
			goto G;
		}
	}
	return 3; G:;
	if (d[0].first != 1) { goto H; }
	if (d[1].first != 10) { goto H; }
	if (d[2].first != 11) { goto H; }
	if (d[3].first != 12) { goto H; }
	if (d[4].first != 13) { goto H; }
	return 3; H:;
	if (g[3] == 1) { return 2; }
	if (g[2] == 2) { return 1; }
	if (g[2] == 1) { return 0; }
	return 9;
}
int main() {
	int cnt = 0;
	while (cin >> N) {
		if (cnt) { cout << endl; }
		cnt++;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 13; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 9; i++) { cin >> b[i]; }
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> S;
				for (int k = 0; k < 14; k++) {
					if (T[k] == S[0]) { d[j].first = k; }
				}
				for (int k = 0; k < 4; k++) {
					if (U[k] == S[1]) { d[j].second = k; }
				}
			}
			sort(d, d + 5);
			int A = b[poker()];
			int B = 0;
			for (int j = 0; j < 5; j++) {
				B += a[d[j].second][d[j].first];
			}
			cout << A*B << endl;
		}
	}
}