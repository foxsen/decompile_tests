#include <bits/stdc++.h>
#define N 200010
using namespace std;

int n, q, data[N];
vector<int> edge[N];

int dfn[N], top[N], f[N], size[N], son[N], d[N];
int _index;
void dfs(int u, int fa) {
	f[u] = fa;
	d[u] = d[fa] + 1;
	size[u] = 1;
	for (int i = 0; i < edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v == fa) continue;
		dfs(v, u);
		size[u] += size[v];
		if (size[v] > size[son[u]]) son[u] = v;
	}
}

int val[N];
void build(int u, int tp) {
	top[u] = tp;
	dfn[u] = ++_index;
	val[_index] = data[u];
	if (son[u]) build(son[u], tp);
	for (int i = 0; i < edge[u].size(); ++i) {
		int v = edge[u][i];
		if (v != f[u] && v != son[u]) build(v, v);
	}
}

#define ls (x << 1)
#define rs (x << 1 | 1)

struct info {
	int max_l, max_r, max_mid, sum;
	info() {}
	info(int x) {
		max_l = max_r = max_mid = sum = x;
	}
	friend info operator + (const info &a, const info &b) {
		info res;
		res.sum = a.sum + b.sum;
		res.max_l = max(a.max_l, a.sum + max(0, b.max_l));
		res.max_r = max(b.max_r, b.sum + max(0, a.max_r));
		res.max_mid = max(max(a.max_mid, b.max_mid), max(max(a.max_r, 0) + b.max_l, a.max_r + max(b.max_l, 0)));
		return res;
	}
	inline info reverse() const {
		info res = *this;
		swap(res.max_l, res.max_r);
		return res;
	}
	void update(int val, int size) {
		sum = val * size;
		if (val > 0) max_l = max_r = max_mid = sum;
		else max_l = max_r = max_mid = val;
	}
};

struct node {
	info val;
	int lab;
	bool vis;
}tr[N << 2];

void buildTree(int x, int l, int r) {
	if (l == r) {
		tr[x].val = info(val[l]);
		tr[x].vis = 0;
		return;
	}
	int mid = l + r >> 1;
	buildTree(ls, l, mid);
	buildTree(rs, mid + 1, r);
	tr[x].val = tr[ls].val + tr[rs].val;
}

void push_down(int x, int l, int r) {
	if (!tr[x].vis) return;
	int mid = l + r >> 1;
	tr[ls].val.update(tr[x].lab, mid - l + 1);
	tr[ls].vis = 1;
	tr[ls].lab = tr[x].lab;
	tr[rs].val.update(tr[x].lab, r - mid);
	tr[rs].vis = 1;
	tr[rs].lab = tr[x].lab;
	tr[x].vis = 0;
}

void modify(int x, int l, int r, int a, int b, int val) {
	if (a <= l && r <= b) {
		tr[x].vis = 1;
		tr[x].lab = val;
		tr[x].val.update(val, r - l + 1);
		return;
	}
	push_down(x, l, r);
	int mid = l + r >> 1;
	if (a <= mid) modify(ls, l, mid, a, b, val);
	if (b > mid) modify(rs, mid + 1, r, a, b, val);
	tr[x].val = tr[ls].val + tr[rs].val;
//cout << l << ' ' << r << ' ' << tr[x].val.max_mid << ' ' << tr[x].val.max_l << ' ' << tr[x].val.max_r << endl;
}

info query(int x, int l, int r, int a, int b) {
	if (a <= l && r <= b) {
//cout << l << ' ' << r << ' ' << a << ' ' << b << ' ' << tr[x].val.max_mid << ' ' << endl;	
		return tr[x].val;
	}
	int mid = l + r >> 1;
	push_down(x, l, r);
	info res;
	if (b <= mid) {
		res = query(ls, l, mid, a, b);
	} else if (a > mid) {
		res = query(rs, mid + 1, r, a, b);
	} else {
		res = query(ls, l, mid, a, b) + query(rs, mid + 1, r, a, b);
	}
	tr[x].val = tr[ls].val + tr[rs].val;
	return res;
}

void modify(int x, int y, int c) {
	int fx = top[x], fy = top[y];
	while (fx != fy) {
		if (d[fx] < d[fy]) {
			swap(fx, fy);
			swap(x, y);
		}
		modify(1, 1, n, dfn[fx], dfn[x], c);
		x = f[fx];
		fx = top[x];
	}
	if (d[x] > d[y]) swap(x, y);
	modify(1, 1, n, dfn[x], dfn[y], c);
}

int query(int x, int y) {
	int fx = top[x], fy = top[y];
	info res_l, res_r;
	bool flag_l = 0, flag_r = 0;
	while (fx != fy) {
		if (d[fx] < d[fy]) {
			if (!flag_r) {
				flag_r = 1;
				res_r = query(1, 1, n, dfn[fy], dfn[y]);
			} else {
				res_r = query(1, 1, n, dfn[fy], dfn[y]) + res_r;
			}
			y = f[fy];
			fy = top[y];
		} else {
			if (!flag_l) {
				flag_l = 1;
				res_l = query(1, 1, n, dfn[fx], dfn[x]).reverse();
			} else {
				res_l = res_l + query(1, 1, n, dfn[fx], dfn[x]).reverse();
			}
			x = f[fx];
			fx = top[x];
		}
	}
	info res;
	if (d[x] < d[y]) {
		res = query(1, 1, n, dfn[x], dfn[y]);
	} else {
		res = query(1, 1, n, dfn[y], dfn[x]).reverse();
	}
	if (flag_l) res = res_l + res;
	if (flag_r) res = res + res_r;
	return res.max_mid;
}

int main() {
	// freopen("DD.in","r",stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &data[i]);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	build(1, 1);
	buildTree(1, 1, n);
	//for (int i = 1; i <= n; ++i) cout << top[i] << ' ' << f[i] << ' ' << son[i] << endl;
	for (int i = 1; i <= q; ++i) {
		int x, a, b, c;
		scanf("%d%d%d%d", &x, &a, &b, &c);
		if (x == 1) modify(a, b, c);
		else printf("%d\n", query(a, b));
	}
	return 0;
}