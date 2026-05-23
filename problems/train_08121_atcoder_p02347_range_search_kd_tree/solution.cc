#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1 << 30;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 500000;

struct Node {int location, p, l, r;};
struct Point {int id, x, y;};

int np = 0;
Node T[N];
Point P[N];
vi ans;

bool lessX(const Point &a, const Point &b) { return a.x < b.x;}
bool lessY(const Point &a, const Point &b) { return a.y < b.y;}

int makekDTree(int l, int r, int d) {
	if (l >= r) return -1;
	if (d%2 == 0) sort(P+l, P+r, lessX);
	else sort(P+l, P+r, lessY);
	int mid = (l+r)/2;
	int t = np++;
	T[t].location = mid;
	T[t].l = makekDTree(l, mid, d+1);
	T[t].r = makekDTree(mid+1, r, d+1);
	return t;
}

void find(int v, int sx, int tx, int sy, int ty, int d) {
	int i = T[v].location, x = P[i].x, y = P[i].y;
	if (sx <= x && x <= tx && sy <= y && y <= ty) ans.push_back(P[i].id);
	if (d%2 == 0) {
		if (T[v].l != -1 && sx <= x) find(T[v].l, sx, tx, sy, ty, d+1);
		if (T[v].r != -1 && x <= tx) find(T[v].r, sx, tx, sy, ty, d+1);
	}
	else {
		if (T[v].l != -1 && sy <= y) find(T[v].l, sx, tx, sy, ty, d+1);
		if (T[v].r != -1 && y <= ty) find(T[v].r, sx, tx, sy, ty, d+1);
	}
}

int main() {
	int n; cin >> n;
	rep(i, n) {
		scanf("%d %d", &P[i].x, &P[i].y);
		P[i].id = i;
	}
	int root = makekDTree(0, n, 0);
	int q; cin >> q;
	rep(i, q) {
		int sx, tx, sy, ty;
		scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
		ans.clear();
		find(root, sx, tx, sy, ty, 0);
		sort(ans.begin(), ans.end());
		for(auto i : ans) printf("%d\n", i);
		printf("\n");
	}
}

