#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXLEN = 100000;
const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXTN = MAXLEN + 1;
const int MAXLG = 16;
const int MAXSN = 4 * (MAXN - 1);
const int MAXZN = 4 * MAXN;
typedef struct TN {
  int d;
  int nxt[26];
  int par[MAXLG + 1];
} TN;
typedef struct SN {
  int best;
  vector<int> preidx, sufidx;
} SN;
int n, nq;
char s[MAXLEN + 1];
TN tn[MAXTN];
int ntn, troot;
int tpos[MAXN];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qidx[MAXQ], qlen[MAXQ], qtpos[MAXQ];
int gettn(int par) {
  int ret = ntn++;
  tn[ret].d = par == -1 ? 0 : tn[par].d + 1;
  for (int i = (0); i < (26); ++i) tn[ret].nxt[i] = -1;
  tn[ret].par[0] = par == -1 ? ret : par;
  for (int i = (1); i <= (MAXLG); ++i)
    tn[ret].par[i] = tn[tn[ret].par[i - 1]].par[i - 1];
  return ret;
}
int tinsert() {
  int at = troot;
  for (int i = 0; s[i] != '\0'; ++i) {
    int x = s[i] - 'a';
    if (tn[at].nxt[x] == -1) tn[at].nxt[x] = gettn(at);
    at = tn[at].nxt[x];
  }
  return at;
}
int getlca(int a, int b) {
  if (tn[a].d < tn[b].d) swap(a, b);
  for (int k = MAXLG; k >= 0; --k)
    if (tn[a].d - (1 << k) >= tn[b].d) a = tn[a].par[k];
  for (int k = MAXLG; k >= 0; --k)
    if (tn[a].par[k] != tn[b].par[k]) a = tn[a].par[k], b = tn[b].par[k];
  return a == b ? a : tn[a].par[0];
}
int lcp[MAXN - 1];
SN sn[MAXSN];
void print(const SN &a) {
  printf("[");
  for (int i = (0); i < (((int)(a.preidx).size())); ++i) {
    if (i != 0) printf(",");
    printf("%d", a.preidx[i]);
  }
  printf("][");
  for (int i = (0); i < (((int)(a.sufidx).size())); ++i) {
    if (i != 0) printf(",");
    printf("%d", a.sufidx[i]);
  }
  printf("]->%d", a.best);
}
int calc(int l, int r, int mn) { return (r - l + 2) * mn; }
SN makesn(int idx) {
  SN ret;
  ret.best = calc(idx, idx, lcp[idx]);
  ret.preidx.push_back(idx);
  ret.sufidx.push_back(idx);
  return ret;
}
SN combine(const SN &a, const SN &b) {
  SN ret;
  ret.best = max(a.best, b.best);
  int ai = ((int)(a.sufidx).size()) - 1, bi = ((int)(b.preidx).size()) - 1;
  while (true) {
    if (lcp[a.sufidx[ai]] >= lcp[b.preidx[bi]]) {
      if (ai == 0) {
        for (int i = (0); i <= (bi); ++i) ret.preidx.push_back(b.preidx[i]);
        for (int i = (0); i < (((int)(a.preidx).size())); ++i)
          if (lcp[a.preidx[i]] == lcp[ret.preidx.back()])
            ret.preidx[((int)(ret.preidx).size()) - 1] = a.preidx[i];
          else
            ret.preidx.push_back(a.preidx[i]);
        ret.sufidx = b.sufidx;
        break;
      } else {
        int cur =
            calc(a.sufidx[ai - 1] + 1, b.preidx[bi] - 1, lcp[a.sufidx[ai]]);
        if (cur > ret.best) ret.best = cur;
        --ai;
      }
    } else {
      if (bi == 0) {
        ret.preidx = a.preidx;
        for (int i = (0); i <= (ai); ++i) ret.sufidx.push_back(a.sufidx[i]);
        for (int i = (0); i < (((int)(b.sufidx).size())); ++i)
          if (lcp[b.sufidx[i]] == lcp[ret.sufidx.back()])
            ret.sufidx[((int)(ret.sufidx).size()) - 1] = b.sufidx[i];
          else
            ret.sufidx.push_back(b.sufidx[i]);
        break;
      } else {
        int cur =
            calc(a.sufidx[ai] + 1, b.preidx[bi - 1] - 1, lcp[b.preidx[bi]]);
        if (cur > ret.best) ret.best = cur;
        --bi;
      }
    }
  }
  int l = ret.preidx.back(), r = ret.sufidx.back();
  ret.best = max(ret.best, calc(l, r, lcp[ret.preidx[0]]));
  for (int i = (1); i < (((int)(ret.preidx).size())); ++i)
    ret.best =
        max(ret.best, calc(l, ret.preidx[i - 1] - 1, lcp[ret.preidx[i]]));
  for (int i = (1); i < (((int)(ret.sufidx).size())); ++i)
    ret.best =
        max(ret.best, calc(ret.sufidx[i - 1] + 1, r, lcp[ret.sufidx[i]]));
  return ret;
}
void sinit(int x, int l, int r) {
  if (l == r) {
    sn[x] = makesn(l);
  } else {
    int m = l + (r - l) / 2;
    sinit(2 * x + 1, l, m);
    sinit(2 * x + 2, m + 1, r);
    sn[x] = combine(sn[2 * x + 1], sn[2 * x + 2]);
  }
}
void sset(int x, int l, int r, int IDX) {
  if (l == r) {
    sn[x] = makesn(l);
  } else {
    int m = l + (r - l) / 2;
    if (IDX <= m)
      sset(2 * x + 1, l, m, IDX);
    else
      sset(2 * x + 2, m + 1, r, IDX);
    sn[x] = combine(sn[2 * x + 1], sn[2 * x + 2]);
  }
}
SN sget(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return sn[x];
  int m = l + (r - l) / 2;
  if (R <= m) return sget(2 * x + 1, l, m, L, R);
  if (m + 1 <= L) return sget(2 * x + 2, m + 1, r, L, R);
  return combine(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
}
int len[MAXN];
int zn[MAXZN];
void zinit(int x, int l, int r) {
  if (l == r) {
    zn[x] = len[l];
  } else {
    int m = l + (r - l) / 2;
    zinit(2 * x + 1, l, m);
    zinit(2 * x + 2, m + 1, r);
    zn[x] = max(zn[2 * x + 1], zn[2 * x + 2]);
  }
}
void zset(int x, int l, int r, int IDX) {
  if (l == r) {
    zn[x] = len[l];
  } else {
    int m = l + (r - l) / 2;
    if (IDX <= m)
      zset(2 * x + 1, l, m, IDX);
    else
      zset(2 * x + 2, m + 1, r, IDX);
    zn[x] = max(zn[2 * x + 1], zn[2 * x + 2]);
  }
}
int zget(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) return zn[x];
  int m = l + (r - l) / 2;
  if (R <= m) return zget(2 * x + 1, l, m, L, R);
  if (m + 1 <= L) return zget(2 * x + 2, m + 1, r, L, R);
  return max(zget(2 * x + 1, l, m, L, R), zget(2 * x + 2, m + 1, r, L, R));
}
int ans[MAXQ];
void solve() {
  for (int i = (0); i < (n - 1); ++i)
    lcp[i] = tn[getlca(tpos[i], tpos[i + 1])].d;
  if (n >= 2) sinit(0, 0, n - 2);
  zinit(0, 0, n - 1);
  for (int i = (0); i < (nq); ++i) {
    if (qkind[i] == 1) {
      ans[i] = zget(0, 0, n - 1, ql[i], qr[i]);
      if (ql[i] != qr[i]) {
        SN cur = sget(0, 0, n - 2, ql[i], qr[i] - 1);
        if (cur.best > ans[i]) ans[i] = cur.best;
      }
    }
    if (qkind[i] == 2) {
      int idx = qidx[i];
      tpos[idx] = qtpos[i];
      len[idx] = qlen[i];
      zset(0, 0, n - 1, idx);
      if (idx >= 1) {
        lcp[idx - 1] = tn[getlca(tpos[idx - 1], tpos[idx])].d;
        sset(0, 0, n - 2, idx - 1);
      }
      if (idx + 1 < n) {
        lcp[idx] = tn[getlca(tpos[idx], tpos[idx + 1])].d;
        sset(0, 0, n - 2, idx);
      }
    }
  }
}
void run() {
  ntn = 0;
  troot = gettn(-1);
  scanf("%d%d", &n, &nq);
  for (int i = (0); i < (n); ++i) {
    scanf("%s", s);
    len[i] = strlen(s), tpos[i] = tinsert();
  }
  for (int i = (0); i < (nq); ++i) {
    scanf("%d", &qkind[i]);
    if (qkind[i] == 1) {
      scanf("%d%d", &ql[i], &qr[i]);
      --ql[i], --qr[i];
    }
    if (qkind[i] == 2) {
      scanf("%d%s", &qidx[i], s);
      --qidx[i], qlen[i] = strlen(s), qtpos[i] = tinsert();
    }
  }
  solve();
  for (int i = (0); i < (nq); ++i)
    if (qkind[i] == 1) printf("%d\n", ans[i]);
}
string ss[MAXN];
string os[MAXN];
string qs[MAXQ];
int chk[MAXQ];
int bflcp(const string &a, const string &b) {
  int ret = 0;
  while (ret < ((int)(a).size()) && ret < ((int)(b).size()) && a[ret] == b[ret])
    ++ret;
  return ret;
}
int bf(int l, int r) {
  int ret = 0;
  vector<pair<int, int> > stck;
  for (int i = (l); i <= (r); ++i) {
    ret = max(ret, ((int)(ss[i]).size()));
    if (i != l) {
      int lcp = bflcp(ss[i - 1], ss[i]);
      while (((int)(stck).size()) > 0 && lcp <= stck.back().first) {
        int cur = calc(((int)(stck).size()) == 1
                           ? l
                           : stck[((int)(stck).size()) - 2].second + 1,
                       i - 2, stck.back().first);
        if (cur > ret) ret = cur;
        stck.pop_back();
      }
      stck.push_back(make_pair(lcp, i - 1));
    }
  }
  while (((int)(stck).size()) > 0) {
    int cur = calc(((int)(stck).size()) == 1
                       ? l
                       : stck[((int)(stck).size()) - 2].second + 1,
                   r - 1, stck.back().first);
    if (cur > ret) ret = cur;
    stck.pop_back();
  }
  return ret;
}
void stress() {
  for (int rep = (0); rep < (10000); ++rep) {
    ntn = 0;
    troot = gettn(-1);
    n = 100;
    nq = 100;
    int slen = 5;
    for (int i = (0); i < (n); ++i) {
      for (int j = (0); j < (slen); ++j) s[j] = 'a' + rand() % 2;
      s[slen] = '\0';
      os[i] = ss[i] = string(s);
      len[i] = strlen(s), tpos[i] = tinsert();
    }
    for (int i = (0); i < (nq); ++i) {
      qkind[i] = 1 + rand() % 2;
      if (qkind[i] == 1) {
        ql[i] = rand() % n, qr[i] = rand() % n;
        if (ql[i] > qr[i]) swap(ql[i], qr[i]);
        chk[i] = bf(ql[i], qr[i]);
      }
      if (qkind[i] == 2) {
        qidx[i] = rand() % n;
        for (int j = (0); j < (slen); ++j) s[j] = 'a' + rand() % 2;
        s[slen] = '\0';
        qs[i] = ss[qidx[i]] = string(s);
        qlen[i] = strlen(s), qtpos[i] = tinsert();
      }
    }
    solve();
    bool ok = true;
    for (int i = (0); i < (nq); ++i)
      if (qkind[i] == 1 && chk[i] != ans[i]) {
        printf("it%d: err in q%d: expected %d but got %d\n", rep, i, chk[i],
               ans[i]);
        printf("%d %d\n", n, nq);
        for (int j = (0); j < (n); ++j) {
          if (j != 0) printf(" ");
          printf("%s", os[j].c_str());
        }
        puts("");
        for (int j = (0); j < (nq); ++j) {
          if (qkind[j] == 1) printf("1 %d %d\n", ql[j] + 1, qr[j] + 1);
          if (qkind[j] == 2) printf("2 %d %s\n", qidx[j] + 1, qs[j].c_str());
        }
        ok = false;
        break;
      }
    if (ok) printf(".");
  }
}
void stresstime() {
  ntn = 0;
  troot = gettn(-1);
  n = MAXN;
  nq = MAXQ;
  int slen = 1;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (slen); ++j) s[j] = 'a' + rand() % 2;
    s[slen] = '\0';
    len[i] = strlen(s), tpos[i] = tinsert();
  }
  for (int i = (0); i < (nq); ++i) {
    qkind[i] = 1;
    if (qkind[i] == 1) {
      ql[i] = rand() % n, qr[i] = rand() % n;
      if (ql[i] > qr[i]) swap(ql[i], qr[i]);
      chk[i] = bf(ql[i], qr[i]);
    }
    if (qkind[i] == 2) {
      qidx[i] = rand() % n;
      for (int j = (0); j < (slen); ++j) s[j] = 'a' + rand() % 2;
      s[slen] = '\0';
      qs[i] = ss[qidx[i]] = string(s);
      qlen[i] = strlen(s), qtpos[i] = tinsert();
    }
  }
  solve();
}
int main() {
  run();
  return 0;
}
