#include <bits/stdc++.h>
using namespace std;
int d3(long long x) {
  int ret = 0;
  while (x % 3 == 0) {
    ret++;
    x /= 3;
  }
  return ret;
}
vector<pair<int, long long>> v;
int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second;
    v[i].first = -d3(v[i].second);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) cout << v[i].second << " ";
}
