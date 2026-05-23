#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) {
  int cnt = 1;
  while (a != b) {
    if (a <= 0 || b <= 0) break;
    if (a > b) {
      cnt += (a - 1) / b;
      a -= ((a - 1) / b) * b;
    } else {
      cnt += (b - 1) / a;
      b -= ((b - 1) / a) * a;
    }
  }
  return a * b == 1 ? cnt : -1;
}
string g(int a, int b, int n, int &chg) {
  string ans1(n, 'T');
  string ans2(n, 'T');
  int pp = n - 1;
  while (a != b) {
    if (a > b) {
      for (int(i) = (int)(0); (i) < (int)((a - 1) / b); ++(i)) {
        ans1[pp - i] = 'T';
        ans2[pp - i] = 'B';
      }
      pp -= (a - 1) / b;
      a -= ((a - 1) / b) * b;
    } else {
      for (int(i) = (int)(0); (i) < (int)((b - 1) / a); ++(i)) {
        ans1[pp - i] = 'B';
        ans2[pp - i] = 'T';
      }
      pp -= (b - 1) / a;
      b -= ((b - 1) / a) * a;
    }
  }
  int cnt1 = 0, cnt2 = 0;
  for (int(i) = (int)(1); (i) < (int)(n); ++(i)) {
    if (ans1[i - 1] == ans1[i]) ++cnt1;
    if (ans2[i - 1] == ans2[i]) ++cnt2;
  }
  chg = min(cnt1, cnt2);
  return cnt1 <= cnt2 ? ans1 : ans2;
}
int main() {
  int n, r;
  cin >> n >> r;
  if (n == 1 && r == 1) {
    cout << "0" << endl;
    cout << "T" << endl;
    return 0;
  }
  string ans = "IMPOSSIBLE";
  int cmin = 987654321;
  for (int x = 1; x < r; ++x)
    if (f(r, x) == n) {
      int chg;
      string tmp = g(r, x, n, chg);
      if (chg < cmin) cmin = chg, ans = tmp;
    }
  if (cmin != 987654321) cout << cmin << endl;
  cout << ans << endl;
  return 0;
}
