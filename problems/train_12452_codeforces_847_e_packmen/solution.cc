#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> p;
bool check(int x) {
  int ind = 0, i = 0;
  while (1) {
    while (ind < s.size() && s[ind] != '*') ind++;
    if (ind >= s.size()) return true;
    if (i >= p.size()) return false;
    if (ind < p[i]) {
      if (p[i] - ind > x) return false;
      int t = p[i] - ind;
      ind = max(ind, p[i] + 1 + max(0, x - 2 * (p[i] - ind)));
      ind = max(ind, p[i] + ((x - t) / 2) + 1);
    } else
      ind = max(p[i] + x + 1, ind);
    i++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 1e9, i;
  cin >> n >> s;
  int l = 0, r = 1e6;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == 'P') p.push_back(i);
  }
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  ans = min(ans, r);
  cout << ans;
}
