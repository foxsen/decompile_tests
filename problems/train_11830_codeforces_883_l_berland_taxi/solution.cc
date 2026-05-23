#include <bits/stdc++.h>
using namespace std;
multiset<int> W;
set<pair<long long, long long> > S[200020];
struct str {
  str() {}
  str(long long tm, int c, int b) : tm(tm), c(c), b(b) {}
  long long tm;
  int c, b;
  bool operator>(const str &rhs) const { return tm > rhs.tm; }
};
priority_queue<str, vector<str>, greater<str> > pq;
void solve() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    S[x].insert(pair<long long, long long>(0, i));
    W.insert(x);
  }
  long long fm = 0;
  for (int i = 1; i <= m; i++) {
    long long t;
    int a, b;
    scanf("%lld%d%d", &t, &a, &b);
    fm = max(fm, t);
    while (!pq.empty() && pq.top().tm <= fm) {
      auto e = pq.top();
      pq.pop();
      W.insert(e.b);
      S[e.b].insert(pair<long long, long long>(e.tm, e.c));
    }
    if (((int)(W).size()) == 0) {
      fm = pq.top().tm;
      while (!pq.empty() && pq.top().tm == fm) {
        auto e = pq.top();
        pq.pop();
        W.insert(e.b);
        S[e.b].insert(pair<long long, long long>(e.tm, e.c));
      }
    }
    auto it = W.lower_bound(a);
    int idis = 1e9, jdis = 1e9;
    if (it != W.end()) idis = *it - a;
    auto jt = it;
    if (it != W.begin()) jt = prev(it), jdis = a - *jt;
    pair<long long, long long> tex = pair<long long, long long>(-1, -1);
    if (idis < jdis || (idis == jdis && *S[*it].begin() < *S[*jt].begin())) {
      tex = *S[*it].begin();
      S[*it].erase(S[*it].begin());
      W.erase(it);
      long long det = fm + idis + abs(a - b);
      pq.push(str(det, (int)tex.second, b));
      printf("%d %lld\n", (int)tex.second, fm + idis - t);
    } else {
      tex = *S[*jt].begin();
      S[*jt].erase(S[*jt].begin());
      W.erase(jt);
      long long det = fm + jdis + abs(a - b);
      pq.push(str(det, (int)tex.second, b));
      printf("%d %lld\n", (int)tex.second, fm + jdis - t);
    }
  }
}
int main() {
  int Tc = 1;
  for (int tc = 1; tc <= Tc; tc++) {
    solve();
  }
  return 0;
}
