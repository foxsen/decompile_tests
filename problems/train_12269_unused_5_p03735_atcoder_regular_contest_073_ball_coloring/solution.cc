#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long lint;
typedef pair<lint, int> pli;

#define MAXN 200005

const lint LINF = 1e9;
lint X[MAXN], Y[MAXN];
pli d[2 * MAXN];
int cnt[MAXN];
int col;

int main() {
	int N;
	lint ans;

	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%lld%lld", X + i, Y + i);

	lint rmn = LINF, rmx = 0, bmn = LINF, bmx = 0;
	for(int i = 0; i < N; i++) {
		if(X[i] > Y[i]) swap(X[i], Y[i]);
		rmn = min(rmn, X[i]);
		rmx = max(rmx, X[i]);
		bmn = min(bmn, Y[i]);
		bmx = max(bmx, Y[i]);
	}
	ans = (rmx - rmn) * (bmx - bmn);
	for(int i = 0; i < N; i++) {
		d[i * 2] = make_pair(X[i], i);
		d[i * 2 + 1] = make_pair(Y[i], i);
	}

	sort(d, d + 2 * N);
	int s = 0, e = 0;
	while(true) {
		while(e < 2 * N && col < N)
			if(cnt[d[e++].second]++ == 0) col++;
		if(col < N) break;
		//printf("s = %d, e = %d\n", s, e);
		ans = min((d[N * 2- 1].first - d[0].first) * (d[e - 1].first - d[s].first), ans);
		if(cnt[d[s++].second]-- == 1) col--;
	}
	printf("%lld", ans);
	return 0;
}
