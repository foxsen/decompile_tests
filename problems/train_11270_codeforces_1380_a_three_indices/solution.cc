#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n), pref(n), suf(n), id_p(n), id_s(n);
  for (int& i : v) cin >> i;
  for (int(i) = 0; (i) < (n); ++(i)) {
    if (!i) {
      pref[i] = v[i];
      id_p[i] = 0;
    } else if (v[i] < pref[i - 1]) {
      pref[i] = v[i];
      id_p[i] = i;
    } else {
      pref[i] = pref[i - 1];
      id_p[i] = id_p[i - 1];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      suf[i] = v[i];
      id_s[i] = n - 1;
    } else if (v[i] < suf[i + 1]) {
      suf[i] = v[i];
      id_s[i] = i;
    } else {
      suf[i] = suf[i + 1];
      id_s[i] = id_s[i + 1];
    }
  }
  for (int j = 1; j < n - 1; ++j) {
    if (pref[j - 1] < v[j] && v[j] > suf[j + 1]) {
      cout << "YES\n";
      cout << id_p[j - 1] + 1 << " " << j + 1 << " " << id_s[j + 1] + 1 << "\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
