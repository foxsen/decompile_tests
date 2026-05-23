#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(_i,_a,_n) for(int _i=_a;_i<=_n;++_i)
#define PER(_i,_a,_n) for(int _i=_n;_i>=_a;--_i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(_a) ({REP(_i,1,n) cout<<_a[_i]<<',';hr;})
using namespace std;
typedef long long ll;
const int N = 3e5+10, P = 998244353;
int n, m, vis[N], sg[N], h[N], f[3][N];
vector<int> g[N];
void add(int &a, ll b) {a=(a+b)%P;}

int main() {
	h[0] = 1;
	h[1] = 1000000000000000000ll%P;
	REP(i,2,N-1) h[i] = (ll)h[i-1]*h[1]%P;
	scanf("%d", &n);
int mx = 0;
	REP(i,0,2) {
		scanf("%d", &m);
mx = max(mx, int(sqrt(1+4*m)/2));
		REP(j,1,n) g[j].clear();
		REP(j,1,m) {
			int u,v;
			scanf("%d%d", &u, &v);
			if (u>v) swap(u,v);
			g[u].pb(v);
		}
		PER(j,1,n) {
			int sz = g[j].size();
			REP(k,0,sz) vis[k] = 0;
			for (int k:g[j]) vis[sg[k]] = 1;
			REP(k,0,sz) if (!vis[k]) {
				sg[j] = k;
				break;
			}
			add(f[i][sg[j]],h[j]);
		}
	}
mx=500;
	int ans = 0;
	REP(i,0,mx) REP(j,0,mx) {
		add(ans, (ll)f[0][i]*f[1][j]%P*f[2][i^j]);
	}
	printf("%d\n", ans);
}
