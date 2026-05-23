#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
bool pal(string s) {
  long long j = s.size() - 1;
  long long sw = 0;
  for (long long i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[j]) {
      sw = 1;
      break;
    }
    j--;
  }
  if (sw)
    return false;
  else
    return true;
}
set<long long> se;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie();
  long long a, b, c, d, n, t, m, k;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    v.push_back(0);
    set<long long> se;
    long long sw = 0;
    for (int i = 0; i < n; i++) {
      long long h = ((((i + v[i]) % n) + n) % n);
      se.insert(h);
    }
    if (se.size() == n)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
