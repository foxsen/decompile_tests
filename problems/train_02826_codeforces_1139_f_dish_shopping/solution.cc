#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, s[800005], ans[200005];
struct ii {
  int l, r, lys, inc, pref, op;
} a[200005];
bool cmp(ii x, ii y) {
  if (x.op == 0 && y.op == 0) return x.r > y.r;
  if (x.op == 0 && y.op != 0) return x.r >= y.inc;
  if (x.op != 0 && y.op == 0) return x.inc > y.r;
  if (x.op != 0 && y.op != 0) return x.inc > y.inc;
}
struct query {
  int x, y, op;
};
vector<query> v;
vector<int> allx, ally;
void add(int x, int y) {
  int i;
  for (i = x; i; i -= (i & (-i))) s[i] += y;
}
int qry(int x) {
  int i, sss = 0;
  for (i = x; i <= 800000; i += (i & (-i))) sss += s[i];
  return sss;
}
void solve(const vector<query> &v, int l, int r) {
  if (v.empty()) return;
  if (l >= r) return;
  int mid = (l + r) / 2;
  vector<query> vl, vr;
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    if (it->x <= mid) {
      vl.push_back(*it);
      if (it->op == 0) add(it->y, 1);
    } else {
      vr.push_back(*it);
      if (it->op) ans[it->op] += qry(it->y);
    }
  }
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    if (it->x <= mid) {
      if (it->op == 0) add(it->y, -1);
    }
  }
  solve(vl, l, mid);
  solve(vr, mid + 1, r);
}
int main() {
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(a[i].l);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(a[i].r);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) read(a[i].lys);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) read(a[i + n].inc);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) read(a[i + n].pref);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) a[i + n].op = i;
  stable_sort(a + 1, a + n + m + 1, cmp);
  for (((i)) = (1); ((i)) <= ((n + m)); ((i))++) {
    if (a[i].op) {
      v.push_back((query){a[i].pref + a[i].inc + 1 + 1,
                          a[i].pref - a[i].inc + 1000000001, a[i].op});
    } else {
      v.push_back(
          (query){a[i].lys + a[i].l + 1, a[i].lys - a[i].l + 1000000001, 0});
    }
  }
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    allx.push_back(it->x);
    ally.push_back(it->y);
  }
  stable_sort((allx).begin(), (allx).end());
  allx.resize(unique((allx).begin(), (allx).end()) - allx.begin());
  stable_sort((ally).begin(), (ally).end());
  ally.resize(unique((ally).begin(), (ally).end()) - ally.begin());
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    it->x = upper_bound((allx).begin(), (allx).end(), it->x) - allx.begin();
    it->y = upper_bound((ally).begin(), (ally).end(), it->y) - ally.begin();
  }
  solve(v, 1, allx.size());
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) printf("%d ", ans[i]);
  return 0;
}
