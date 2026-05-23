#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long inf = 3e18 + 5;
const double eps = 1e-8;
const double pi = acos(-1);
void test() {
  long long n, m;
  cin >> n >> m;
  set<pair<int, int> > s;
  for (int i = 0; i < (1001); i++) {
    if (i * i > n) break;
    for (int j = 0; j < (1001); j++) {
      if (j * j > m || i * i + j > n) break;
      if (i * i + j == n && (j * j) + i == m) s.insert({i, j});
    }
  }
  cout << s.size() << endl;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int cases = 1, c = 1;
  while (cases--) {
    test();
  }
}
