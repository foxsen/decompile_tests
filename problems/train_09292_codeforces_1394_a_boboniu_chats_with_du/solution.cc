#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
void fun() {
  int sum = 0;
  int x;
  while (cin >> x) sum += x;
  cout << "sum =  " << sum << endl;
}
void solve() {
  int n, d, m;
  scanf("%d%d%d", &n, &d, &m);
  d++;
  vector<long long> tmp, v, add;
  for (int i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    tmp.push_back(x);
  }
  sort(tmp.begin(), tmp.end());
  long long sum = tmp[n - 1];
  for (int i = 0; i < n - 1; ++i) {
    if (tmp[i] > m) {
      v.push_back(0);
      add.push_back(tmp[i]);
    } else
      v.push_back(tmp[i]);
  }
  sort(v.begin(), v.end());
  sort(add.begin(), add.end());
  reverse(add.begin(), add.end());
  int _add = add.size();
  int _v = v.size();
  int l = 0;
  for (int i = 0; i < _add; ++i) {
    if (l + d > _v) break;
    long long x = 0;
    for (int j = l; j < l + d; ++j) x += v[j];
    if (x < add[i]) {
      sum += add[i];
      l += d;
    } else
      break;
  }
  for (int i = l; i < _v; ++i) sum += v[i];
  printf("%lld\n", sum);
}
int main() {
  solve();
  return 0;
}
