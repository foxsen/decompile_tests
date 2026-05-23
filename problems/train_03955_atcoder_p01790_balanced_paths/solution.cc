#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std; 
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	x *= f; 
}
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
char s[maxn];
int head[maxn];
struct edge {
	int to, nex;
	edge(int to=0,int nex=0):to(to),nex(nex){}
};
vector<edge> G;
inline void addedge(int u, int v) {
	G.push_back(edge(v, head[u])), head[u] = G.size() - 1;
	G.push_back(edge(u, head[v])), head[v] = G.size() - 1;
}
namespace dvt {
	ll an;
	int k;
	int sum;
	int maxlen;
	int cnt[maxn];
	int siz[maxn];
	int son[maxn];
	char ch;
	bool mark[maxn];
	void getpoint(int u, int fa) {
		siz[u] = 1;
		son[u] = 0;
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(v == fa || mark[v]) continue; 
			getpoint(v, u);
			siz[u] += siz[v];
			son[u] = max(son[u], siz[v]);
		}
		son[u] = max(son[u], sum - siz[u]);
		if(k == -1 || son[k] > son[u]) k = u; 
	}
	void rebuild(int u, int fa) {
		siz[u] = 1;
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(v == fa || mark[v]) continue;
			rebuild(v, u);
			siz[u] += siz[v];
		}
	}
	void findan(int u, int fa, int now, int sum) {
		if(s[u] == ch) {
			if(now) --now;
			else ++sum;
		}
		else {
			++now;
		}
		if(now == 0) an += cnt[sum]; 
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(v == fa || mark[v]) continue;
			findan(v, u, now, sum);
		}
	}
	void update(int u, int fa, int now, int sum) {
		if(s[u] != ch) {
			if(now) --now;
			else ++sum;
		}
		else {
			++now;
		}
		if(now == 0) {
			++cnt[sum];
			if(sum > maxlen) maxlen = sum;
		}
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(v == fa || mark[v]) continue;
			update(v, u, now, sum);
		}
	}
	void divide(int u) {
		mark[u] = 1, rebuild(u, -1);
		maxlen = 0;
		if(s[u] != ch) {
			cnt[1] = maxlen = 1; 
		} 
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(mark[v]) continue; 
			findan(v, u, 0, 0); 
			if(s[u] != ch) update(v, u, 0, 1);
			else update(v, u, 1, 0);
		}
		for(int i = 0; i <= maxlen; ++i) cnt[i] = 0;
		for(int i = head[u]; ~i; i = G[i].nex) {
			int v = G[i].to; if(mark[v]) continue;
			k = -1, sum = siz[v], getpoint(v, u);
			divide(k);
//			debug("%d %d\n", u, k);
		}
	}
	ll solve() {
		ch = '(';
		k = -1, sum = n, getpoint(1, -1);
		divide(k);
		memset(mark, 0, sizeof(mark));
		ch = ')';
		k = -1, sum = n, getpoint(1, -1);
		divide(k);
		return an;
	}
}
int main() {
	read(n);
	scanf("%s", s + 1);
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; ++i) {
		int u, v; read(u), read(v);
		addedge(u, v);
	} 
	printf("%lld\n", dvt :: solve());
	return 0; 
}
