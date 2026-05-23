#include <bits/stdc++.h>
using namespace std;
const int cnst = -(1e9 + 7);
bool IsQuery = true, found;
long long int q = 1, cnt;
void solve() {
  long long int b, c, r, g, o, e, p, d, x, y, z, n,
      minm = cnst, maxm = cnst, k = 200, sum = 0, ans = 1, l = 0, flag = 0,
      sum1;
  string s, t, s1;
  set<string> set1;
  set<string>::iterator it;
  map<string, long long int> m, f;
  vector<long long int> a, v;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] < k) {
      k = s[i];
      v.clear();
    }
    if (k == s[i]) v.push_back(i + 1);
  }
  for (auto i : v) {
    string s2;
    s1 = s.substr(0, i - 1);
    t = s.substr(i - 1, n);
    if ((n - i + 1) % 2 == 1) reverse(s1.begin(), s1.end());
    t.append(s1);
    if (m[t] == 0) m[t] = i;
    set1.insert(t);
  }
  s1 = *set1.begin();
  for (it = set1.begin(); it != set1.end(); it++) {
    t = *it;
    for (int j = 0; j < n; j++) {
      if (t[j] < s1[j]) {
        s1 = t;
        break;
      } else if (t[j] > s1[j])
        break;
    }
  }
  cout << s1 << endl;
  cout << m[s1] << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (IsQuery) cin >> q;
  for (int i = 0; i < q; i++) solve();
  return 0;
}
