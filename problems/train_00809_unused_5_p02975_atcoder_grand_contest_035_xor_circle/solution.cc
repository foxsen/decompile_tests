#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int x = 0;
  vector<int> a(n);
  for (int& i : a) cin >> i, x ^= i;
  puts(x == 0 ? "Yes" : "No");
  return 0;
}
