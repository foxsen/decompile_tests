#include <bits/stdc++.h>
using namespace std;
long long pow(long long b, long long e, long long m) {
  long long t = 1;
  for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0;
  return t;
}
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T x, T y) {
  for (T t; x; t = x, x = y % x, y = t)
    ;
  return y;
}
template <class edge>
struct Graph {
  vector<vector<edge> > adj;
  Graph(int n) {
    adj.clear();
    adj.resize(n + 5);
  }
  Graph() { adj.clear(); }
  void resize(int n) { adj.resize(n + 5); }
  void add(int s, edge e) { adj[s].push_back(e); }
  void del(int s, edge e) { adj[s].erase(find(iter(adj[s]), e)); }
  vector<edge> &operator[](int t) { return adj[t]; }
};
const int maxn = 6600;
struct line {
  double dx, y;
  int k;
};
vector<line> f, g;
double x[maxn], remL, opt[maxn], ans[maxn];
void push(line x) {
  chkmin(x.dx, remL);
  remL -= x.dx;
  if (x.dx > 1e-9) {
    f.push_back(x);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  double Q, A, B;
  cin >> n >> Q >> A >> B, B -= A;
  cout << setprecision(15);
  cerr << setprecision(15);
  g.push_back((line){Q, 0, 0});
  pair<long double, double> minval;
  long double cost = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (i <= n) {
      int tmp;
      cin >> tmp;
      x[i] = tmp;
    }
    double lmt = A * (i - 1) + 1, vx = 0;
    x[i] -= lmt, remL = Q - lmt;
    f.clear();
    long double nowval = cost;
    minval = make_pair(cost, 0);
    bool b = false;
    for (vector<line>::iterator L = g.begin(); L != g.end(); ++L) {
      double ny = L->y + L->dx * L->k;
      if (L->y <= 0 && ny >= 0 && !b) {
        double xs;
        if (L->k == 0) {
          xs = 0;
        } else {
          xs = -L->y / L->k;
        }
        if (xs) push((line){xs, L->y, L->k});
        if (B) push((line){B, 0, 0});
        if (L->dx - xs) push((line){L->dx - xs, 0, L->k});
        b = true;
        chkmin(minval,
               make_pair(nowval + L->y * xs * 2 + xs * xs * L->k, vx + xs));
      } else if (L->y < 0) {
        push(*L);
      } else {
        if (!b && B) {
          push((line){B, 0, 0});
          b = true;
        }
        push(*L);
      }
      vx += L->dx;
      nowval += L->y * L->dx * 2 + L->dx * L->dx * L->k;
      chkmin(minval, make_pair(nowval, vx));
    }
    double xs = 0;
    for (vector<line>::iterator L = f.begin(); L != f.end(); ++L) {
      ++L->k;
      L->y += xs - x[i];
      xs += L->dx;
    }
    g = f;
    cost += sqr(x[i]);
    opt[i - 1] = minval.second;
  }
  double vx = minval.second, trans = 0;
  for (int lv = n; lv; --lv) {
    trans += sqr(vx - x[lv]);
    ans[lv] = vx;
    if (vx >= opt[lv - 1]) {
      vx = max(opt[lv - 1], vx - B);
    }
  }
  for (int lv = 1; lv <= n; ++lv) {
    cout << ans[lv] + (lv - 1) * A + 1 << " ";
  }
  cerr << cost << endl;
  cout << endl << trans << endl;
  return 0;
}
