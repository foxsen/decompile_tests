#include <bits/stdc++.h>
using namespace std;
long long int inline ipow(long long int a, long long int b, long long int m) {
  long long int val = 1;
  a %= m;
  while (b) {
    if (b & 01) val = (val * a) % m;
    b >>= 1;
    a = (a * a) % m;
  };
  return val % m;
}
long long int inline ipow(long long int a, long long int b) {
  long long int val = 1;
  while (b) {
    if (b & 01) val = (val * a);
    b >>= 1;
    a = (a * a);
  };
  return val;
}
map<int, pair<char, int> > m;
void ans(int x, int y, char q) {
  map<int, pair<char, int> >::iterator it = m.lower_bound(x);
  if (it->first == x) {
    cout << 0 << endl;
    return;
  }
  if (q == 'L') it--;
  int ans1 = abs(it->first - x);
  if (it->second.first == q) ans1 += it->second.second;
  cout << ans1 << endl;
  m[x] = make_pair(q, ans1);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t tStart = clock();
  int n, x, y;
  char q;
  cin >> n;
  m[0] = make_pair('U', 0);
  m[n + 1] = make_pair('L', 0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> q;
    ans(x, y, q);
  }
  return 0;
}
