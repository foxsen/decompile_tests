#include <bits/stdc++.h>
using namespace std;
const int M = 4000 + 10;
int a[M];
int b[M];
int main() {
  int n;
  cin >> n;
  int nn = 2 * n;
  int p1 = 0;
  int p2 = 0;
  int cnt0 = 0;
  for (int i = 0; i < nn; i++) {
    string s;
    cin >> s;
    int sz = s.length();
    int idx = 0;
    while (idx < sz && s[idx] != '.') {
      idx++;
    }
    int num = 0;
    for (int j = idx + 1; j <= idx + 3; j++) {
      num = num * 10 + s[j] - '0';
    }
    a[i] = num;
    num = 0;
    for (int j = 0; j < idx; j++) {
      num = num * 10 + s[j] - '0';
    }
    b[i] = num;
    p1 = p1 + a[i];
    p2 = p2 + b[i];
    if (a[i] == 0) {
      cnt0++;
    }
  }
  int ans = -1;
  for (int i = 0; i <= n; i++) {
    int v = i * 1000;
    if (i <= nn - cnt0 && n - i <= cnt0) {
      if (ans == -1) {
        ans = abs(p1 - v);
      } else {
        ans = min(ans, abs(p1 - v));
      }
    }
  }
  int qu = ans / 1000;
  int res = ans % 1000;
  cout << qu << ".";
  if (res >= 100) {
    cout << res << endl;
  } else {
    if (res >= 10) {
      cout << 0 << res << endl;
    } else {
      if (res >= 1) {
        cout << "00" << res << endl;
      } else {
        cout << "000" << endl;
      }
    }
  }
  return 0;
};
