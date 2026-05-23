#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e14 + 9;
vector<long long> hash_valuen(5000009, 0);
vector<long long> hash_valuer(5000009, 0);
long long ans[5000009];
long long inv[5000009];
const long long p = 317;
const long long m = 104000717;
long long gcd(long long a, long long tri) {
  long long x = 1, y = 0, ini = tri;
  if (tri == 1) return 0;
  while (a > 1) {
    long long q = a / tri;
    long long t = tri;
    tri = a % tri;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += ini;
  return x;
}
void init() {
  inv[0] = gcd(p, m);
  for (int i = 1; i < 5000009; i++) {
    inv[i] = (inv[i - 1] * inv[0]) % m;
  }
}
void compute_hash(vector<long long>& hash_value, string const& s) {
  hash_value[0] = 0;
  long long p_pow = 1;
  int cont = 1;
  for (char c : s) {
    hash_value[cont] = (hash_value[cont - 1] + (c - '$' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
    cont++;
  }
}
void compute_hash2(vector<long long>& hash_value2, string const& s) {
  hash_value2[0] = 0;
  long long p_pow = 1;
  int cont = 1;
  for (char c : s) {
    hash_value2[cont] = (hash_value2[cont - 1] + (c - '$' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
    cont++;
  }
}
long long querie(long long l, long long r) {
  long long result = 0;
  result = (((hash_valuen[r] - hash_valuen[l - 1] + m) % m) * inv[l]) % m;
  return result;
}
long long querie2(long long l, long long r) {
  long long result = 0;
  result = (((hash_valuer[r] - hash_valuer[l - 1] + m) % m) * inv[l]) % m;
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long anstotal = 0;
  init();
  compute_hash(hash_valuen, s);
  reverse(begin(s), end(s));
  compute_hash2(hash_valuer, s);
  ans[1] = 1;
  long long n = (long long)(s).size();
  for (long long i = 2; i < ((long long)(s).size() + 1); ++i) {
    if (querie(1, i) == querie2(n - i + 1, n)) ans[i] = ans[i / 2] + 1;
  }
  for (long long i = 1; i < ((long long)(s).size() + 1); ++i)
    anstotal += ans[i];
  cout << anstotal << "\n";
  return 0;
}
