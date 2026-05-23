#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define int long long
#define ull unsigned long long
#define fi first
#define se second
#define mpr make_pair
#define dingyi int mid = l + r >> 1, ls = p << 1, rs = p << 1 | 1
#define y0 y_csyakioi_0
#define y1 y_csyakioi_1
#define rep(i, x, y) for(int i = x; i <= y; ++i)
#define per(i, x, y) for(int i = x; i >= y; --i)
#define repg(i, u) for(int i = head[u]; i; i = e[i].nxt)
inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x * 10 + (ch ^ 48); ch = getchar(); }
	return x * f;
}
const int N = 200010;
struct edge{ int v, nxt; } e[N << 1]; int head[N], cnt;
int n, m, p[N], a[N], b[N], dis[N], dep[N], f[N][20], c[N], sta[N], len, num[N], ans;
set <int> st; set <int> ::iterator it; bool vis[N];
inline void add(int u, int v){ e[++cnt].v = v; e[cnt].nxt = head[u]; head[u] = cnt; }
inline void dfs(int u){
	dep[u] = dep[f[u][0]] + 1;
	rep(j, 1, 18) f[u][j] = f[f[u][j - 1]][j - 1];
	repg(i, u) dfs(e[i].v); 
}
inline int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y); per(i, 18, 0) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x; per(i, 18, 0) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline int pat(int x, int y){ return dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
inline void Insert(int x){
	it = st.insert(x).fi; int y = *(--it); ++it; ++it;
	int z = ((it == st.end()) ? *st.begin() : *it);
	ans += pat(y, x) + pat(x, z) - pat(y, z);
}
inline void Delete(int x){
	it = st.find(x); int y = *(--it); ++it; ++it;
	int z = ((it == st.end()) ? *st.begin() : *it);
	ans -= pat(y, x) + pat(x, z) - pat(y, z);
	--it; st.erase(it);
} 
inline void mian(){
	n = read(); m = read();
	rep(i, 1, n){
		p[i] = read(); while(p[sta[len]] < p[i] && len) --len;
		f[i][0] = sta[len]; add(sta[len], i); sta[++len] = i;
	} dfs(0);
	rep(i, 1, n) a[i] = read(), c[i] += a[i];
	rep(i, 1, n) b[i] = read(), c[i] -= b[i], c[f[i][0]] += b[i];
	per(i, n, 1) dis[i] += c[i], dis[f[i][0]] += min(dis[i], 0ll), dis[i] -= min(0ll, dis[i]);
	dis[0] += c[0]; rep(i, 1, n) dis[i] += dis[f[i][0]]; num[0] = 1; st.insert(0);
	while(m--){
		int x = read();
		if(vis[x]){
			vis[x] = 0;
			if(!(--num[f[x][0]])) Delete(f[x][0]);
		}
		else{
			vis[x] = 1;
			if(!(num[f[x][0]]++)) Insert(f[x][0]);
		}
		printf("%lld\n", ans / 2 + dis[0]);
	}
}
signed main(){ int qwq = 1; while(qwq--) mian(); return 0; }