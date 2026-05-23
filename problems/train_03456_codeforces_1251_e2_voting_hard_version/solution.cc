#include <bits/stdc++.h>
using namespace std;
int n;
set<pair<int, int>> byp;
int p[200000];
int m[200000];
int sorted[200000];
bool cmp(int i, int j) {
  if (m[i] < m[j]) return true;
  if (m[i] > m[j]) return false;
  return p[i] > p[j];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    byp.clear();
    for (int i = 0; i < n; i++) {
      cin >> m[i] >> p[i];
      sorted[i] = i;
    }
    sort(sorted, sorted + n, cmp);
    int cnt = 0;
    long long cost = 0;
    for (int i = n - 1; i >= 0; i--) {
      int ind = sorted[i];
      byp.insert({p[ind], ind});
      if (i + cnt < m[ind]) {
        auto it = byp.begin();
        cnt++;
        cost += it->first;
        byp.erase(it);
      }
    }
    cout << cost << "\n";
  }
  return 0;
}
