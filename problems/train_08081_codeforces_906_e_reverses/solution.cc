#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
char mde[N];
char mde1[N >> 1];
char mde2[N >> 1];
struct nod {
  int v;
  int fr;
  friend bool operator<(nod a, nod b) {
    return (a.v == b.v) ? a.fr < b.fr : a.v < b.v;
  }
} dp[N], g[N];
struct data {
  int s;
  int d;
  int siz;
  inline int cmx() { return s + d * (siz - 1); }
} se[2][500];
int tp[2];
int al[N];
int ar[N];
int atp;
inline void ins1(data* b, int& hd, const int& s) {
  if (hd == 0) {
    b[++hd] = (data){s, 0x3f3f3f3f, 1};
  } else {
    int del = s - b[hd].cmx();
    if (del == b[hd].d)
      b[hd].siz++;
    else
      b[++hd] = (data){s, del, 1};
  }
}
inline void ins2(data* b, int& hd, const data& p) {
  if (b[hd].d == p.d)
    b[hd].siz += p.siz;
  else
    b[++hd] = p;
}
inline void trs(data* a, int tp, data* b, int& hd, const char& c) {
  hd = 0;
  for (int i = 1; i <= tp; i++)
    if (mde[a[i].s - 1] == c) {
      ins1(b, hd, a[i].s - 1);
      if (a[i].siz != 1)
        ins2(b, hd, (data){a[i].s + a[i].d - 1, a[i].d, a[i].siz - 1});
    }
}
int main() {
  scanf("%s", mde1 + 1);
  scanf("%s", mde2 + 1);
  for (n = 1; mde1[n + 1] != '\0'; n++)
    ;
  for (int i = 1; i <= n; i++) mde[i << 1] = mde1[i];
  for (int i = 1; i <= n; i++) mde[(i << 1) - 1] = mde2[i];
  n <<= 1;
  mde[0] = '#';
  for (int i = 1; i <= n; i++) g[i] = (nod){0x3f3f3f3f, 0};
  for (int i = 1; i <= n; i++) dp[i] = (nod){0x3f3f3f3f, 0};
  for (int i = 1, p = 1, q = 0; i <= n; i++, p ^= 1, q ^= 1) {
    trs(se[q], tp[q], se[p], tp[p], mde[i]);
    if (mde[i] == mde[i - 1]) ins1(se[p], tp[p], i - 1);
    if (i & 1) continue;
    if (mde[i] == mde[i - 1]) dp[i] = min(dp[i], (nod){dp[i - 2].v, i - 2});
    data* a = se[p];
    for (int j = 1; j <= tp[p]; j++) {
      nod ret = (nod){0x3f3f3f3f, 0};
      int ed = a[j].cmx() - 1;
      if (a[j].siz == 1) {
        ret = min((nod){dp[ed].v + 1, ed}, ret);
      } else {
        ret = min((nod){dp[ed].v + 1, ed}, g[a[j].s - a[j].d]);
      }
      if (a[j].s - a[j].d >= 0) g[a[j].s - a[j].d] = ret;
      dp[i] = min(dp[i], ret);
    }
  }
  if (dp[n].v == 0x3f3f3f3f) {
    printf("-1\n");
    return 0;
  }
  for (int p = n; p; p = dp[p].fr)
    if (dp[p].fr < p - 2) {
      al[++atp] = dp[p].fr + 1, ar[atp] = p;
    }
  printf("%d\n", atp);
  for (int i = 1; i <= atp; i++)
    printf("%d %d\n", (al[i] + 1) >> 1, (ar[i] + 1) >> 1);
  return 0;
}
