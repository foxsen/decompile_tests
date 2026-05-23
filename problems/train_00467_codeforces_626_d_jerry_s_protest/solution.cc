#include <bits/stdc++.h>
using namespace std;
long long t[2222];
long long p1[5555];
long long p2[20000];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> t[i];
  }
  sort(t, t + n);
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      p1[t[j] - t[i]]++;
    }
  }
  for (long long i = 0; i < 5555; ++i) {
    for (long long j = 0; j < 5555; ++j) {
      p2[i + j] += p1[i] * p1[j];
    }
  }
  long double ans = 0;
  long double q = 0;
  for (int i = 1; i < 5555; ++i) {
    q += p2[i - 1];
    ans += p1[i] * q;
  }
  ans /= (long double)n * (n - 1) * n * (n - 1) * n * (n - 1) / 8;
  cout << fixed << setprecision(15) << ans << '\n';
}
