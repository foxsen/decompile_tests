#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int maxn = 1e5 + 11;

ll ans;
struct point {
	int num, val;
}a[maxn];
int n;
int tree[maxn], ran[maxn];

bool cmp(point q, point p) {
	if (q.val == p.val) 
		return q.num < p.num;
	return q.val < p.val;
}

int lowbit(int x) {return x & (-x);}

void update(int pos, int x) {
	for (int i = pos; i <= n; i += lowbit(i)) 
		tree[i] += x;
}

int query(int n) {
	int ans = 0;
	for (int i = n; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}


void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].val), a[i].num = i;
	sort(a + 1, a + 1 + n, [&](point a, point b) -> bool {
		return a.val < b.val;
	});

	int pre = 0, now = 0;
	int l = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i].val != a[i + 1].val) {
			int r = i;
			if (r == l) {
				int x = (i - a[i].num == 0 ? 0 :
				(i - a[i].num > 0 ? i - a[i].num : a[i].num - i));
				if (x & 1) {
					printf("NO\n");
					return;
				}
			} else {
				int odd0 = 0, odd1 = 0;
				//printf("l = %d, r = %d\n", l, r);
				for (int i = l; i <= r; ++i) {
					if (i & 1) odd0++;
					if (a[i].num & 1) odd1++;
				}
				if (odd0 != odd1) {
					printf("NO\n");
					return ;
				}
			}
			l = i + 1;
		}
		// else if (a[i].val == a[i + 1].val) {
		// 	l = i;
		// }
	}
	printf("YES\n");
	
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}