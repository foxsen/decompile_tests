#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node {
  string fi, se, ans;
  int id;
} x[1009];
int n;
map<string, int> cntfi, cntse, cnt;
bool cmp(node a, node b) { return cntfi[a.fi] > cntfi[b.fi]; }
bool cmp_cnt(node a, node b) { return cnt[a.fi] > cnt[b.fi]; }
bool cmp_id(node a, node b) { return a.id < b.id; }
int f(int k) {
  sort(x + k, x + n, cmp_cnt);
  if (!cnt[x[k].fi]) return k;
  for (; k < n; k++) {
    if (cnt[x[k].fi]) {
      if (cnt[x[k].se]) return -1;
      x[k].ans = x[k].se;
      cnt[x[k].ans] = 1;
    } else
      break;
  }
  return f(k);
}
bool solve() {
  int i = 0;
  for (; i < n; i++) {
    if (cntfi[x[i].fi] > 1) {
      if (cntse[x[i].se] == 1)
        return false;
      else
        x[i].ans = x[i].se, cntse[x[i].ans] = 1, cnt[x[i].ans] = 1;
    } else
      break;
  }
  i = f(i);
  if (i == -1) return false;
  for (; i < n; i++) x[i].ans = x[i].fi;
  return true;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      cin >> x[i].fi >> x[i].se;
      x[i].id = i;
      x[i].se = x[i].fi.substr(0, 2) + x[i].se[0];
      x[i].fi = x[i].fi.substr(0, 3);
      cntfi[x[i].fi]++;
    }
    sort(x, x + n, cmp);
    bool flag = solve();
    printf("%s\n", flag ? "YES" : "NO");
    if (flag) {
      sort(x, x + n, cmp_id);
      for (int i = 0; i < n; i++) cout << x[i].ans << endl;
    }
  }
  return 0;
}
