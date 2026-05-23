#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int cnt[N], nleaf[N], p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> p[i], p[i]--;
    nleaf[p[i]] = true;
  }
  for (int i = 0; i < n; ++i)
    if (!nleaf[i]) cnt[p[i]]++;
  bool ok = true;
  for (int i = 0; i < n; ++i) ok &= (!nleaf[i] || cnt[i] >= 3);
  cout << (ok ? "YES" : "NO") << endl;
}
