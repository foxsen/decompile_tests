#include <bits/stdc++.h>
using namespace std;
int n, d;
struct Node {
  int mx, ad;
} seg[200010 * 12];
pair<int, int> inp[200010];
map<int, int> dis;
int inv[200010 * 4];
int cn = 0;
int cmi = 0;
int lav = -1;
int cl = 0;
void assignV(int ed) {
  typeof(dis.begin()) it = dis.upper_bound(lav);
  for (; it != dis.end() && it->first <= ed; ++it) {
    inv[cn] = it->first;
    it->second = cn++;
  }
  lav = ed;
}
void s_add(int i, int l, int r, int st, int ed, int av) {
  if (ed <= st) return;
  if (st == l && ed == r) {
    seg[i].mx += av;
    seg[i].ad += av;
    return;
  }
  int m = (l + r) / 2;
  if (m <= st)
    s_add(i * 2 + 2, m, r, st, ed, av);
  else if (m >= ed)
    s_add(i * 2 + 1, l, m, st, ed, av);
  else {
    s_add(i * 2 + 1, l, m, st, m, av);
    s_add(i * 2 + 2, m, r, m, ed, av);
  }
  seg[i].mx = max(seg[2 * i + 1].mx, seg[2 * i + 2].mx) + seg[i].ad;
}
int s_getMinId(int i, int l, int r, int av, int cv) {
  if (seg[i].mx + av < cv) return r;
  if (l + 1 == r) return l;
  int m = (l + r) / 2;
  if (seg[2 * i + 1].mx + av + seg[i].ad >= cv)
    return s_getMinId(i * 2 + 1, l, m, av + seg[i].ad, cv);
  else
    return s_getMinId(i * 2 + 2, m, r, av + seg[i].ad, cv);
}
void lemon() {
  scanf("%d%d", &n, &d);
  for (int i = (0); i <= (n - 1); i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    if (t < 0)
      i--, n--;
    else {
      s = max(s, 0);
      inp[i] = pair<int, int>(t + 1, s);
      dis[s] = 0, dis[t + 1] = 0;
    }
  }
  sort(inp, inp + n);
  int maxd = n * 3 + 1;
  inv[maxd] = 1000000001;
  for (int i = (0); i <= (n - 1); i++) {
    int np = inv[s_getMinId(0, 0, maxd, 0, cmi + 1)];
    np += d;
    if (np < cl) np = cl;
    if (np <= inp[i].first) {
      cmi++;
      if (dis.find(np) == dis.end()) dis[np] = 0;
      assignV(np);
      s_add(0, 0, maxd, dis[np], maxd, 1);
      cl = np;
      i--;
    } else {
      assignV(inp[i].first);
      s_add(0, 0, maxd, dis[inp[i].second], dis[inp[i].first], 1);
      cl = inp[i].first;
    }
  }
  printf("%d\n", seg[0].mx);
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
