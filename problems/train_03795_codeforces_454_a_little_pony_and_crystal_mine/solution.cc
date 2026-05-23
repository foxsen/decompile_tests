#include <bits/stdc++.h>
using namespace std;
long long int INF = 1e18 + 5;
long long int power(long long int a, long long int n) {
  long long int res = 1;
  if (n & 1) {
    n--;
    res *= a;
  } else {
    n /= 2;
    a = a * a;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long int N = 1e6 + 5;
const long long int MOD = 1e9 + 7;
void solve() {
  list<string> ans;
  long long int n;
  cin >> n;
  string s(n, 'D');
  ans.push_back(s);
  long long int a = 0, b = n - 1;
  for (long long int i = 1; i <= n / 2; i++) {
    s[a] = '*';
    s[b] = '*';
    ans.push_back(s);
    ans.push_front(s);
    a++;
    b--;
  }
  for (auto it : ans) cout << it << "\n";
  return;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  for (long long int i = 1; i <= T; i++) solve();
}
