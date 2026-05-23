#include <bits/stdc++.h>
using namespace std;
int n, a[20], len;
set<long long> s;
int used[20], que[20];
void calc(int l) {
  for (int i = len; i > l; --i) que[i] = que[len - i + 1];
  int tmp = 0;
  for (int i = 1; i <= 3; ++i) {
    if (i == 2 && que[1] == 0) break;
    tmp = tmp * 10 + que[i];
    if (tmp > 255) break;
    int tmp2 = 0;
    for (int j = i + 1; j <= i + 3 && j <= len; ++j) {
      if (j == i + 2 && que[i + 1] == 0) break;
      tmp2 = tmp2 * 10 + que[j];
      if (tmp2 > 255) break;
      int tmp3 = 0;
      for (int p = j + 1; p <= j + 3 && p <= len; ++p) {
        if (p == j + 2 && que[j + 1] == 0) break;
        tmp3 = tmp3 * 10 + que[p];
        if (tmp3 > 255) break;
        int tmp4 = 0;
        bool fl = 1;
        if (p == len || p + 3 < len) continue;
        for (int q = p + 1; q <= len; ++q) {
          if (q == p + 2 && que[p + 1] == 0) fl = 0;
          tmp4 = tmp4 * 10 + que[q];
          if (tmp4 > 255) fl = 0;
        }
        if (fl)
          s.insert((((long long)tmp * 256ll + tmp2) * 256ll + tmp3) * 256ll +
                   tmp4);
      }
    }
  }
}
void dfs(int p, int l) {
  if (p > l) {
    for (int i = 1; i <= n; ++i)
      if (!used[i]) return;
    calc(l);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    used[i]++;
    que[p] = a[i];
    dfs(p + 1, l);
    used[i]--;
  }
}
void solve(int l) {
  memset(used, 0, sizeof used);
  len = l;
  dfs(1, (l + 1) / 2);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 4; i <= 12; ++i) solve(i);
  cout << s.size() << endl;
  for (set<long long>::iterator it = s.begin(); it != s.end(); ++it) {
    long long num = *it;
    printf("%d.%d.%d.%d\n", (int)(num / 16777216), int(num / 65536 % 256),
           int(num / 256 % 256), int(num % 256));
  }
  return 0;
}
