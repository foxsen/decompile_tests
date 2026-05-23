#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = (int)1e9 + 7;
const int MAXN = (int)3e6 + 7;
struct line {
  long long slope, delta;
  line() {}
  line(long long k, long long c) {
    slope = k;
    delta = c;
  }
  friend bool operator<(line a, line b) {
    if (a.slope != b.slope) return a.slope < b.slope;
    return a.delta < b.delta;
  }
};
double intersection(line x, line y) {
  return (double)(x.delta - y.delta) / (double)(y.slope - x.slope);
}
const long long SOSMALL = -(1LL << 62);
long long optima(vector<line> &st, int x) {
  if (st.empty()) return SOSMALL;
  int l = 0, r = (int)st.size();
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (intersection(st[mid], st[mid + 1]) <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  long long optimus = SOSMALL;
  for (int i = max(0, l - 5); i < min(l + 5, (int)st.size()); i++)
    optimus = max(optimus, st[i].delta + st[i].slope * 1ll * x);
  return optimus;
}
vector<line> lazy[MAXN];
vector<int> query[MAXN];
int n;
int t[MAXN];
int a[MAXN];
int b[MAXN];
int en[MAXN];
void add(int l, int r, line x, int v = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return;
  if (l <= tl && tr <= r) {
    lazy[v].push_back(x);
    return;
  }
  int mid = (tl + tr) / 2;
  add(l, r, x, v + v, tl, mid);
  add(l, r, x, v + v + 1, mid + 1, tr);
}
void add_line(vector<line> &st, line w) {
  while (st.size() > 1 && intersection(st[st.size() - 2], st[st.size() - 1]) >
                              intersection(st[st.size() - 2], w))
    st.pop_back();
  st.push_back(w);
}
vector<line> calc(vector<line> st) {
  sort(st.begin(), st.end());
  vector<line> res;
  for (auto it : st) {
    while (!res.empty() && res.back().slope == it.slope) {
      assert(it.delta >= res.back().delta);
      res.pop_back();
    }
    res.push_back(it);
  }
  return res;
}
void traverse(int v = 1, int tl = 1, int tr = n) {
  auto tmp = calc(lazy[v]);
  lazy[v].clear();
  for (auto it : tmp) {
    add_line(lazy[v], it);
  }
  if (tl != tr) {
    int mid = (tl + tr) / 2;
    traverse(v + v, tl, mid);
    traverse(v + v + 1, mid + 1, tr);
  }
}
void dfs(int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    if (query[tl].empty()) return;
    long long ans = SOSMALL;
    for (int i = v; i > 0; i /= 2)
      ans = max(ans, optima(lazy[i], query[tl][0]));
    if (ans == SOSMALL) {
      puts("EMPTY SET");
    } else {
      printf("%lld\n", ans);
    }
  } else {
    int mid = (tl + tr) / 2;
    dfs(v + v, tl, mid);
    dfs(v + v + 1, mid + 1, tr);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &t[i], &a[i]);
    if (t[i] == 1) {
      scanf("%d", &b[i]);
    } else if (t[i] == 2) {
      en[a[i]] = i;
    } else {
      query[i].push_back(a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      if (!en[i]) en[i] = n;
      add(i, en[i], line(a[i], b[i]));
    }
  }
  traverse();
  dfs();
  return 0;
}
