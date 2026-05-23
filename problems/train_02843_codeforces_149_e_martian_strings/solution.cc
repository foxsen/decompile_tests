#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1010;
int L[N], R[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q, ans = 0;
  string s, sr;
  cin >> s;
  sr = s;
  reverse(sr.begin(), sr.end());
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    string a = t + '#' + s;
    reverse(t.begin(), t.end());
    string b = t + '#' + sr;
    for (int i = 1; i < a.size(); i++) {
      int j = L[i - 1];
      while (j && a[i] != a[j]) j = L[j - 1];
      if (a[i] == a[j]) j++;
      L[i] = j;
      j = R[i - 1];
      while (j && b[i] != b[j]) j = R[j - 1];
      if (b[i] == b[j]) j++;
      R[i] = j;
    }
    for (int i = t.size() + 1; i < a.size(); i++) {
      if (L[i] == t.size()) L[i] = 0;
      if (R[i] == t.size()) R[i] = 0;
      L[i] = max(L[i], L[i - 1]);
      R[i] = max(R[i], R[i - 1]);
    }
    for (int i = 1; i < s.size(); i++) {
      if (t.size() <= L[t.size() + i] + R[t.size() + s.size() - i]) {
        ans++;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
