#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9 + 7;
const int Maxn = 5007;
int N, M;
char s[Maxn];
struct SAM {
  int endpos[2][Maxn * 4];
  int a[Maxn * 4], b[Maxn * 4];
  struct state {
    int len, link;
    map<char, int> next;
    void init() { len = 0, link = 0; }
  };
  state st[Maxn * 4];
  int sz, last;
  void sa_init() { sz = last = 1; }
  void sa_extend(char c) {
    if (st[last].next[c] && st[last].len + 1 == st[st[last].next[c]].len) {
      last = st[last].next[c];
      return;
    }
    int p = last;
    int np = last = ++sz;
    st[np].len = st[p].len + 1;
    for (; p && !st[p].next[c]; p = st[p].link) st[p].next[c] = np;
    if (p == 0) {
      st[np].link = 1;
    } else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len) {
        st[np].link = q;
      } else {
        int nq = ++sz;
        st[nq].next = st[q].next;
        st[nq].len = st[p].len + 1;
        st[nq].link = st[q].link;
        st[q].link = st[np].link = nq;
        for (; p && st[p].next[c] == q; p = st[p].link) st[p].next[c] = nq;
      }
    }
  }
  void Topo() {
    int os = 1;
    for (int i = os; i <= sz; i++) {
      ++a[st[i].len];
    }
    for (int i = os; i <= sz; i++) {
      a[i] += a[i - 1];
    }
    for (int i = os; i <= sz; i++) {
      b[a[st[i].len]--] = i;
    }
  }
  void solve() {
    int ans = 9999;
    for (int i = sz; i > 1; i--) {
      int e = b[i];
      if (endpos[0][e] == 1 && endpos[1][e] == 1) {
        ans = min(ans, st[st[e].link].len + 1);
      }
      endpos[0][st[e].link] += endpos[0][e];
      endpos[1][st[e].link] += endpos[1][e];
    }
    if (ans == 9999)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
} sam;
int main() {
  scanf(" %s", s);
  int len = strlen(s);
  sam.sa_init();
  for (int i = 0; i < len; i++) {
    sam.sa_extend(s[i]);
    sam.endpos[0][sam.last] = 1;
  }
  sam.last = 1;
  scanf(" %s", s);
  len = strlen(s);
  for (int i = 0; i < len; i++) {
    sam.sa_extend(s[i]);
    sam.endpos[1][sam.last] = 1;
  }
  sam.Topo();
  sam.solve();
  return 0;
}
