#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int n, a, b;
  vector<int> v;
  cin >> n;
  cin >> a;
  v.push_back(a);
  for (int i = 1; i < n; i++) {
    cin >> b;
    v.push_back(b);
    if (a < b) swap(a, b);
    a = gcd(a, b);
  }
  sort(v.begin(), v.end());
  if (*(lower_bound(v.begin(), v.end(), a)) == a)
    cout << a;
  else
    cout << -1;
  return 0;
}
