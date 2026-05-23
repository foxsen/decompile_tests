#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
struct robot {
  int c, f, l;
};
int d;
inline bool operator<(const robot &a, const robot &b) {
  if (a.l != b.l) return a.l < b.l;
  if (!a.l) return false;
  return a.f > b.f;
}
int sz, bad, ans1, ans2;
long long t[110000];
void take(int t1, int f1, int t2, int f2) {
  t1 += t2;
  t2 -= min(t2, bad);
  int n = sz - t2;
  int pos = int(upper_bound(t, t + n, f2) - t);
  t1 += pos;
  if (pos) f1 += (int)t[pos - 1];
  if (t1 > ans1 || t1 == ans1 && f1 < ans2) {
    ans1 = t1;
    ans2 = f1;
  }
}
int main() {
  int n, s;
  cin >> n >> d >> s;
  vector<robot> a, b;
  for (int i = 0; i < (int)(n); i++) {
    robot x;
    scanf("%d%d%d", &x.c, &x.f, &x.l);
    x.l = x.l >= d;
    if (x.c)
      a.push_back(x);
    else
      b.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sz = 0;
  long long sum = 0;
  for (int i = (int)(b.size()) - 1; i >= 0; i--)
    if (b[i].l) {
      sum += b[i].f;
      t[sz++] = sum;
    } else
      bad++;
  take(0, 0, 0, s);
  long long free = 0;
  for (int i = 0; i < (int)(a.size()); i++) free += a[i].c;
  free -= (int)a.size();
  sum = 0;
  for (int i = (int)(a.size()) - 1; i >= 0; i--)
    if (a[i].l && s >= a[i].f) {
      sum += a[i].f;
      s -= a[i].f;
      free++;
      take((int)a.size(), (int)sum, (int)min(free, (long long)b.size()), s);
    }
  cout << ans1 << ' ' << ans2 << endl;
  return 0;
}
