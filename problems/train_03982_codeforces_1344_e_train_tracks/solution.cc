#include <bits/stdc++.h>
using namespace std;
const long long iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const long long maxn = 1e5 + 5;
struct edge {
  long long u, w, i;
};
vector<edge> g[maxn];
long long par[maxn], head[maxn], hv[maxn], sz[maxn], dep[maxn], wdep[maxn],
    last[maxn], which[maxn];
long long stp[maxn], enp[maxn], nof[maxn];
bool hasch[maxn];
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    pq[maxn];
long long lastedge[maxn], lasttime[maxn];
void dfs1(long long v, long long p) {
  sz[v] = 1;
  par[v] = p;
  long long bigsz = 0;
  for (edge e : g[v]) {
    if (e.u != p) {
      hasch[v] = 1;
      which[e.u] = e.i;
      par[e.u] = v;
      dep[e.u] = dep[v] + 1;
      wdep[e.u] = wdep[v] + e.w;
      lastedge[v] = e.i;
      dfs1(e.u, v);
      sz[v] += sz[e.u];
      if (sz[e.u] > bigsz) {
        hv[v] = e.u;
        bigsz = sz[e.u];
      }
    }
  }
  if (lastedge[v] == which[hv[v]]) {
    lastedge[v] = -1;
  }
  if (!hasch[v]) {
    lastedge[v] = -2;
  }
}
void dfs2(long long v, long long p) {
  nof[head[v]]++;
  if (lastedge[v] >= 0) {
    pq[head[v]].push({dep[v], v});
    ;
  }
  for (edge e : g[v]) {
    if (e.u == p) continue;
    if (hv[v] == e.u) {
      head[e.u] = head[v];
    } else {
      head[e.u] = e.u;
    }
    dfs2(e.u, v);
  }
}
vector<pair<long long, long long> > flist;
void add(long long v, long long t, long long pt) {
  flist.push_back({pt == 0 ? 0 : pt + wdep[v], t + wdep[v]});
}
long long second[maxn * 2];
void MO(long long p, long long v) {
  for (second[p += maxn] = v; p > 1; p >>= 1) {
    second[p >> 1] = max(second[p], second[p ^ 1]);
  }
}
long long QU(long long l, long long r) {
  long long re = 0;
  for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
    if (l & 1) re = max(re, (__typeof__(re))(second[l++]));
    if (r & 1) re = max(re, (__typeof__(re))(second[--r]));
  }
  return re;
}
void go(long long v, long long t) {
  while (1) {
    ;
    long long H = head[v];
    while (!pq[H].empty() && pq[H].top().first < dep[v]) {
      long long u = pq[H].top().second;
      assert(lastedge[u] != -1);
      add(u, t, lasttime[u]);
      lastedge[u] = -1;
      pq[H].pop();
    }
    if (v != H) {
      MO(stp[H] + (dep[par[v]] - dep[H]), t);
      ;
    }
    v = H;
    if (v == 0) break;
    if (lastedge[par[v]] != which[v]) {
      long long pt = -1;
      if (lastedge[par[v]] == -1) {
        pq[head[par[v]]].push({dep[par[v]], par[v]});
        pt = QU(stp[head[par[v]]] + (dep[par[v]] - dep[head[par[v]]]),
                enp[head[par[v]]]);
        ;
      } else {
        pt = lasttime[par[v]];
      }
      lastedge[par[v]] = which[v];
      add(par[v], t, pt);
      ;
    }
    lasttime[par[v]] = t;
    v = par[v];
  }
}
struct EE {
  long long t, to;
  bool qu;
  bool operator<(const EE &b) const { return t != b.t ? t < b.t : qu > b.qu; }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n - 1; ++i) {
    long long a, b, w;
    cin >> a >> b >> w;
    --a;
    --b;
    g[a].push_back({b, w, i});
  }
  dfs1(0, -1);
  dfs2(0, -1);
  long long NOW = 0;
  for (long long i = 0; i < n; ++i) {
    if (head[i] == i) {
      stp[i] = NOW;
      enp[i] = NOW + nof[i];
      NOW += nof[i];
      ;
    }
  }
  for (long long i = 0; i < n; ++i)
    ;
  for (long long j = 0; j < m; ++j) {
    long long v, t;
    cin >> v >> t;
    --v;
    go(v, t);
  }
  long long prv = 0;
  vector<EE> ev;
  for (pair<long long, long long> &p : flist) {
    ev.push_back({p.first, p.second, 0});
    ev.push_back({p.second, -1, 1});
  }
  vector<long long> tyd;
  priority_queue<long long, vector<long long>, greater<long long> > fr;
  sort(ev.begin(), ev.end());
  long long ret = inf;
  for (EE e : ev) {
    for (long long j = 0; j < e.t - prv; ++j) {
      if (!fr.empty()) {
        tyd.push_back(fr.top());
        fr.pop();
      } else
        break;
    }
    if (e.qu) {
      if (!fr.empty() && fr.top() <= e.t) {
        assert(fr.top() == e.t);
        ret = e.t;
        break;
      }
    } else {
      fr.push(e.to);
    }
    prv = e.t;
  }
  long long nofsmol = 0;
  for (long long x : tyd) nofsmol += (x < ret);
  ;
  if (ret == inf) ret = -1;
  cout << ret << ' ' << nofsmol << '\n';
}
