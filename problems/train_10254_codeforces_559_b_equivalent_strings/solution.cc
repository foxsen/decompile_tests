#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 9;
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = power(x, y / 2);
  if (y % 2 == 1)
    return temp * temp * x;
  else
    return temp * temp;
}
bool check(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a == b) return true;
  return false;
}
string solve(string x) {
  int n = x.length();
  if (n % 2) return x;
  string a = solve(x.substr(0, n / 2));
  string b = solve(x.substr(n / 2, n));
  return a < b ? (a + b) : (b + a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  if (solve(a) == solve(b))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
