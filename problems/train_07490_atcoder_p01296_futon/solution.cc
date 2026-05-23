#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define pb push_back
#define fs first
#define sc second
#define openfile {freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
#define debug 0

struct cell
{
	int x, y;
	int vt;
};

struct futon
{
	cell a, b;
};

const int MAXN = 20005;
const int mov[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int col[MAXN];
vector <int> adj[MAXN];
futon a[MAXN];
cell b[MAXN * 2];
int n, m;
bool ok;

void rset()
{
	m = 0;
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	memset(col, 0, sizeof col);
}

bool mycmp(const cell &a, const cell &b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int bs2(int trai, int phai, int y)
{
	int L = trai, R = phai, mid;
	while (L + 1 < R)
	{
		mid = (L + R) / 2;
		if (b[mid].y < y) L = mid;
		else R = mid;
	}
	if (b[L].y == y) return b[L].vt;
	else if (b[R].y == y) return b[R].vt;
	return -1;
}

int bs1(int x, int y)
{
	int trai, phai;

	int L = 1, R = m, mid;
	while (L + 1 < R)
	{
		mid = (L + R) / 2;
		if (b[mid].x < x) L = mid;
		else R = mid;
	}
	if (b[L].x == x) trai = L;
	else if (b[R].x == x) trai = R;
	else return -1;

	L = 1, R = m;
	while (L + 1 < R)
	{
		mid = (L + R) / 2;
		if (b[mid].x > x) R = mid;
		else L = mid;
	}
	if (b[R].x == x) phai = R;
	else if (b[L].x == x) phai = L;
	else return -1;

	return bs2(trai, phai, y);
}

void init()
{
	sort(b+1, b+m+1, mycmp);
	for (int i = 1; i <= m; i++)
	for (int j = 0; j < 4; j++)
	{
		int x = b[i].x + mov[j][0], y = b[i].y + mov[j][1];
		int k = bs1(x, y);
		if (k == -1) continue;
		if (k != b[i].vt) adj[b[i].vt].pb(k), adj[k].pb(b[i].vt);
	}
}

bool isKe(cell a, cell b)
{
	for (int i = 0; i < 4; i++)
	{
		int x = a.x + mov[i][0], y = a.y + mov[i][1];
		if (x == b.x && y == b.y) return true;
	}
	return false;
}

void dfs(int u)
{
	for (int i = 0; i < (int)adj[u].size() && ok; i++)
	{
		int v = adj[u][i];
		if (!col[v])
		{
			if (isKe(a[v].a, a[u].a))
			{
				if (col[u] == 1) col[v] = 1;
				else col[v] = 2;
			}
			else if (isKe(a[v].a,a[u].b))
			{
				if (col[u] == 1) col[v] = 2;
				else col[v] = 1;
			}
			else if (isKe(a[v].b,a[u].a))
			{
				if (col[u] == 1) col[v] = 2;
				else col[v] = 1;
			}
			else
			{
				if (col[u] == 1) col[v] = 1;
				else col[v] = 2;
			}
			dfs(v);
		}
		else
		{
			if (isKe(a[v].a, a[u].a))
			{
				if (col[u] != col[v]) { ok = false; return; }
			}
			else if (isKe(a[v].a,a[u].b))
			{
				if (col[u] == col[v]) { ok = false; return; }
			}
			else if (isKe(a[v].b,a[u].a))
			{
				if (col[u] == col[v]) { ok = false; return; }
			}
			else
			{
				if (col[u] != col[v]) { ok = false; return; }
			}
		}
	}
}

void solve()
{
	ok = true;
	for (int i = 1; i <= n; i++)
	{
		if (col[i]) continue;

		col[i] = 1;
		dfs(i);
		if (ok) continue;

		col[i] = 2;
		dfs(i);
		if (!ok)
		{
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main()
{
   if (debug) openfile;

   while (scanf("%d", &n) && n)
	{
		rset();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].a.x, &a[i].a.y);
			b[++m] = a[i].a;
			b[m].vt = i;
			char ch;
			scanf("%c%c", &ch, &ch);
			if (ch == 'x')
			{
				a[i].b.x = a[i].a.x + 1;
				a[i].b.y = a[i].a.y;
			}
			else
			{
				a[i].b.x = a[i].a.x;
				a[i].b.y = a[i].a.y + 1;
			}
			b[++m] = a[i].b;
			b[m].vt = i;
			scanf("%c", &ch);
		}
		init();
		solve();
	}

   return 0;
}