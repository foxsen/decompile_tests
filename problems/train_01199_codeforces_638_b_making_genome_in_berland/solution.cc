#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
int n;
bool a[26][26];
bool was[26];
void dfs(int x) {
  cout << char(97 + x);
  for (int to = 0; to < 26; ++to) {
    if (a[x][to]) {
      dfs(to);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    for (int j = 0; j < t.size(); ++j) {
      was[t[j] - 'a'] = true;
    }
    for (int j = 1; j < t.size(); ++j) {
      a[t[j - 1] - 'a'][t[j] - 'a'] = true;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (!was[i]) continue;
    bool ok = true;
    for (int j = 0; j < 26; ++j) {
      if (a[j][i] == true) ok = false;
    }
    if (ok) {
      dfs(i);
    }
  }
  return 0;
}
