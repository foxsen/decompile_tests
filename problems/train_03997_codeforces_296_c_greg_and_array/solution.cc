#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<unsigned long long> a(n);
  vector<long long> l(m + 1);
  vector<int> r(m + 1);
  vector<unsigned long long> p(m + 1);
  unordered_map<long long, long long> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> p[i];
  }
  int x, y;
  vector<unsigned long long> count(m + 1, 0);
  vector<unsigned long long> frero(n + 1, 0);
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    count[x - 1]++;
    count[y]--;
  }
  for (int i = 0; i < m; i++) {
    if (i) count[i] += count[i - 1];
    p[i] *= count[i];
    frero[l[i] - 1] += p[i];
    frero[r[i]] -= p[i];
  }
  for (int i = 0; i < n; i++) {
    if (i) frero[i] += frero[i - 1];
    a[i] += frero[i];
    cout << a[i] << " ";
  }
}
