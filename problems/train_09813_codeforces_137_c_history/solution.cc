#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100;
pair<int, int> hap[MAXN];
int main() {
  int n, m = 0, index = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> hap[i].first >> hap[i].second;
  sort(hap, hap + n);
  m = hap[0].second;
  for (int i = 1; i < n; i++) {
    if (hap[i].second < m)
      ++index;
    else if (m < hap[i].second)
      m = hap[i].second;
  }
  cout << index;
  return 0;
}
