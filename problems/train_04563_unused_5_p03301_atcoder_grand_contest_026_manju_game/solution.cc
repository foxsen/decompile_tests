#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 300000;
const int INF = (1 << 30);

int s[2], sum[MAXN + 5], a[MAXN + 5], N;
bool check(int x) {
	int k = 0;
	for(int i=2;i<=N;i+=2) {
		if( sum[i-1] - k >= x )
			k = min(k, sum[i]);
	}
	return sum[N] - k >= x;
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%d", &a[i]), s[i & 1] += a[i];
	if( N % 2 == 0 )
		printf("%d %d\n", max(s[0], s[1]), min(s[0], s[1]));
	else {
		for(int i=1;i<=N;i++) sum[i] = sum[i-1] + (i & 1 ? a[i] : -a[i]);
		int le = 0, ri = s[0] + s[1];
		while( le < ri ) {
			int mid = (le + ri + 1) >> 1;
			if( check(mid) ) le = mid;
			else ri = mid - 1;
		}
		printf("%d %d\n", s[0] + le, s[1] - le);
	}
}