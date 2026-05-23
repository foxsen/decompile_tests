#include <bits/stdc++.h>
using namespace std;
int const N = 512312;
int const INF = 1e9 + 7;
int n, a[N], mn[35][N], gcd[35][N], numlog[N];
int gcd__(int a, int b) { return b ? gcd__(b, a % b) : a; }
void build1() {
  numlog[1] = 0;
  for (int c = 2; c <= n; c++) {
    numlog[c] = numlog[c / 2] + 1;
  }
  for (int c = 0; c <= numlog[n]; c++) {
    int len = 1 << c;
    for (int i = 1; i <= n; i++) {
      if (c == 0) {
        mn[c][i] = a[i];
      } else {
        mn[c][i] = min(mn[c - 1][i], mn[c - 1][i + len / 2]);
      }
    }
  }
}
void build2() {
  for (int c = 0; c <= numlog[n]; c++) {
    int len = 1 << c;
    for (int i = 1; i <= n; i++) {
      if (c == 0) {
        gcd[c][i] = a[i];
      } else {
        gcd[c][i] = gcd__(gcd[c - 1][i], gcd[c - 1][i + len / 2]);
      }
    }
  }
}
int get1(int l, int r) {
  if (r > n) r = n;
  if (l < 1) l = 1;
  int len = numlog[r - l + 1];
  return min(mn[len][l], mn[len][r - (1 << len) + 1]);
}
int get2(int l, int r) {
  if (r > n) r = n;
  if (l < 1) l = 1;
  int len = numlog[r - l + 1];
  return gcd__(gcd[len][l], gcd[len][r - (1 << len) + 1]);
}
bool ok(int len) {
  for (int c = 1; c <= n - len + 1; c++) {
    if (get1(c, c + len - 1) == get2(c, c + len - 1)) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int c = 1; c <= n; c++) {
    scanf("%d", &a[c]);
  }
  build1();
  build2();
  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  ans--;
  vector<int> res;
  for (int c = 1; c <= n - ans; c++) {
    if (get1(c, c + ans) == get2(c, c + ans)) res.push_back(c);
  }
  cout << res.size() << " " << ans << endl;
  for (int c = 0; c < res.size(); c++) {
    cout << res[c] << " ";
  }
  return 0;
}
