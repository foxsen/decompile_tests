#include <bits/stdc++.h>
using namespace std;
struct ACM {
  int T[300010][26], ed[300010], fail[300010], last[300010], cnt, val[300010];
  multiset<int> S[300010];
  void insert(char *s, int idx) {
    int o = 0;
    for (int i = 0; s[i]; ++i) {
      int v = s[i] - 97;
      if (!T[o][v]) T[o][v] = ++cnt;
      o = T[o][v];
    }
    ed[idx] = o, val[idx] = 0, S[o].insert(0);
  }
  void build() {
    for (int i = 0; i <= cnt; ++i) S[i].insert(-1);
    queue<int> q;
    for (int i = 0; i < 26; ++i)
      if (T[0][i]) fail[T[0][i]] = 0, q.push(T[0][i]);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      last[x] = S[fail[x]].size() > 1 ? fail[x] : last[fail[x]];
      for (int i = 0; i < 26; ++i)
        if (T[x][i]) {
          fail[T[x][i]] = T[fail[x]][i];
          q.push(T[x][i]);
        } else
          T[x][i] = T[fail[x]][i];
    }
  }
  void change(int x, int idx) {
    int pos = ed[idx];
    S[pos].erase(S[pos].find(val[idx]));
    val[idx] = x, S[pos].insert(x);
  }
  int ask(char *s) {
    int ans = -1, o = 0;
    for (int i = 0; s[i]; ++i) {
      int v = s[i] - 97, t;
      for (t = o = T[o][v]; t; t = last[t]) ans = max(ans, *S[t].rbegin());
    }
    return ans;
  }
} ac;
char s[300010];
inline void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s), ac.insert(s, i);
  ac.build();
  while (m--) {
    int op, i, x;
    scanf("%d", &op);
    if (op == 1)
      scanf("%d%d", &i, &x), ac.change(x, i);
    else
      scanf("%s", s), printf("%d\n", ac.ask(s));
  }
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
}
