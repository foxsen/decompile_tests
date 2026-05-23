#include <bits/stdc++.h>
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
inline int read() {
  static int ans, f;
  static char ch;
  for (ch = (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))),
             ib == ob ? -1 : *ib++),
      f = 1;
       !isdigit(ch);
       ch = (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))),
             ib == ob ? -1 : *ib++),
      f ^= ch == '-')
    ;
  for (ans = 0; isdigit(ch); ans = ((ans << 2) + ans << 1) + (ch ^ 48),
      ch = (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))),
            ib == ob ? -1 : *ib++))
    ;
  return f ? ans : -ans;
}
namespace modular {
const int mod = 1e9 + 7;
inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
inline void Mul(int &a, int b) { a = (long long)a * b % mod; }
inline int ksm(int a, int p) {
  static int ret;
  for (ret = 1; p; p >>= 1, Mul(a, a)) {
    (p & 1) && (Mul(ret, a), 1);
  }
  return ret;
}
}  // namespace modular
using namespace modular;
const int N = 1e6 + 5, B = 1000;
int n, a[N];
int cnt[N], ct[N], tim, dep[N], fa[N];
vector<int> e[N];
int mn = 0x3f3f3f3f;
void bfs(int s) {
  queue<int> q;
  q.push(s);
  ct[s] = tim;
  dep[s] = 0;
  fa[s] = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (register int i = 0, v; i < e[p].size(); ++i) {
      v = e[p][i];
      if (ct[v] == ct[p]) {
        if (v != fa[p]) {
          mn = min(dep[p] + dep[v] + 1, mn);
        }
        continue;
      }
      fa[v] = p;
      ct[v] = tim;
      dep[v] = dep[p] + 1;
      q.push(v);
    }
  }
}
int main() {
  n = read();
  bool f1 = 0, f2 = 0;
  for (register int i = 1; i <= n; ++i) {
    a[i] = read();
    vector<int> ps;
    ps.resize(0);
    for (register int j = 2; j * j <= a[i]; ++j) {
      while (a[i] == a[i] / (j * j) * (j * j)) {
        a[i] /= j * j;
      }
      if (a[i] == a[i] / j * j) {
        ps.push_back(j);
        a[i] /= j;
      }
    }
    if (a[i] > 1) {
      ps.push_back(a[i]);
    }
    if (!ps.size()) {
      f1 = 1;
      break;
    }
    if (ps.size() == 1) {
      if (cnt[ps.back()]) {
        f2 = 1;
      }
      ++cnt[ps.back()];
      e[1].push_back(ps[0]);
      e[ps[0]].push_back(1);
      continue;
    }
    if (cnt[ps[0] * ps[1]]) {
      f2 = 1;
    }
    ++cnt[ps[0] * ps[1]];
    e[ps[0]].push_back(ps[1]);
    e[ps[1]].push_back(ps[0]);
  }
  if (f1) {
    cout << "1";
    return 0;
  }
  if (f2) {
    cout << "2";
    return 0;
  }
  dep[0] = -1;
  for (register int i = 1; i <= B; ++i) {
    tim = i;
    bfs(i);
  }
  if (mn == 0x3f3f3f3f) {
    cout << "-1";
  } else {
    cout << mn;
  }
  return 0;
}
