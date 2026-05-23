#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
using namespace std;
long long mul(long long a, long long b, long long m = 1000000007) {
  long long res = 0;
  a = a % m;
  while (b > 0) {
    if (b % 2 == 1) res = (res + a) % m;
    a = (a * 2) % m;
    b /= 2;
  }
  return res % m;
}
long long expMod(long long a, long long b, long long m = 1000000007) {
  long long x = 1, y = a;
  while (b) {
    if (b % 2 == 1) {
      x = mul(x, y, m);
    }
    y = mul(y, y, m);
    b = b / 2;
  }
  return x;
}
bool getBit(long long n, long long i) { return (n >> i) & 1; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long N, M, k, x;
  cin >> N >> M >> k;
  vector<long long> a, b;
  for (long long i = 0; i < N; ++i) {
    cin >> x;
    a.push_back(x);
  }
  for (long long i = 0; i < M; ++i) {
    cin >> x;
    b.push_back(x);
  }
  unordered_map<long long, long long> ta, tb;
  long long cnt = 0;
  for (long long i = 0; i < N; ++i) {
    if (a[i] == 0) {
      if (cnt != 0) {
        for (long long j = 1; j <= cnt; ++j) ta[j] += cnt - j + 1;
      }
      cnt = 0;
    }
    if (a[i] == 1) cnt++;
  }
  if (cnt != 0) {
    for (long long j = 1; j <= cnt; ++j) ta[j] += cnt - j + 1;
  }
  cnt = 0;
  for (long long i = 0; i < M; ++i) {
    if (b[i] == 0) {
      if (cnt != 0) {
        for (long long j = 1; j <= cnt; ++j) tb[j] += cnt - j + 1;
      }
      cnt = 0;
    }
    if (b[i] == 1) cnt++;
  }
  if (cnt != 0) {
    for (long long j = 1; j <= cnt; ++j) tb[j] += cnt - j + 1;
  }
  cnt = 0;
  long long ans = 0;
  for (auto i : ta) {
    if (k % (i.first) == 0) {
      if (tb.find(k / (i.first)) != tb.end()) {
        ans += i.second * tb[k / (i.first)];
      }
    }
  }
  cout << ans << "\n";
}
