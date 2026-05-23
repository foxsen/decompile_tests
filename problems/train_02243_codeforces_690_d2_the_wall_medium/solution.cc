#include <bits/stdc++.h>
const double eps = 1e-10;
const float epsf = 1e-6;
using namespace std;
inline long long int __gcd(long long int a, long long int b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  }
  long long int tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
inline int compfloat(float& x, float& y) {
  if (fabs(x - y) < epsf)
    return 0;
  else if (x - y > 0)
    return 1;
  return -1;
}
inline int compdouble(double x, double y) {
  if (fabs(x - y) < eps)
    return 0;
  else if (x - y > 0)
    return 1;
  else
    return -1;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
void cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
}
long long int fact[700006];
long long int ifact[700006];
long long int mod = 1000003;
long long int C(int n, int m) {
  return (fact[n] * ((ifact[m] * ifact[n - m]) % mod)) % mod;
}
long long int power(long long int x, long long int y, long long int z) {
  long long int result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
void solve() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 700005; i++) fact[i] = (fact[i - 1] * i) % mod;
  ifact[700005] = modInverse(fact[700005], mod) % mod;
  for (int i = 700004; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
  int n, c;
  cin >> n >> c;
  cout << C(n + c, c) - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
