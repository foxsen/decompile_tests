#include <bits/stdc++.h>
using namespace std;
long long n, m, v1, v2, v, l, r, k2, color, j, mm, c, k1, f;
string s[1007], s1, s2, x;
char res[1007];
long long a[1007];
char z;
long long str(string q, string w) {
  if (a[w.size()] == 1) return 0;
  for (long long i = 0; i < w.size(); i++) {
    if (q[i] != w[i]) return 0;
  }
  return 1;
}
long long can(string ss) {
  long long kkk = 0;
  long long zzz = 0;
  for (j = 1; j <= 2 * n - 2; j++) {
    if (str(ss, s[j])) {
      res[j] = 'P';
      kkk++;
      a[s[j].size()] = 1;
    } else
      res[j] = 'S', zzz++;
  }
  if (kkk == zzz) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n * 2 - 2; i++) {
    cin >> s[i];
    if (s[i].size() == n - 1 && f == 0) {
      s1 = s[i];
      f = 1;
    } else if (s[i].size() == n - 1) {
      s2 = s[i];
      f = 1;
    }
  }
  x = s1;
  x += s2[n - 2];
  f = 0;
  for (long long i = 0; i < s2.size(); i++) {
    if (s2[i] != x[i + 1]) {
      f = 1;
      break;
    }
  }
  if (f == 0)
    if (can(x)) {
      for (long long i = 1; i <= 2 * n - 2; i++) cout << res[i];
      cout << "\n";
      return 0;
    }
  for (long long i = 1; i <= 2 * n - 2; i++) {
    res[i] = '#';
    a[i] = 0;
  }
  x = s2 + s1[n - 2];
  if (can(x)) {
    for (long long i = 1; i <= 2 * n - 2; i++) cout << res[i];
    cout << "\n";
  }
  return 0;
}
