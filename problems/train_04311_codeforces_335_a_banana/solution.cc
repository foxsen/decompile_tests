#include <bits/stdc++.h>
using namespace std;
string s;
int tedad[300];
bool possible(int t, int n) {
  int len = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    len += tedad[i] / t;
    if (tedad[i] % t != 0) len++;
  }
  return len <= n;
}
int bs(int first, int second, int n) {
  if (first == second) return first;
  int d = (first + second) / 2;
  if (d == 1 && possible(d, n)) return d;
  if (possible(d, n) && !possible(d - 1, n)) return d;
  if (!possible(d, n)) return bs(d + 1, second, n);
  return bs(first, d - 1, n);
}
int main() {
  int n;
  cin >> s >> n;
  for (int i = 0; i < 300; i++) tedad[i] = 0;
  int dif = 0, dif2 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (tedad[s[i]] == 0) dif++;
    tedad[s[i]]++;
  }
  if (n < dif) {
    cout << -1 << endl;
    return 0;
  }
  int ans = bs(1, 1005, n);
  string sans = "";
  for (int i = 'a'; i <= 'z'; i++) {
    int need = tedad[i] / ans;
    if (tedad[i] % ans != 0) need++;
    for (int j = 0; j < need; j++) sans += char(i);
  }
  cout << ans << endl;
  while (sans.length() < n) sans += 'a';
  cout << sans << endl;
  return 0;
}
