#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x);
    }
    n >>= 1;
    if (n != 0) {
      x = (x * x);
    }
  }
  return res;
}
long long powerMOD(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % MOD;
    }
    n >>= 1;
    x = (x * x) % MOD;
  }
  return res;
}
bool mycompare(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}
bool mycompare1(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}
void solve() {
  long long i, j, k, n, m, l, x;
  cin >> n >> k;
  x = 0;
  l = 0;
  while (k) {
    if (k & 1) x += powerMOD(n, l);
    x %= MOD;
    k >>= 1;
    l++;
  }
  cout << x << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  int t = 1, i;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
