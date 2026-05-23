#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C, l[100009], c[100009], w[100009], p[100009];
int main() {
	cin >> N >> M >> C;
	for (int i = 0; i < C; i++) cin >> l[i];
	for (int i = 0; i < N; i++) cin >> c[i] >> w[i], p[i] = i, c[i]--;
	sort(p, p + N, [](int i, int j) { return w[i] > w[j]; });
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (l[c[p[i]]] > 0) {
			l[c[p[i]]]--;
			sum += w[p[i]];
			cnt++;
		}
		if (cnt == M) break;
	}
	cout << sum << endl;
	return 0;
}
