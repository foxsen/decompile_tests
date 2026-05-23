#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
const int N = 1e5 + 7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
bool comp(long long a, long long b) { return (a > b); }
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long i, flag = 1, num, a, b;
  std::set<long long> holes;
  for (i = 0; i < m; i++) {
    cin >> num;
    holes.insert(num);
  }
  long long pos = 1;
  if (holes.find(1) != holes.end()) flag = 0;
  while (k--) {
    cin >> a >> b;
    if (pos == a && flag) {
      pos = b;
      if (holes.find(b) != holes.end()) flag = 0;
      continue;
    } else if (pos == b && flag) {
      pos = a;
      if (holes.find(a) != holes.end()) flag = 0;
      continue;
    }
  }
  cout << pos;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
