#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
void prin(long long int a, long long int b, long long int c,
          long long int maxi) {
  if (a == max(b, c))
    cout << "1 ";
  else if (a == maxi)
    cout << "0 ";
  else
    cout << max(b, c) - a + 1 << " ";
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second > b.second);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < (n); i++) cin >> a[i];
  int flag = 1;
  long long int egcd = a[0], ogcd = a[1];
  long long int omin = a[1], emin = a[1];
  for (long long int i = 0; i < (n); i++) {
    if (i % 2 == 0) {
      egcd = gcd(egcd, a[i]);
    } else
      ogcd = gcd(ogcd, a[i]);
  }
  int flag1 = 0;
  for (long long int i = 0; i < (n - 1); i++) {
    if (a[i] % egcd == 0 && a[i + 1] % egcd == 0) {
      flag1 = 1;
      break;
    }
  }
  int flag2 = 0;
  for (long long int i = 0; i < (n - 1); i++) {
    if (a[i] % ogcd == 0 && a[i + 1] % ogcd == 0) {
      flag2 = 1;
      break;
    }
  }
  if (flag1 == 0)
    cout << egcd << endl;
  else if (flag2 == 0)
    cout << ogcd << endl;
  else
    cout << 0 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, x;
  cin >> t;
  while (t--) {
    solve();
  }
}
