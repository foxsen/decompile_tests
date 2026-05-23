
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x.size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-------
const int N = 35353;
const ll INF = 1e18;
int n, m;
int a[N], last[N];
ll f[N];
struct SegmentTree {
    int n;
    std::vector<ll> mn, tag;
    SegmentTree(int n) : n(n), mn(4 * n, INF), tag(4 * n) {}
    void pull(int p) {
        mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
    }
    void push(int p) {
        add(2 * p, tag[p]);
        add(2 * p + 1, tag[p]);
        tag[p] = 0;
    }
    void add(int p, ll v) {
        mn[p] += v;
        tag[p] += v;
    }
    void rangeAdd(int p, int l, int r, int x, int y, ll v) {
        if (l > y || r < x) {
            return;
        }
        if (l >= x && r <= y) {
            add(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m + 1, r, x, y, v);
        pull(p);
    }
};
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) scanf("%d", a + i);
	rep(i, 0, n) a[i]--;
	fill_n(last, n, -1);
	fill_n(f, n, INF);
	f[0] = 0;
	ll ans = 0;
	rep(j, 0, m) {
		SegmentTree seg_tree(n);
		fill_n(last, n, -1);
		ll lastf = 0;
		rep(i, 1, n + 1) {
			auto & val = a[i - 1];
			seg_tree.rangeAdd(1, 0, n - 1, i - 1, i - 1, lastf - INF);
			if (last[val] != -1) {
				seg_tree.rangeAdd(1, 0, n - 1, 0, last[val], i - 1 - last[val]);
			}
			lastf = f[i];
			f[i] = seg_tree.mn[1];
			last[val] = i - 1;
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}
