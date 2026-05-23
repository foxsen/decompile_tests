#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, mod, a[3] = {};
  string s;
  cin >> s;
  n = s.size();
  vector<char> v(n), temp, ans;
  for (int i = 0; i < n; i++) {
    v[i] = s[i];
    sum += (s[i] - '0'), a[(s[i] - '0') % 3]++;
  }
  mod = sum % 3;
  if (mod == 0) {
    int j;
    if (v[0] == '0' && v.size() > 1) {
      for (int i = 0; v[i] == '0' && i < v.size(); i++) j = i + 1;
    }
    v.erase(v.begin(), v.begin() + j);
    for (int i = 0; i < v.size(); i++) cout << v[i];
    return 0;
  }
  temp = v;
  if (a[mod] > 0) {
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
      if ((v[i] - '0') % 3 == mod) {
        v.erase(v.begin() + i);
        break;
      }
    int ok = 0;
    if (v[0] == '0' && v.size() > 0) {
      ok = 1;
      for (int i = 0; v[i] == '0' && i < v.size(); i++) j = i + 1;
    }
    v.erase(v.begin(), v.begin() + j);
    if (ok && v.size() == 0) v.push_back('0');
    ans = v;
  }
  v = temp;
  if (a[(2 * mod) % 3] > 1) {
    int j = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--)
      if ((v[i] - '0') % 3 == (2 * mod) % 3) {
        cnt++;
        v.erase(v.begin() + i);
        if (cnt == 2) break;
      }
    int ok = 0;
    if (v[0] == '0' && v.size() > 0) {
      ok = 1;
      for (int i = 0; v[i] == '0' && i < v.size(); i++) j = i + 1;
    }
    v.erase(v.begin(), v.begin() + j);
    if (ok && v.size() == 0) v.push_back('0');
    if (v.size() > ans.size()) ans = v;
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  if (ans.size() == 0) cout << -1;
  return 0;
}
