#include <bits/stdc++.h>
using namespace std;
long long mod = (1000000007LL);
inline long long Mod(long long a, long long b) { return (a % b); }
inline long long poww(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b, swap(a, b);
  }
  return a;
}
void read(vector<long long> &w, long long n) {
  w.resize(n);
  for (long long i = 0; i < n; i++) cin >> w[i];
}
void print(vector<long long> &w) {
  for (long long i = 0; i < (long long)(w).size(); i++) {
    if (i == (long long)(w).size() - 1)
      cout << w[i] << "\n";
    else
      cout << w[i] << " ";
  }
}
long long prodmod(vector<long long> w);
long long summod(vector<long long> w);
long long n;
long long cross(pair<long long, long long> A, pair<long long, long long> B,
                pair<long long, long long> O) {
  return (A.first - O.first) * (B.second - O.second) -
         (A.second - O.second) * (B.first - O.first);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back(pair<long long, long long>(x, y - x * x));
  }
  vector<pair<long long, long long> > upper;
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), v.end());
  for (long long i = 0; i < (long long)(v).size(); i++) {
    while ((long long)(upper).size() >= 2 and
           cross(upper[(long long)(upper).size() - 2], v[i], upper.back()) <= 0)
      upper.pop_back();
    upper.push_back(v[i]);
  }
  long long ans = 0;
  for (long long i = 0; i < (long long)(upper).size() - 1; i++)
    if (upper[i].first != upper[i + 1].first) ans++;
  cout << ans << "\n";
}
long long summod(vector<long long> w) {
  long long curr = 0;
  for (long long i = 0; i < (long long)(w).size(); i++) {
    curr = (curr + w[i]) % mod;
    if (curr < 0) curr += mod;
  }
  return curr;
}
long long prodmod(vector<long long> w) {
  long long curr = 1;
  for (long long i = 0; i < (long long)(w).size(); i++) {
    if (w[i] >= mod) w[i] %= mod;
    curr = (curr * w[i]) % mod;
    if (curr < 0) curr += mod;
  }
  return curr;
}
