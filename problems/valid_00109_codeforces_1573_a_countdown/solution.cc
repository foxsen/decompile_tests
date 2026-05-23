#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void test_case() {
  long long n;
  string s;
  cin >> n >> s;
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    sum += (s[i] - '0');
    if (i < n - 1 && s[i] > '0') sum++;
  }
  cout << sum << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    test_case();
  }
}
