#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const int mod = 1e9 + 7;
int pwr(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * 1LL * a) % mod;
    }
    a = (a * 1LL * a) % mod;
    b >>= 1;
  }
  return ans;
}
const int N = 1e7 + 5;
int smp[N], cnt[N];
bool pr[N];
int phi[N], lol[N];
int zz = 0;
signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  iota(phi + 1, phi + n + 1, 1);
  pr[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!pr[i]) {
      for (int j = i; j <= n; j += i) {
        if (!smp[j]) {
          lol[++zz] = i;
          smp[j] = i;
        }
        cnt[j]++;
        pr[j] = 1;
        phi[j] = (i - 1) * (phi[j] / i);
      }
      pr[i] = 0;
    }
  }
  reverse(lol + 1, lol + n);
  int pt = 1;
  long long one = 0, two = 0;
  for (int i = 2; i <= n; i++) {
    if (!pr[i] && i <= n / 2) {
      for (int j = i; j <= n; j += i) {
        if (smp[j] * 1LL * i <= n) two--;
      }
      while (pt < n && lol[pt] * 1LL * i > n) pt++;
      two += n - pt;
    }
  }
  int cp = 1;
  for (int i = 2; i <= n; i++) {
    if (pr[i]) {
      two += phi[i] - cp + cnt[i];
    }
    one += i - 1 - phi[i];
    if (!pr[i]) cp++;
  }
  long long c = 1;
  for (int i = n / 2 + 1; i <= n; i++) {
    if (!pr[i]) c++;
  }
  long long zero = c * (n - 1) - (c * (c - 1)) / 2;
  for (int i = 2; i <= n; i++) {
    if (cnt[i] == 2 && !pr[i / smp[i]]) two--;
  }
  long long three = (n * 1LL * (n - 1)) / 2 - zero - one - two;
  cout << three * 3 + two * 2 + one * 1;
  return 0;
}
