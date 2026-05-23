#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int ca[100005];
int cb[100005];
int ua, ub;
int n;
int f(int t) {
  int sa = 0, sb = 0;
  int p = 0;
  int pa, pb;
  while (1) {
    if (p + 2 * t - 1 >= n) {
      pa = ca[n] - ca[p];
      pb = cb[n] - cb[p];
      if (pa != t && pb != t) return -1;
      if (pa == t) {
        ++sa;
        if (sa > sb && a[ca[n]] == n)
          return sa;
        else
          return -1;
      } else {
        ++sb;
        if (sa < sb && b[cb[n]] == n)
          return sb;
        else
          return -1;
      }
    }
    pa = ca[p + 2 * t - 1] - ca[p];
    pb = cb[p + 2 * t - 1] - cb[p];
    if (pa > pb) {
      ++sa;
      p = a[ca[p] + t];
    } else {
      ++sb;
      p = b[cb[p] + t];
    }
  }
  return -2;
}
int cmp(long long a, long long b) {
  if ((int)a != (int)b) return (int)a < (int)b;
  return a < b;
}
int main() {
  int i;
  vector<long long> res;
  ua = ub = 1;
  a[0] = b[0] = 0;
  ca[0] = cb[0] = 0;
  int u;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> u;
    if (u == 1) {
      a[ua++] = i;
    } else {
      b[ub++] = i;
    }
    ca[i] = ua - 1;
    cb[i] = ub - 1;
  }
  int s;
  long long x;
  for (i = 1; i <= n; ++i) {
    s = f(i);
    if (s != -1) {
      x = ((long long)i << 32) | s;
      res.push_back(x);
    }
  }
  int len = res.size();
  cout << len << endl;
  sort(res.begin(), res.end(), cmp);
  for (i = 0; i < len; ++i) {
    cout << (int)res[i] << " " << (res[i] >> 32) << endl;
  }
  return 0;
}
