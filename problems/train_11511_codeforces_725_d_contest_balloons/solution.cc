#include <bits/stdc++.h>
using namespace std;
int n, ans, size, cnt;
long long x, y, z;
struct xj {
  long long t, w, p;
} hy[300009];
long long read() {
  long long x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x;
}
struct cmp1 {
  bool operator()(const int& x, const int& y) { return hy[x].p > hy[y].p; }
};
bool cmp(xj x, xj y) { return x.t > y.t; }
priority_queue<int, vector<int>, cmp1> dui;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    hy[i].t = read(), hy[i].w = read(), hy[i].p = hy[i].w - hy[i].t;
  sort(hy + 2, hy + n + 1, cmp);
  for (int i = 2; i <= n; ++i) {
    if (hy[i].t > hy[1].t)
      dui.push(i), size++;
    else
      break;
  }
  ans = cnt = size + 1;
  while (1) {
    if (!size) break;
    x = dui.top();
    if (hy[1].t < (hy[x].p + 1)) break;
    dui.pop();
    size--;
    hy[1].t -= (hy[x].p + 1);
    while (cnt < n && hy[cnt + 1].t > hy[1].t) {
      cnt++;
      dui.push(cnt);
      size++;
    }
    ans = min(ans, size + 1);
  }
  cout << ans;
  return 0;
}
