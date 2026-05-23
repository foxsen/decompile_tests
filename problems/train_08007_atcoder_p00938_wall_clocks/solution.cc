#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long H, W, N, L[100009], R[100009]; vector<long long>D;

long long solve(vector<pair<long long, long long>>V) {
	long long cnt = 0, res = 0, pos = 0;

	while (pos < V.size()) {
		while (pos < V.size() && V[pos].first <= res) {
			res = min(res, V[pos].second); pos++;
		}
		cnt++; res = (1 << 30);
	}
	return cnt;
}

int main() {
	cin >> N >> W >> H;
	for (int i = 0; i < N; i++) {
		int px, py; char c;
		cin >> px >> py >> c;

		if (c == 'N') {
			long long BASE = px;
			L[i] = BASE - (H - py); R[i] = BASE + (H - py);
		}
		if (c == 'E') {
			long long BASE = W + (H - py);
			L[i] = BASE - (W - px); R[i] = BASE + (W - px);
		}
		if (c == 'S') {
			long long BASE = W + H + (W - px);
			L[i] = BASE - py; R[i] = BASE + py;
		}
		if (c == 'W') {
			long long BASE = W + H + W + py;
			L[i] = BASE - px; R[i] = BASE + px;
		}
		L[i] += ((W + H) * 2); L[i] %= ((W + H) * 2);
		R[i] += ((W + H) * 2); R[i] %= ((W + H) * 2);
		D.push_back(L[i]);
		D.push_back(R[i]);
	}
	sort(D.begin(), D.end());
	D.erase(unique(D.begin(), D.end()), D.end());

	long long LENG = (H + W) * 2;
	long long ans = (1 << 30);

	for (int i = 0; i < D.size(); i++) {
		vector<pair<long long, long long>>vec;
		for (int j = 0; j < N; j++) {
			long long GL = (L[j] - D[i] + LENG) % LENG;
			long long GR = (R[j] - D[i] + LENG) % LENG;
			if (GL > GR) GL = 0;
			vec.push_back(make_pair(GL, GR));
		}
		sort(vec.begin(), vec.end());
		long long rem = solve(vec);
		ans = min(ans, rem);
	}
	cout << ans << endl;
	return 0;
}
