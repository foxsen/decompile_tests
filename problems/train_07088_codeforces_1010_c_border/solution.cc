#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long k;
  cin >> n >> k;
  long long ai;
  cin >> ai;
  long long g = ai;
  for (int i = 2; i <= n; i++) {
    cin >> ai;
    g = gcd(g, ai);
  }
  g %= k;
  set<int> s;
  for (int i = 0; i < k; i++) {
    s.insert((i * g) % k);
  }
  cout << s.size() << "\n";
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    cout << (*it) << " ";
  }
  cout << "\n";
  return 0;
}
